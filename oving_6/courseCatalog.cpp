
#include "courseCatalog.h"

/*
insert does nothing if the key allerady exsists
op[] = value, changes the value, and makes a new one if the value does not exists.
Kunne brukt insert på addCourse og laget en ny updateCourse funksjon:
courses.at("code") = newname, her endres bare elementet dersom det finnes.
*/

void CourseCatalog::addCourse(std::string code, std::string name){
    CourseCatalog::courses.insert({code, name});
    // CourseCatalog::courses[code] = name;
}

void CourseCatalog::removeCourse(std::string code){
    CourseCatalog::courses.erase({code});
}

std::string CourseCatalog::getCourse(std::string code){
    return CourseCatalog::courses.at(code);
}



std::ostream& operator<<(std::ostream& os, const CourseCatalog& c){
    for (std::pair<const std::string, const std::string> course: c.courses){
        os << course.first << ": " << course.second << std::endl;
    }
    return os;
}

void CourseCatalog::saveToFile(){
    std::ofstream w{CourseCatalog::filenName};
    
    if (w.is_open()){
        for (std::pair<const std::string, const std::string> m: CourseCatalog::courses){
            w << m.first << ":" << m.second << std::endl;
        }
    }
    else {
        std::cout << "Error, cant save to file." << std::endl;
    }
}


void CourseCatalog::getFromFile(){
    std::ifstream r{this->filenName};

    std::string line;
    std::string code;
    std::string name;

    int codeSeperatorIndex = 0;
    // int nameSepreatorIndex = 0;

    if (r.is_open()){
        while (std::getline(r, line)){
            codeSeperatorIndex = line.find(":");
            // nameSepreatorIndex = line.find(";");

            code = line.substr(0, codeSeperatorIndex - 1);
            name = line.substr(codeSeperatorIndex + 1, line.size());

            // std::cout << code << "\n" << name << std::endl;

            this->addCourse(code, name);
        }

    }
    else {
        std::cout << "error, cant read from file" << std::endl;
    }
}


