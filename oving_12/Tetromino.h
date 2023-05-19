#pragma once
#include "Point.h"
#include <vector>
#include "Color.h"



enum class TetrominoType{NONE = 0, J=1, L=2, T=3, S=4, Z=5, O=6, I=7};

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
    void moveDown(int size = blockSize) { topLeftCorner.y += size; }
    void moveLeft(int size = blockSize) { topLeftCorner.x -= size; }
    void moveRight(int size = blockSize) { topLeftCorner.x += size; }

    bool blockExist(int row, int col);

    TetrominoType getBlock(int row, int col);
    int getMatrixSize() const { return matrixSize; }
    TDT4102::Point getPosition() const {return topLeftCorner; }
    static TDT4102::Color getColor(TetrominoType tetType);


   
private:
    TDT4102::Color color;
    int matrixSize;
    TDT4102::Point topLeftCorner;
    std::vector<std::vector<TetrominoType>> blockMatrix;
};  