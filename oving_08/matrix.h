#pragma once

#include <cassert>
#include <iostream>

class Matrix{
    private:

        const int nR;
        const int nC;

        double **matrix;
        void assertInputRnC(int row, int col);

    public:
        // create a M x N matrix
        Matrix(int nRows, int nColumns);
        // explicit constructor (create I matrix)
        explicit Matrix(int nRows);
        // destructor delete all dynmaic memory
        ~Matrix();

        double get(int row, int col) const;
        void set(int row, int col, double value);
        
        // FIXME: bug when trying to acsess value beyond matrix
        double *operator[](int index);

        // output object
        friend std::ostream& operator<<(std::ostream &os, const Matrix &m);
        
        int getRows() const;
        int getColumns() const;

        Matrix(const Matrix &oldObject);

        Matrix &operator=(Matrix tempCopy);

        Matrix &operator+=(const Matrix &sumMatrix);

        // pass by value bacuase we dont want to alter the other matrixes
        Matrix &operator+(const Matrix sumMatrix);
};  