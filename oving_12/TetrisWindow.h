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

//fixed row and columns size
constexpr int rows = 10;
constexpr int col = 20;
constexpr int cellDownScale = 20; 

struct Map{
    int cellSize;
    TDT4102::Point origo;
    int width;
    int height;
};

class TetrisWindow : public TDT4102::AnimationWindow {
public:
    
    TDT4102::Color backgroundColor = TDT4102::Color::light_grey;
    
    TetrisWindow();
    void run();
    
private:
    Map map;

    std::vector<std::vector<TetrominoType>> gridMatrix;
    Tetromino currentTetromino;

    // update map
    void updateMapParameters();
    void drawMap();


    // updates this->currentTetromino
    void generateRandomTetromino();
    void drawTetromino(Tetromino tet);

    bool validLeftMove();
    bool validRightMove();
    bool validDownMove();

    void moveTetrominoDown();



    void handleInput();

};