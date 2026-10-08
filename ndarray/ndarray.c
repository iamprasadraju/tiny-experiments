#include <stdio.h>
#include <stdlib.h>

typedef _Float16 float16;
typedef float float32;
typedef double float64;

typedef enum {
  DTYPE_FLOAT16, // 0
  DTYPE_FLOAT32, // 1
  DTYPE_FLOAT64, // 2
} DType;

typedef struct {
  void *data;
  size_t *shape;
  int ndim;
  DType dtype;
} NDArray; // creating alias as NDArray


NDArray create_ndarray(DType dtype, int ndim, size_t *shape){
  NDArray arr;
  arr.ndim = ndim;
  arr.dtype = dtype;


  // allocated on heap
  // Lifetime Danger - (arr.shape) = shape (shallow copy)
  // This ensures the NDArray struct permanently owns its shape data.
  arr.shape = malloc(ndim * sizeof(size_t)); // deep copy

    
  size_t element_size = sizeof(double);
  switch (dtype) {
    case DTYPE_FLOAT16: element_size = sizeof(float16); break;
    case DTYPE_FLOAT32: element_size = sizeof(float32); break;
    case DTYPE_FLOAT64: element_size = sizeof(float64); break;
  }
  
  size_t total_elements = 1;
  for (int i = 0; i < ndim; i++) {
    arr.shape[i] = shape[i];
    total_elements *= arr.shape[i];
    
  }

  arr.data = malloc(element_size * total_elements);

  // TODO: indexing

  return arr;
}




int main(){ 
  size_t shape[2] = {4, 2}; // on stack
  NDArray myarr = create_ndarray(DTYPE_FLOAT64, 2, shape);

  free(myarr.data);
  free(myarr.shape);
  return 0;
}
