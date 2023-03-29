#include "meetingWindow.h"


MeetingWindow::MeetingWindow(int x, int y, int w, int h, const std::string &title):
        AnimationWindow{x, y, w, h, title},
        quitButton{{w - pad - btnW/2, pad + btnH/2}, btnW, btnH, "quit"}
        {
            add(quitButton);
            quitButton.setCallback(std::bind(MeetingWindow::cb_quit, this));
            
        }

void MeetingWindow::cb_quit(){
    close();
}