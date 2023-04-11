#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>



struct Temps{
    double max = 0;
    double min = 0;

    std::string line = "";


};

std::vector<Temps> readTemps(std::string filename);

void testTemp();

void tempStats(std::vector<Temps> temps);