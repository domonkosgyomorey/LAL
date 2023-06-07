# A Linear algebra library for connect vec.h and mat.h

## The example code
```C
#define LAL_IMPL
#include "lal.h"

int main(){
    Mat mat = mat_alloc(2, 2);
    mat_put(mat, (double[]){2,0,0,1}, 4);

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

    Vec vecs[] = {
        pos,
        pos,
        pos,
        pos,
    };
    Vec* result = lal_vecs_transform(vecs, 4, mat);
    for(ll i = 0; i < 4; i++){
        vec_print(result[i]);
    }
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
