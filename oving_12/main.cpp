#include "Tetromino.h"
#include "TetrisWindow.h"
#include "logger.hpp"

#include <cassert>


int main()
{
	/********************************************************/
		//Opprett vindu her
    TetrisWindow win;
    /********************************************************/
        //kall run på det her
    win.run();

    // Tetromino t {{0,0}, TetrominoType::T};
    // t.printBlockMatrix();

    // for (int x = 0; x < 3; x++){
    //     for (int y = 0; y < 3; y++){
    //         DEBUG(static_cast<int>(t.getBlock(x,y)));
            
    //     }

    // }


    


    return 0;

}
