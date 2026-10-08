#include <stdio.h>

typedef _Float16 float16;
typedef float float32;
typedef double float64;

typedef enum {
  DTYPE_FLOAT16,
  DTYPE_FLOAT32,
  DTYPE_FLOAT64,
} DType;

typedef struct NDArray{
  void *data;
  size_t *shape;
  int ndim;
  DType dtype;
} NDArray; // creating alias as NDArray


NDArray create_ndarray(DType dtype, int ndim, size_t *shape){
  NDArray arr;
  arr.ndim = ndim;
  arr.dtype = dtype;

  return arr;
}

int main(){
  return 0;
}
