
#include <cassert>

class Matrix{
    private:
        int nR;
        int nC;

        double *rows;
        double *coulmns;
        


    public:
        // identety matrix constructor
        explicit Matrix(int nRows);
        // secound constructor
        Matrix(int nRows, int nColumns);
        // destructor
        ~Matrix();


};