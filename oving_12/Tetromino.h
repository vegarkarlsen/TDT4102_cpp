#pragma once
#include "Point.h"
#include <vector>
#include "Color.h"



enum class TetrominoType{NONE, J, L, T, S, Z, O, I};

class Tetromino {
public:
    static constexpr int blockSize {30};

    explicit Tetromino() : matrixSize(0), topLeftCorner({0,0})
    {}

    Tetromino(TDT4102::Point startingPoint, TetrominoType tetType);
    
    void rotateClockwise();
    void rotateCounterClockwise();

    void printBlockMatrix();

    // move
    void moveDown() { topLeftCorner.y += blockSize; }
    void moveLeft() { topLeftCorner.x -= blockSize; }
    void moveRight() { topLeftCorner.x += blockSize; }

    bool blockExist(int row, int col);

    TetrominoType getBlock(int row, int col);
    int getMatrixSize() const { return matrixSize; }
    TDT4102::Point getPosition() const {return topLeftCorner; }


   
private:
    TDT4102::Color color;
    int matrixSize;
    TDT4102::Point topLeftCorner;
    std::vector<std::vector<TetrominoType>> blockMatrix;
};  