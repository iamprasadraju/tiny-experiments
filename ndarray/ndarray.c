#include <stdio.h>
#include <stdlib.h>
// #include <malloc/malloc.h>


// name mapping(alias) for better convention
typedef _Float16 float16;
typedef float float32;
typedef double float64;

typedef enum {
  DTYPE_FLOAT16, // 0
  DTYPE_FLOAT32, // 1
  DTYPE_FLOAT64, // 2
} DType;

typedef struct {
  size_t *data;
  size_t len;
} NDTuple;

typedef union{
  float16 f16;
  float32 f32;
  float64 f64;
} NDFloat;

typedef struct {
  DType dtype;
  NDFloat value;
} NDScaler; 

// macro
#define NDtuple(...) (NDTuple){ \
  .data = (size_t[]){__VA_ARGS__}, \
  .len = sizeof((size_t[]){__VA_ARGS__}) / sizeof(size_t) \
}

typedef struct {
  void *data;
  NDTuple shape;
  NDTuple stride;
  size_t size;
  int ndim;
  DType dtype;
} NDArray; // creating alias as NDArray


NDArray ndarray_create(DType dtype, NDTuple shape){
  NDArray arr;
  arr.ndim = shape.len;
  arr.dtype = dtype;

  // allocated on heap
  // Lifetime Danger - (arr.shape) = shape (shallow copy)
  // This ensures the NDArray struct permanently owns its shape data.
  arr.shape.len = shape.len;
  arr.shape.data = malloc(arr.ndim * sizeof(size_t)); // deep copy

  if (arr.shape.data == NULL){
    arr.data = NULL;
    return arr;
  }
    
  size_t element_size = sizeof(double);
  switch (dtype) {
    case DTYPE_FLOAT16: element_size = sizeof(float16); break;
    case DTYPE_FLOAT32: element_size = sizeof(float32); break;
    case DTYPE_FLOAT64: element_size = sizeof(float64); break;
  }

  // total elements in ndarray (*arr.shape)
  size_t total_elements = 1;
  for (int i = 0; i < arr.ndim; i++) {
    arr.shape.data[i] = shape.data[i];
    total_elements *= arr.shape.data[i];
    
  }
  arr.size = total_elements;

  arr.data = malloc(element_size * total_elements);

  // for allocation failure
  if (arr.data == NULL){
    free(arr.shape.data);
    arr.shape.data = NULL;
  }
    
  // stride calculation

  arr.stride.len = arr.ndim;
  arr.stride.data = malloc(arr.ndim * sizeof(size_t));

  size_t stride = element_size;
  for(int i = arr.ndim - 1; i >= 0; i--){
    arr.stride.data[i] = stride;
    stride *= arr.shape.data[i];
  }
  
  // print strides

  /* 
  for(int i = 0; i < arr.stride.len; i++){
    printf("%zu ", arr.stride.data[i]);
  }
  */
  
  return arr;
}


// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Indexing (Pointer Arithmetic)
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void *get_index_ptr_address(NDArray arr, NDTuple index){
  size_t offset = 0;

  for(size_t i = 0; i < arr.stride.len; i++){
    offset += arr.stride.data[i] * index.data[i];  
  }

  // printf("%p", (char *)(arr.data) + offset); 
  // typecast to char for pointer arthimetic by compiler since data in void type
  return (char *)arr.data + offset; 
}

NDScaler ndarray_index_get(NDArray arr, NDTuple index){
  NDScaler scalar = { .dtype = arr.dtype };
  if(arr.ndim != index.len){ return scalar;} // dimension check

  // individual index co-ordinate check 
  for(size_t i = 0; i < arr.ndim; i++){
    if(index.data[i] > arr.shape.data[i]){
      fprintf(stderr, "Error: Index %zu is outside bounds for dimension %zu (Size: %zu).\n", 
                    index.data[i], i, arr.shape.data[i]);
    return scalar;
    }
  }
    void *ptr = get_index_ptr_address(arr, index);

    switch (arr.dtype) { 
        case DTYPE_FLOAT16:
           scalar.value.f16 = *(float16 *)ptr;
           break;
        case DTYPE_FLOAT32:
            scalar.value.f32 = *(float32 *)ptr;
        case DTYPE_FLOAT64:
            scalar.value.f64 = *(float64 *)ptr;
    }

    return scalar;
    }


// ndarray_index_set(NDArray arr, size_t value, size_t *index){

int main(){
  NDTuple shape = NDtuple(3, 4);
  
  NDArray myarr = ndarray_create(DTYPE_FLOAT64, shape);
  
  // malloc_size() func to get size of malloc memory block
  // printf("%lu", malloc_size(myarr.data)); 

  for(int i = 0; i < shape.data[0]; i++){
      for(int j = 0; j < shape.data[1]; j++){
          NDScaler value = ndarray_index_get(myarr, NDtuple(i, j));
          printf("%f", value.value.f64);
      }
  }
  
  
  
  free(myarr.data);
  free(myarr.shape.data);
  return 0;
}
