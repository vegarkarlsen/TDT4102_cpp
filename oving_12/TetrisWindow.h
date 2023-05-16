#pragma once
#include "AnimationWindow.h"
#include "Tetromino.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include <string>

// window parameters
constexpr int xWin {800};
constexpr int yWin  {150};
constexpr int winWidth {500};
constexpr int winHeight {650};
const std::string winName {"Tetris"};


class TetrisWindow : public TDT4102::AnimationWindow {
public:
    
    TetrisWindow();
    void run();
    


private:
    const TDT4102::Color backgroundColor = TDT4102::Color::light_grey;
    const int cellSize = Tetromino::blockSize;
    const int mapWidth = winWidth - (cellSize * 2);
    const int mapHeight = winHeight - (cellSize * 2);
    const int mapX = 0;
    const int mapY = 0;

    const int nRows = mapWidth/cellSize;
    const int nCol = mapHeight/cellSize;

    TDT4102::Point startTetromino {mapX + (cellSize * nRows)/2, mapY};

    std::vector<std::vector<TetrominoType>> gridMatrix;
    Tetromino currentTetromino;

    Tetromino randomTetromino();
    void drawBoard();


    void handleInput();

};