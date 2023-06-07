# A Linear algebra library for connect vec.h and mat.h

## The example code
```C
#define LAL_IMPL
#include "lal.h"

int main(){
    Mat mat = mat_alloc(2, 2);
    mat_put(mat, (double[]){2,0,0,1}, 4);

    printf("%lld %lld\n", mat.row, mat.col);

    Vec pos = vec_alloc(2);
    vec_put(pos, (double[]){1, 1}, 2);
    
    printf("Transformation matrix:\n");
    mat_print(mat); 
    printf("\n");

    printf("Posizion vector:\n");
    vec_print(pos);
    printf("\n");

    printf("Transformed position:\n");
    vec_print(lal_vec_transform(pos, mat));
    printf("\n");
    return 0;
}
```

## Compile and run
```console
make
./main.exe
```

# Rederences
my [Vec](https://github.com/domonkosgyomorey/Vec/) library.

my [Mat](https://github.com/domonkosgyomorey/Mat/) library.
