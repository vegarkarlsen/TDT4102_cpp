#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"


constexpr int wWidth = 500;
constexpr int wHeigt = 500;


class MeetingWindow : public AnimationWindow {

    private:
        Button quitButton;
    
    public:
        inline static constexpr int pad = wWidth/50;
        inline static constexpr int btnW = wWidth/30;
        inline static constexpr int btnH = wHeigt/40;
        inline static constexpr int fieldW = wWidth/3;
        inline static constexpr int fieldH = 2/3 * btnH;
        inline static constexpr int fieldPad = wWidth/8;

        MeetingWindow(int x, int y, int w, int h, const std::string &title);

        void cb_quit();



};