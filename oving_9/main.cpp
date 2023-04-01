#include <iostream>
#include <memory>
#include <string>

#include "person.h"
#include "car.h"
#include "meeting.h"
#include "meetingWindow.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"


void test(){

    std::unique_ptr<Person> unqPers = std::make_unique<Person>("n", "@");
    
    std::shared_ptr<Person> sharPer1 = std::make_shared<Person>("s", "@");

    std::shared_ptr<Person> sharePer2 = sharPer1;

    std::cout << "unqPers: " << *unqPers << std::endl;
    std::cout << "sharPer1: " << *sharPer1 << std::endl;
    std::cout << "sharPer2: " << *sharePer2 << std::endl;

    std::cout << "transfering ownership from unqPers to newUnq" << std::endl;

    std::unique_ptr<Person> newUnq = std::move(unqPers);

}


int main(){

    // Person p{"paal", "paal@n.no", std::make_unique<Car>(3)};
    // Person b{"olga", "olga@n.no"}; 
    // std::cout << p << std::endl;
    // std::cout << b << std::endl;
    
    // std::shared_ptr<Person> leader = std::make_shared<Person>("andreas", "@", std::make_unique<Car>(3));
    // std::shared_ptr<Person> par = std::make_shared<Person>("Vegar", "@", std::make_unique<Car>(4));
    
    // Meeting m{5, 50, 70, Campus::trondheim, "AI", leader};
    // m.addParticipants(par);

    // std::cout << m << std::endl;

    const std::string title = "GUI";
    MeetingWindow m{500, 300, wWidth, wHeight, title};

    m.wait_for_close();

    for (auto p : m.people){
        std::cout << *p << std::endl;
    }


    return 0;
}