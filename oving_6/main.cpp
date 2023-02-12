
// #include "std_lib_facilities.h"
#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

// local files
#include "courseCatalog.h"
#include "temp.h"

// std::filesystem::path fileName{"myFile.txt"}; does not work!


std::string stringToLower(std::string str){
    
    std::string newString;
    newString.clear();

    for (char i : str){
        newString += tolower(i);
    }
    return newString;
}

void writeWordToFile(std::string file){
    // write
    std::ofstream outputStream{file};
    
    std::string word;

    while (1){
        std::cout << "-> "; // this bugs when writing many words
        std::cin >> word;

        outputStream << word << std::endl;

        if (stringToLower(word) == "quit"){
            break;
        }     
    }
}

void readNCopyFileWithPageNumber(std::string rPath, std::string wPath){
    std::string line;
    
    std::ifstream readFile{rPath};
    std::ofstream writeFile{wPath};
    

    int lineNumber = 0;
    if (readFile.is_open()){

        while(std::getline(readFile, line)){
            lineNumber++;
            writeFile << lineNumber << ". "<< line << std::endl;
        }
    }
    else {
        std::cout << "Error, file does not exsist." << std::endl;
    }

}


// telle alle bokstaver (a-z) bare små bokstaver.
void charStatistic(std::string path){
    
    std::map<char, int> charCount;
    
    
    // for (char c = 'a'; c < 'z'+ 1; c++){
    //     charCount.insert({c, 0});
    // }
    
    std::ifstream readFile{path};


    char c;
    while (readFile >> c){
        if (c >= 'a' && c <= 'z'){
        // charCount.at(c)++;
        charCount[c]++;
        }
    }

    // print map
    for (std::pair<const char, const int> m:charCount){
        std::cout << m.first << ": " << m.second << std::endl;
    }
}


const std::map<std::string, std::string> capitalsMap {
{"Norway", "Oslo"},
{"Sweden", "Stockholm"},
{"Denmark", "Copenhagen"}
};

std::string getCapital(const std::string country) {
return capitalsMap.at(country);
}



void testCourseCatalog(){
    CourseCatalog cc;
    // cc.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    // cc.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    // cc.addCourse("TMA4100", "Matematikk 1");

    // cc.addCourse("TDT4102", "c++");
    // cc.saveToFile();
    cc.getFromFile();

    std::cout << cc;
}




//------------------------------------------------------------------------------


int main() {
    // writeWordToFile();
    // readNCopyFileWithPageNumber();
    // writeWordToFile("test.txt");
    // charStatistic("test.txt");

    // std::cout << "Capitals:" << std::endl;
    // for (std::pair<const std::string, const std::string> elem : capitalsMap) {
    //     std::cout << getCapital(elem.first) << std::endl;
    // }

    // testCourseCatalog();
    // testTemp();

    std::vector<Temps> t = readTemps("temperatures.txt");

    tempStats(t);



    return 0;
}

//------------------------------------------------------------------------------
