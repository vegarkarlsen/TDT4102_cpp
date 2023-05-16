#include "Tetromino.h"
#include <map>
#include <logger.hpp>
#include <iostream>
#include <cassert>
#include "Color.h"


const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap {

    {
    TetrominoType::J,
        {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 1}
        }
    },
    {
    TetrominoType::L,
        {
        {0, 0, 0},
        {1, 1, 1},
        {1, 0, 0}
        }
    },
    {
    TetrominoType::T,
        {
        {0, 0, 0},
        {1, 1, 1},
        {0, 1, 0}
        }
    },
    {
    TetrominoType::S,
        {
        {0, 0, 0},
        {0, 1, 1},
        {1, 1, 0}
        }
    },
    {
    TetrominoType::Z,
        {
        {0, 0, 0},
        {1, 1, 0},
        {0, 1, 1}
        }
    },
    {
    TetrominoType::O,
        {
        {1, 1},
        {1, 1}
        }
    },
    {
    TetrominoType::L,
        {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0}
        }
    }
};

std::map<TetrominoType, TDT4102::Color> tetrominoTypeToColorMap{
    {TetrominoType::NONE, TDT4102::Color::white},
    {TetrominoType::J, TDT4102::Color::dark_blue},
    {TetrominoType::L, TDT4102::Color::orange},
    {TetrominoType::T, TDT4102::Color::purple},
    {TetrominoType::S, TDT4102::Color::light_green},
    {TetrominoType::Z, TDT4102::Color::red},
    {TetrominoType::O, TDT4102::Color::yellow},
    {TetrominoType::I, TDT4102::Color::light_blue},
};


Tetromino::Tetromino(TDT4102::Point startingPoint, TetrominoType tetType) : 
topLeftCorner(startingPoint), color(tetrominoTypeToColorMap.at(tetType))
{
    // given full rank on matrixes i.e N x N
    matrixSize = static_cast<int>(initialMatrixMap.at(tetType).size());
    DEBUG("new matrix, Size: " << matrixSize << " type: "<< static_cast<int>(tetType));

    // std right dim row
    std::vector<TetrominoType> stdRow;
    stdRow.insert(stdRow.begin(), matrixSize, TetrominoType::NONE);

    for (int row = 0; row < matrixSize; row ++){

        // add right dim row and loop thorugh and change value as needed
        blockMatrix.push_back(stdRow);
        for (int col = 0; col < matrixSize; col++){
            // value is 1
            if (initialMatrixMap.at(tetType).at(row).at(col) > 0){
                blockMatrix.at(row).at(col) = tetType;
            }
        }
    }
}
void Tetromino::printBlockMatrix(){
    for (auto r : blockMatrix){
        for (int i = 0; i < matrixSize; i++){
            std::cout << static_cast<int>(r.at(i)) << " ";
        }
        std::cout << std::endl;
    }
        std::cout << std::endl;
}


bool Tetromino::blockExist(int row, int col){
    // check index out of range
    assert(row > matrixSize);
    assert(col > matrixSize);

    return blockMatrix.at(row).at(col) != TetrominoType::NONE;
}

TetrominoType Tetromino::getBlock(int row, int col){
    // check index out of range
    assert(row > matrixSize);
    assert(col > matrixSize);
    return blockMatrix.at(row).at(col);
}


// |-----------------------------------------------------------------------|

void Tetromino::rotateCounterClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    //Andre rotasjon, med hensyn på den midtre raden
    for(int row = 0; row < matrixSize/2; row++){
        for(int column = 0; column < matrixSize; column++){
            std::swap(blockMatrix[row][column], blockMatrix[matrixSize-row-1][column]);
            
        }
    }
}

void Tetromino::rotateClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }
     
    //Andre rotasjon, med hensyn på den midtre kolonnen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < matrixSize/2; column++){
            std::swap(blockMatrix[row][column], blockMatrix[row][matrixSize-column-1]);
        }
    }
}

