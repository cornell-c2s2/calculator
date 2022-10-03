//========================================================================
// Matrix.h
//========================================================================
// Declarations for calculator matrix object.

#ifndef Matrix_H
#define Matrix_H


typedef struct {
    int ncols;
    int nrows;
} Matrix;

// constructor and deconstructor 
void matrixConstruct();
void matrixDestruct();

// methods
Matrix inverse();

#endif