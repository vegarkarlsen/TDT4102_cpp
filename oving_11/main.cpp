
#include <vector>
#include <iostream>
#include <string>
#include <iterator>


void task_1a(std::vector<std::string> &strs){

    // for (auto word = strs.cbegin(); word != strs.cend(); word++ ){
    //     std::cout << *word << std::endl;
    // }
    auto test = strs.begin();
    for (auto it = strs.begin(); it != strs.end(); it++){
        std::cout << *it << std::endl;
    }

}


void task_1b(std::vector<std::string> &strs){

    for (auto word = --strs.cend(); word != --strs.cbegin(); word--){
        std::cout << *word << std::endl;
    }
}

void replace(std::vector<std::string> &strs, std::string old, std::string replacement){
    for (auto it = strs.begin(); it != strs.end(); it++){
        if (*it == old){
            strs.insert(it, replacement);
        }
    }
}

int main() {

    std::vector<std::string> strs = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectur"};

    replace(strs, "Sit", "hei");

    task_1a(strs);
    std::cout << std::endl;
    task_1b(strs);



    return 0;
}