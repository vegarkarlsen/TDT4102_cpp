#pragma once
#include <iostream>
// #include <iomanip>

class MatrixFast{
    private:
        unsigned int row;
        unsigned int col;

        double *data;

    public:
        // new M x N zero matrix
        MatrixFast(unsigned int r, unsigned int c);
        // N x N matrix
        explicit MatrixFast(unsigned int r);

        // copy constructor (same dimetion)
        MatrixFast(const MatrixFast &copyObject);

        ~MatrixFast();

        // manipulate matrix
        double get(unsigned int r, unsigned int c) const ;
        void set(unsigned int r, unsigned int c, double value);
        
        // operator overloading
        friend std::ostream &operator<<(std::ostream &os, const MatrixFast &m);
        // cant do this with one dimentioal array, use get() insted
        double *operator[](unsigned int i);

        MatrixFast &operator=(MatrixFast temperaryCopyObject);


        






};