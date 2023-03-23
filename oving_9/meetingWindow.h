#pragma once

// #include "std_lib_facilities.h"
#include <string>
#include <vector>

#include "person.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"




constexpr int wWidth = 500;
constexpr int wHeight = 500;



class MeetingWindow : public TDT4102::AnimationWindow {
    private: 
        TDT4102::Button quitBtn;
        TDT4102::TextInput personName;
        TDT4102::TextInput personEmail;
        TDT4102::TextInput personCar;
        TDT4102::Button personNewBtn;

        
        void newPerson();


    public:
        MeetingWindow(int x, int y, int w, int h, const std::string &title);
        ~MeetingWindow();

        // avg w and h
        inline static constexpr int pad = wWidth/15;
        inline static constexpr int btnW = pad * 4;
        inline static constexpr int btnH = pad * 2;
        inline static constexpr int fieldW = wWidth/3;
        inline static constexpr int fieldH = pad;
        inline static constexpr int fieldPad = 3 * pad;

        std::vector<std::shared_ptr<Person>> people;

        void cb_quit();
        
};      