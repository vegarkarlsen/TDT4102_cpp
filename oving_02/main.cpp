
// include libraies
#include "std_lib_facilities.h"
#include "AnimationWindow.h"


//------------------------------------------------------------------------------'


// 1 b)
void inputAndPrintInteger(){
    int Integer;
    cout << "Skriv inn et tall: ";
    cin >> Integer;
    cout << "Du skrev: " << Integer << endl;
}

// 1 c)
int inputInteger(){
    int Integer;
    cout << "Skriv inn et tall: ";
    cin >> Integer;
    return Integer;

}

// 1 d)
void inputIntegersAndPrintSum(){
    int a = inputInteger();
    int b = inputInteger();
    cout << "Summen av " << a << " og " << b << " er: " << a + b << endl;
    
}

// 1 e)
// Jeg valgte å bruke inputInteger fordi den retunerer verdien.

// 1 f)
bool isOdd(int x){
    if (x % 2 == 0) {
        return false;
    } else {
        return true;
    }
}

// 1 g)
void printHumanReadableTime(int seconds){
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    seconds = (seconds % 3600) % 60;
    cout << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl;
}

// ------------------------------------------------------------

// 2 a)
void readKnowNumbersAndDoSum(){
    int n;
    cout << "Hvor mange tall oonsker du aa sumere? ";
    cin >> n;

    int sum = 0;
    int currentNumber;
    for (int i = 0; i < n; i++){
        cout << "number: ";
        cin >> currentNumber;
        sum += currentNumber;
    }
    cout << "------------------" << endl;
    cout << "sum: " << sum << endl;
}

// 2 b)
void readUnknownNumbersAndDoSum(){
    int input = -1;
    int sum = 0;

    bool active = 1;

    cout << "Skriv inn tall som skal summeres (0 = exit): " << endl;

    while (active){
        cout << "number: ";
        cin >> input;

        if (input == 0){
            active = 0;
        }

        sum += input;
    }
    cout << "---------------" << endl;
    cout << "sum: " << sum << endl;
}

// 2 c)
// i oppg a) med spesifikk antall iterasjoner er for loop best, og i oppg b) med ukjent antall iterasjoner er while loop best


// 2 d)
double inputDouble(){
    double input;
    cout << "Desicmal number: ";
    cin >> input;
    return input;
}

// 2 e)
double NOKToEURO(){
    bool active = 1;
    double euro;
    double nok;

    while (active){

        nok = inputDouble();

        // exit on positive number
        if (nok > 0){
            active = 0;
            break;
        }
    }
    euro = nok * 0.0930;

    cout << nok << " kroner = " << euro << " euro." << endl;
    return euro;
}

// 2 f)
// jeg bør bruke inputDouble fremfor inputInteger 
// fordi kroner er flytall så har man derfor mer valgmulighet, i tilegg ganges det med et flytall

// 2 g)
void productTable(){
    int height;
    int width;

    // set space between columns
    const int tableWidth = 4;


    cout << "Enter height: ";
    cin >> height;
    cout << "Enter width: ";
    cin >> width;
    cout << endl;

    // genreate table:
    for (int h = 1; h < height + 1; h++){

        for (int w = 1; w < width + 1; w++){
            cout << setw(tableWidth) << w * h;
        }
        cout << endl;
    }


}

// ------------------------------------------------------------

// 3 a)
double discriminant(double a, double b, double c){
    return (pow(b,2) - 4 * a*c);
}

// 3 b)
void printRealRoots(double a, double b, double c){
    
    double x_1 = -1;
    double x_2 = -1;

    double disc = discriminant(a, b, c);


    // two solutions
    if (disc > 0){
        x_1 = (-b + sqrt(disc))/(2*a);
        x_2 = (-b - sqrt(disc))/(2*a);
        cout << "x = " << x_1 << " v x = " << x_2 << endl;
    }
    // one solution (x_1)
    else if (disc == 0){
        x_1 = -b/(2*a);
        cout << "x = " << x_1 << endl;
    }
    else{
        cout << "The solution is complex " << endl;
    }
    
    
}

// 3 c)
void solveQuadraticEquation(){
    double abc[3];

    for (int i = 0; i < 3; i++){
        abc[i] = inputDouble();
    }

    cout << abc[0] << "x^2 + " << abc[1] << "x + " << abc[2] << " = 0" << endl;
    cout << "=> ";

    printRealRoots(abc[0], abc[1], abc[2]);

}

// --------------------------------------------------------------
// opgpave 4


