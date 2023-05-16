#include "TetrisWindow.h"
#include <iostream>
#include "logger.hpp"
#include "std_lib_facilities.h"

void TetrisWindow::run() {
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while(!should_close()) { 
        framesSinceLastTetronimoMove++;
        if(framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            /********************************************************/
            //Kall moveTetrominoDown() her
            
            /********************************************************/
        }
        handleInput();
        
        /********************************************************/
        //Kall draw-funksjonene her
        /********************************************************/
        drawBoard();
        next_frame();
    }
}
TetrisWindow::TetrisWindow() 
: TDT4102::AnimationWindow(xWin,yWin,winWidth, winHeight, winName)
{
    std::vector<TetrominoType> stdRow;
    
    // int nRows = mapWidth/cellSize;
    // int nCol = mapHeight/cellSize;
    DEBUG("[Creating Window] rows: " << nRows << " columns " << nCol);

    // NONE row
    stdRow.insert(stdRow.begin(), nRows, TetrominoType::NONE);
    for (int col= 0; col < nCol; col++){
        // add row
        gridMatrix.push_back(stdRow);
    }

    currentTetromino = randomTetromino();

}

Tetromino TetrisWindow::randomTetromino(){
    int ranTetroInt = randint(1, static_cast<int>(TetrominoType::I));
    // TDT4102::Point startPoint {mapX + (cellSize * nRows)/2, mapY};
    Tetromino randomTetromino {startTetromino, static_cast<TetrominoType>(ranTetroInt)};
    return randomTetromino;
}


void TetrisWindow::drawBoard(){
    int cellSize = Tetromino::blockSize;
    TDT4102::Point boardTopLeft = {cellSize * 2, cellSize};
    int boardWidth = winWidth - (boardTopLeft.x + cellSize);
    int boardHeight = winHeight - (cellSize * 2);
    draw_rectangle(boardTopLeft, boardWidth, boardHeight, TDT4102::Color::white, TDT4102::Color::black);
}


void TetrisWindow::handleInput() {

    static bool lastZKeyState = false;
    static bool lastUpKeyState = false;

    bool currentZKeyState = is_key_down(KeyboardKey::Z);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);

    
    if(currentZKeyState && !lastZKeyState) {
        std::cout << "Hello from z\n";
    }

    if(currentUpKeyState && !lastUpKeyState) {
        std::cout << "Hello from up\n";
    }


    lastZKeyState = currentZKeyState;
    lastUpKeyState = currentUpKeyState;
}


