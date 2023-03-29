#include "meetingWindow.h"
<<<<<<< HEAD


MeetingWindow::MeetingWindow(int x, int y, int w, int h, const std::string &title):
        AnimationWindow{x, y, w, h, title},
        quitButton{{w - pad - btnW/2, pad + btnH/2}, btnW, btnH, "quit"}
        {
            add(quitButton);
            quitButton.setCallback(std::bind(MeetingWindow::cb_quit, this));
            
        }

void MeetingWindow::cb_quit(){
    close();
=======
#include <iostream>
#include <memory>

#define LOG
#include "log.h"

// constructor
MeetingWindow::MeetingWindow(int x, int y, int w, int h, const std::string &title) : 
TDT4102::AnimationWindow{x,y,w,h,title},
quitBtn{{wWidth - pad - btnW, pad}, btnW, btnH, "Quit"},
personName{{fieldPad, pad}, fieldW, fieldH, ""},
personEmail{{fieldPad, 2*pad + fieldH}, fieldW, fieldH, ""},
personCar{{fieldPad, 3*pad + 2*fieldH}, fieldW, fieldH, ""},
personNewBtn{{fieldPad, 4 * pad + 3* fieldH}, btnW, btnH, "Add Person"}
{

    TDT4102::AnimationWindow::add(this->quitBtn);
    quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
    
    // add text fields
    TDT4102::AnimationWindow::add(this->personName);
    TDT4102::AnimationWindow::draw_text({5, pad}, "Name");

    TDT4102::AnimationWindow::add(this->personEmail);
    TDT4102::AnimationWindow::draw_text({5, 2*pad + fieldH}, "Email");

    TDT4102::AnimationWindow::add(this->personCar);
    TDT4102::AnimationWindow::draw_text({5, 3*pad + 2*fieldH}, "Car seats");

    TDT4102::AnimationWindow::add(personNewBtn);
    personNewBtn.setCallback(std::bind(&MeetingWindow::newPerson, this));


    
    

}

//desctructor
MeetingWindow::~MeetingWindow(){

}


// callback function to quit button
void MeetingWindow::cb_quit(){
    TDT4102::AnimationWindow::close();
}


void MeetingWindow::newPerson(){

    std::string name = this->personName.getText();
    std::string mail = this->personEmail.getText();
    // stoi : string to int
    
    int seats = 0;

    // catch non int and exit
    try{
    seats = stoi(this->personCar.getText());
    }
    catch (std::invalid_argument){
        std::cout << "seats must be an int" << std::endl;
        return;
    }    

    // emtpy textbox -> do nothing
    if (name.size() < 1 || mail.size() < 1){
        std::cout << " did nothing!" << std::endl;
        return;
    }

    if (seats > 0){
        std::unique_ptr<Car> c = std::make_unique<Car>(seats);
        c->reserveFreeSeat();
        this->people.emplace_back(new Person{name, mail, std::move(c)});
    }
    else{
        this->people.emplace_back(new Person{name, mail});
    }

    this->personName.setText("");
    this->personEmail.setText("");
    this->personCar.setText("0");
    
    std::cout << "added person" << std::endl;
>>>>>>> 9d6db930b8f3a06fbfcf72e8a9a8f1136e427bea
}