void makePythagoras(){
    AnimationWindow win{100, 100, 500, 500, "Pytagoras"};

    // main triangle
    // top point
    Point point1{200, 150};

    // bottom left point 300
    Point point2{200, 300};

    // bottom right point
    Point point3{300, 300};
    
    win.draw_triangle(point1, point2, point3, Color::black);
    // main triangle end

    // left kvadrant
    int leftKvadrantLenght = abs(point2.y - point1.y);
    Point leftKvadrant_leftUpper = {point1.x - leftKvadrantLenght, point1.y};
    Point leftKvadrant_leftBottom = {point2.x - leftKvadrantLenght, point2.y};

    win.draw_quad(point1, leftKvadrant_leftUpper, leftKvadrant_leftBottom, point2, Color::green);
    // left kvadrant end

    // bottom kvadrant
    int bottomKvadrantLenght = abs(point3.x - point2.x);
    //cout << bottomKvadrantLenght << endl;
    Point bootomKvadrant_bottomLeft = {point2.x, point2.y + bottomKvadrantLenght};
    Point bottomKvadrant_bottomRight = {point3.x, point3.y + bottomKvadrantLenght};
    
    win.draw_quad(point2, bootomKvadrant_bottomLeft, bottomKvadrant_bottomRight, point3, Color::red);
    // bootom kvadrant end

    // hypotenuse
    Point hypotenuse_TopRight = {point1.x + leftKvadrantLenght, point1.y - bottomKvadrantLenght};
    Point hytenuse_bottomLeft = {point3.x + leftKvadrantLenght, point3.y - bottomKvadrantLenght};

    win.draw_quad(point3, hytenuse_bottomLeft, hypotenuse_TopRight, point1, Color::blue);
    // hypotenuse end
 
    win.wait_for_close();

}


// --------------------------------------------
// oppgave 5

// 5 a)
vector<int> calculateBalanse(int startCapital, int intrest, unsigned int years){

    vector<int> saldo(years);
    
    for (int i = 0; i < years; i++){
        saldo.at(i) = startCapital * pow((1 + static_cast<double>(intrest)/100), i);
    }

    return saldo;
}

// 5 b)
void printBalance(vector<int> saldo){

    int years = saldo.size();
    static int tableWidth = 15;

    cout << setw(tableWidth) << "years" << setw(tableWidth) <<"saldo" << endl;

    for (int i = 0; i < years; i++){
        cout << setw(tableWidth) << i << setw(tableWidth) << saldo.at(i) << endl;
    }
}


// 5 c)
// kan ikke skrive ut en vektor på grunn den inneholder mange element og ingen har laget en funksjon for hvordan
// cout skal håndtere det. man må skrive ut hvert element i feks en for loop slik som gjort i print balance


// 5 d)
// feilen i koden likker i leddet (i <= v.size()) og kommer av at vi prøver å sammenlikne to variabler av ulik datatype
// i er av typen int og v.size() er unsigned long long



int main() {
    

    int choosePage;
    bool active = 1;

    // variables used in switch case
    int heltall1C;
    int timeInSeconds;


    while (active)
    {
        // menu text
        cout << "velg funksjon:" << endl;
        cout << "0) Avslutt " << endl;
        cout << "1) Skriv inn heltall som printes ut" << endl;
        cout << "2) skriv inn heltall som retuneres" << endl;
        cout << "3) sum av to heltall" << endl;
        cout << "4) er tallet oddetall? fra 0 til 15" << endl;
        cout << "5) Sekunder om til timer, minutter og sekunder" << endl;
        cout << "6) gangetabell" << endl;
        cout << "7) abc- formel solver" << endl;
        cout << "8) tegn pyhtagoras" << endl;
        cout << "9) renters rente effekt" << endl;

        cout << "Angi valg (0-9): ";
        cin >> choosePage;
        
        // sepreate printout from menu
        cout << " " << endl;
        cout << "--------------" << endl;
        cout << " " << endl;

        // page chooser
        switch (choosePage)
        {
            case 0:
                active = 0;
                break;
            
            case 1:
                inputAndPrintInteger();
                break;
            
            case 2:
                heltall1C = inputInteger();
                cout << "du skrev: " << heltall1C << endl;
                break;
            
            case 3:
                inputIntegersAndPrintSum();
                break;

            case 4:
                for (int i = 0; i < 15; i++){
                        if (isOdd(i)) {
                            cout << i << " true" << endl;
                        } else {
                            cout << i << " false" << endl;
                    }

                }
                break;
            
            case 5:
                timeInSeconds = inputInteger();
                printHumanReadableTime(timeInSeconds);
                break;

            case 6:
                productTable();
                break;

            case 7:
                solveQuadraticEquation();
                break;

            case 8:
                makePythagoras();
                break;
            
            case 9:
                printBalance(calculateBalanse(5000, 5, 10)); // can make the user plot in input here if desired.
                break;
                
            default:
                cout << "Unvalid input" << endl;
                break;

        }
        cout << " " << endl;
        cout << "--------------" << endl;
        cout << " " << endl;
    }
    

    // exit program
    return 0;
}


