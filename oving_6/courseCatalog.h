
#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>

class CourseCatalog{
    
    private:
        // {Emnekode, name}
        std::map<std::string, std::string> courses;
        const std::string filenName = "course_catalog.txt"; 

    public:
        void addCourse(std::string code, std::string name);
        void removeCourse(std::string code);
        std::string getCourse(std::string code);

        friend std::ostream& operator<<(std::ostream& os, const CourseCatalog& c);

        void saveToFile();
        void getFromFile();
};