#include "matrix.h"



void Matrix::assertInputRnC(int row, int col){
    assert(row > 0);
    assert(col > 0);
}


Matrix::Matrix(int nRows, int nColumns): nR{nRows}, nC{nColumns}{
    // exit program if we have negative rows or columns
    assertInputRnC(nR, nC);

    // pointers pointers list
    matrix = new double* [nR];
    
    // for each row in matrix asign nC column values as 0
    for (int r = 0; r < nR; r++){
        matrix[r] = new double[nC];
        for (int c = 0; c < nC; c++){
            matrix[r][c] = 0;
        }
    }

}

Matrix::Matrix(int nRows) : Matrix{nRows, nRows}{
    
    // make I matrix:
     for (int r = 0; r < nR; r++){
        for (int c = 0; c < nC; c++){
            if (r == c){
            matrix[r][c] = 1;
            }
        }
    }
} 


Matrix::~Matrix(){

    // delete all 
    for (int r = 0; r < nR; r++){
        delete[] matrix[r];
        matrix[r] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
}


double Matrix::get(int row, int col) const {
    return matrix[row][col];
}

void Matrix::set(int row, int col, double value){
    matrix[row][col] = value;
}

double *Matrix::operator[](int index){
    return matrix[index];
}

int Matrix::getRows() const { return nR; }

int Matrix::getColumns() const { return nC; }

std::ostream& operator<<(std::ostream &os, const Matrix &m){
    
    os << "[";
    for (int r = 0; r < m.nR; r++){
        os << "[";
        for (int c = 0; c < m.nC; c++){
            os << m.matrix[r][c];
            if (c < (m.nC - 1)){
                os << ", ";
            }
        }
        os << "]";
        if (r < (m.nR - 1)){
            os << "\n";
        }
    } 
    os << "]" << "\n";
    return os;
}




Matrix::Matrix(const Matrix &oldObject) : Matrix{oldObject.nR, oldObject.nC}{
    for (int r = 0; r < oldObject.nR; r++){
        for (int c = 0; c < oldObject.nC; c++){
            this->matrix[r][c] = oldObject.matrix[r][c];
        }
    }
    // **this->matrix = **oldObject.matrix;
}

// FIXME: does not work if shape is not the same
Matrix &Matrix::operator=(Matrix tempCopy){
    // need to be same shape (need to handle memory leak to fix this)
    assert(tempCopy.nR == this->nR && tempCopy.nC == this->nC);

    std::swap(this->matrix, tempCopy.matrix);

    return *this;
}


Matrix &Matrix::operator+=(const Matrix &sumMatrix){
    // need to be same shape
    assert(sumMatrix.nR == this->nR && sumMatrix.nC == this->nC);

    for (int r = 0; r < nR; r++){
        for (int c = 0; c < nC; c++){
            this->matrix[r][c] += sumMatrix.matrix[r][c];

        }
    }
    return *this;
}

Matrix &Matrix::operator+(Matrix sumMatrix){

    sumMatrix += *this;
    
    return sumMatrix;
}


