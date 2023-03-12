#include "matrix_fast.h"


MatrixFast::MatrixFast(unsigned int r, unsigned int c): row{r}, col{c}{
    
    data = new double[r*c];
    for (unsigned int i = 0; i < (r*c); i++){
        data[i] = i +1;
    }
}

MatrixFast::MatrixFast(unsigned int r) : MatrixFast{r,r} {

}

MatrixFast::MatrixFast(const MatrixFast &copyObject) : MatrixFast{copyObject.row, copyObject.col}{

    *this->data = *copyObject.data; 
}


MatrixFast::~MatrixFast(){
    delete[] data;
    data = nullptr;
}

double MatrixFast::get(unsigned int r, unsigned int c) const {
    return data[r*row + c];

}

void MatrixFast::set(unsigned int r, unsigned int c, double value){
    data[r*row+c] = value;

}





// overload <<
std::ostream& operator<<(std::ostream &os, const MatrixFast &m){

    int rowIndex = 0;
    for (unsigned int i = 0; i < m.row * m.col; i++){

        if(rowIndex >= m.row){
            rowIndex = 0;
            os << "\n";
        }
        os << m.data[i] << ", ";
    
        rowIndex++;
        
    }
    os << "\n";
    return os;
}

// overload =
MatrixFast &MatrixFast::operator=(MatrixFast temperaryCopyObject){

    // same size on data
    if (temperaryCopyObject.row == this->row && temperaryCopyObject.col == this->col){
        std::swap(this->data, temperaryCopyObject.data);

    }

    // if not same size or shape we need to realocate size
    else{
        // delete data
        delete[] this->data;
        // assign new data with right size
        this->data = new double[temperaryCopyObject.row * temperaryCopyObject.col];

        // swap data, and make sure we update shape identifiers
        std::swap(this->data, temperaryCopyObject.data);
        this->row = temperaryCopyObject.row;
        this->col = temperaryCopyObject.col;
    }

    return *this;

}




