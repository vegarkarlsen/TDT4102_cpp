#include "TetrisWindow.h"
#include <iostream>
#include "logger.hpp"
#include "std_lib_facilities.h"
#include <iostream>

void TetrisWindow::run() {
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while(!should_close()) { 
        framesSinceLastTetronimoMove++;
        if(framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            /********************************************************/
            //Kall moveTetrominoDown() her
            moveTetrominoDown();
            /********************************************************/
        }
        handleInput();
        
        /********************************************************/
        //Kall draw-funksjonene her
        drawMap();
        drawTetromino(currentTetromino);
        currentTetromino.printBlockMatrix();
        
        /********************************************************/
        next_frame();
    }
}
TetrisWindow::TetrisWindow() 
: TDT4102::AnimationWindow(xWin,yWin,winWidth, winHeight, winName)
{
    updateMapParameters();
    generateRandomTetromino();

}

void TetrisWindow::updateMapParameters(){
    
    // look at having fized cellsize
    map.cellSize = height()/cellDownScale;
    map.cellSize = Tetromino::blockSize;

    map.origo.x = width()/2 - ((rows * map.cellSize)/2);
    map.origo.y = height()/2 - ((col * map.cellSize)/2);

    map.width = width() - (map.origo.x * 2);
    map.height = height() - (map.origo.y * 2);

    // DEBUG(
    //     "[Updating map params] origo: (" << map.origo.x << ", " << map.origo.y << ")"
    //     << " width: " << map.width
    //     << " height: " << map.height
    //     << " cellSize: " << map.cellSize
    //     );

}

void TetrisWindow::drawMap(){
    // update before draw
    updateMapParameters();
    // draw background color
    draw_rectangle({-1,-1}, map.width*10, map.height*10, backgroundColor, TDT4102::Color::black);
    
    // draw grid map
    // DEBUG("-------------------------");
    for (int x = map.origo.x; x < map.origo.x + (rows * map.cellSize); x += map.cellSize){
        for (int y = map.origo.y; y < map.origo.y + (col * map.cellSize); y += map.cellSize){
            // DEBUG("drawing on " << x << ", " << y);
            draw_rectangle({x,y}, map.cellSize, map.cellSize, backgroundColor, TDT4102::Color::black);
        }
    }
    
    // DEBUG("--------------------------");
}

void TetrisWindow::drawTetromino(Tetromino tet){

    TetrominoType currentCell;
    TDT4102::Point currentPos; 

    for (int x = 0; x < tet.getMatrixSize(); x++){
        for (int y = 0; y < tet.getMatrixSize(); y++){
            currentCell = tet.getBlock(y,x);
            if (currentCell != TetrominoType::NONE){
                currentPos = {
                    tet.getPosition().x + (x*map.cellSize),
                    tet.getPosition().y + (y*map.cellSize)
                };
                draw_rectangle(
                    currentPos, 
                    map.cellSize, 
                    map.cellSize, 
                    tet.getColor(currentCell), 
                    TDT4102::Color::black
                );
            }        
        }
    }
}

void TetrisWindow::generateRandomTetromino(){
    int randomTetrominoInt = randint(1, 7);
    TetrominoType randomTetrominoType = static_cast<TetrominoType>(randomTetrominoInt);
    TDT4102::Point startTermino {
        map.origo.x + (map.cellSize * 3),
        map.origo.y - (map.cellSize * 4)
        };

    Tetromino newTetoromino {startTermino, randomTetrominoType};
    DEBUG("new terminao genreated, pos: " << startTermino.x << ", " << startTermino.y << " type: " << randomTetrominoInt);
    currentTetromino = newTetoromino;

}

// TODO: implement this
bool TetrisWindow::validLeftMove(){
    int size = currentTetromino.getMatrixSize();

    bool validMove = true;

    for (int x = 0; x < size; x++){
        for (int y = 0; y < size; y++){
            if (currentTetromino.blockExist(x,y)){
                DEBUG("checking block :" << x << ", " << y);
                if (currentTetromino.getPosition().x + (x * map.cellSize) < map.origo.x){
                    validMove = false;
                    DEBUG("block False");
                }
                // TODO: check static blocks
            }

        }
    }
    return validMove;
}

// TODO: implement this
bool TetrisWindow::validRightMove(){
    int size = currentTetromino.getMatrixSize();

    bool validMove = true;

    for (int x = 0; x < size; x++){
        for (int y = 0; y < size; y++){
            if (currentTetromino.blockExist(x,y)){
                DEBUG("checking block :" << x << ", " << y);
                if (currentTetromino.getPosition().x + (x * map.cellSize) > map.origo.x + (map.cellSize * (rows + 1))){
                    validMove = false;
                    DEBUG("block False");
                }
                // TODO: check static blocks
            }

        }
    }
    return validMove;
}

bool TetrisWindow::validDownMove(){
    
    int size = currentTetromino.getMatrixSize();
    int lowestRow;
    bool found = false;
    for (int x = size - 1; x >= 0; x--){
        for (int y = 0; y < size; y++){
            // DEBUG("checking x: " << x << " y: " << y);
            if (currentTetromino.blockExist(y,x)){
                lowestRow = x;
                // DEBUG("found block on row: " << x);
                found = true;
                break;
            }
        }
        if (found){
            break;
        }
    }
    // check outside map:
    if (currentTetromino.getPosition().y + (map.cellSize * (lowestRow + 2)) > (map.origo.y + (col * map.cellSize))){
        return false;
    }
    return true;

    // TODO: check gridMatrix
}

void TetrisWindow::moveTetrominoDown(){
    if (validDownMove()){
        currentTetromino.moveDown(map.cellSize);
        // generateRandomTetromino();
    }
}

void TetrisWindow::handleInput() {

    static bool lastZKeyState = false;
    static bool lastUpKeyState = false;
    static bool lastLeftKeyState = false;
    static bool lastRightKeyState = false;
    static bool lastDownKeyState = false;

    bool currentZKeyState = is_key_down(KeyboardKey::Z);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);
    bool currentLeftKeyState = is_key_down(KeyboardKey::LEFT);
    bool currentRightKeyState = is_key_down(KeyboardKey::RIGHT);
    bool currentDownKeyState = is_key_down(KeyboardKey::DOWN);

    
    // z
    if(currentZKeyState && !lastZKeyState) {
        currentTetromino.rotateClockwise();
    }
    // up
    if(currentUpKeyState && !lastUpKeyState) {
        currentTetromino.rotateCounterClockwise();
    }
    // left
    if (currentLeftKeyState && !lastLeftKeyState){
        // check if you go outside map:
        if (validLeftMove()){
            currentTetromino.moveLeft();
        }
    }
    //right
    if (currentRightKeyState && !lastRightKeyState){
        if (validRightMove()){
            currentTetromino.moveRight();
        }
    }
    // down
    if (currentDownKeyState && !lastDownKeyState){
        while (validDownMove()){
            moveTetrominoDown();
        }
    }

    lastZKeyState = currentZKeyState;
    lastUpKeyState = currentUpKeyState;
    lastLeftKeyState = currentLeftKeyState;
    lastRightKeyState = currentRightKeyState;
    lastDownKeyState = currentDownKeyState;
}


