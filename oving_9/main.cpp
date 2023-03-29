#include "person.h"
#include "car.h"
#include "meeting.h"
#include <iostream>
#include <memory>

#include "meetingWindow.h"

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

    std::string title = "Meeting simulator";
    MeetingWindow win{500,500,wWidth, wHeigt, title};




    win.wait_for_close();
    return 0;
}