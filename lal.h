#ifndef LAL_H
#define LAL_H

#define MAT_IMPL
#include "mat.h"
#define VEC_IMPL
#include "vec.h"

Mat lal_vec2vert_mat(Vec vec);
Mat lal_vec2horz_mat(Vec vec);
Vec lal_mat2vec_by_vert(Mat mat, ll col);
Vec lal_mat2vec_by_horz(Mat mat, ll row);
Vec lal_transform(Vec vec, Mat transformation);

#ifdef LAL_IMPL

Mat lal_vec2vert_mat(Vec vec){
    Mat result = mat_alloc(vec.dim, 1); 
    for(ll i = 0; i < vec.dim; i++){
        MAT_AT(result, i, 0) = vec.data[i];
    }
    return result;
}

Mat lal_vec2horz_mat(Vec vec){
    Mat result = mat_alloc(1, vec.dim); 
    for(ll i = 0; i < vec.dim; i++){
        MAT_AT(result, 0, i) = vec.data[i];
    }
    return result;
}

Vec lal_mat2vec_by_vert(Mat mat, ll col){
    MAT_ASSERT(mat.col>col && "The matrix doesnt have that much col");
    Vec result = vec_alloc(mat.row);
    for(ll i = 0; i < mat.row; i++){
        result.data[i] = MAT_AT(mat, i, col);
    }
    return result;
}

Vec lal_mat2vec_by_horz(Mat mat, ll row){
    MAT_ASSERT(mat.row>row && "The matrix doesnt have that much row");
    Vec result = vec_alloc(mat.col);
    for(ll i = 0; i < mat.col; i++){
        result.data[i] = MAT_AT(mat, row, i);
    }
    return result;
}

Vec lal_vec_transform(Vec vec, Mat transformation){
    MAT_ASSERT(vec.dim==transformation.row && "Cannot perform this transformation over that vector");
    Mat coord = lal_vec2vert_mat(vec);
    Mat transformed = mat_mul(transformation, coord);
    return lal_mat2vec_by_vert(transformed, 0);
}

#endif // LAL_IMPL

#endif // LAL_H
