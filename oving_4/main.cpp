
#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
// opgpave 1
// -------------------------------------------

/* 
1 a
v0 = startvalue + (increment * iteerations)
   = 5 + (2 * 10) = 25
*/ 

// -------------------------------------------


const string menuString = 
"Menu \n "
"0) exits\n "
"1) testCallByValue \n "
"2) testCallByReferance \n "
"3) testSwapNumbers \n"
;

void testPage(int choose, bool& active){
        
        switch (choose){
        case 0:
            cout << "Goodbye!" << endl;
            active = 0;
            break;

        case 1:
            testCallByValue();
            break;
        
        case 2:
            testCallByReferance();
            break;

        case 3:
            testSwapNumbers();
            break;

        default:
            cout << "Invalid choice" << endl;
    }  
}


void testMenu(){
    int choose;
    
    
    bool active = 1;
    while (active){
        
        cout << menuString << endl;
        cout << "Action: " ;
        cin >> choose;
        
        cout << "----------------------------------" << endl;
        testPage(choose, active);
        cout << "----------------------------------" << endl;
    }
}





int main(){

    // testMenu();

    testStudent();

    return 0;

}