#include "temp.h"


std::istream& operator>>(std::istream& is, Temps& t){
    
    is >> t.max >> t.min;
    return is;
}


std::vector<Temps> readTemps(std::string filename){
    std::ifstream tempFile{filename};
    Temps temps;
    
    std::vector<Temps> t;

    while (tempFile >> temps){
        t.push_back(temps);
    }
    return t;

}

void tempStats(std::vector<Temps> temps){
    
    double max = 0.0;
    int maxIndex;
    double min = 0.0;
    int minIndex;

    for (int i = 0; i < static_cast<int>(temps.size()); i++){
        // finds max temp
        if (temps.at(i).max > max){
            max = temps.at(i).max;
            maxIndex = i;
        }

        // find min temp 
        if (temps.at(i).min < min){
            min = temps.at(i).min;
            minIndex = i;
        }
    }

    std::cout << "Max temp: " << max << " on day " << maxIndex << std::endl;
    std::cout << "Min temp: " << min << " on day " << minIndex << std::endl;
}




void testTemp(){
    std::ifstream temp_file{"temperatures.txt"};
    Temps t;

    // std::cin >> t;
    
    temp_file >> t;

    std::cout <<"max: " << t.max << " min: " << t.min << std::endl;

    
}