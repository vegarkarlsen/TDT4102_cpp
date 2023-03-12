#include "meeting.h"


std::ostream& operator<<(std::ostream& os, const Campus &c){
    switch (int(c))
    {
    case 0:
        os << "Trondheim";
        break;
    case 1:
        os << "Aalesund";
        break;
    case 2:
        os << "gjoovik";
        break;
    default:
        break;
    }
    return os;
}


void Meeting::addParticipants(std::shared_ptr<Person> p){
    participants.push_back(p);

}

Meeting::Meeting(int d, int sTime, int eTime, Campus loc, std::string sub, std::shared_ptr<Person> leader) : 
    day{d}, 
    startTime{sTime}, 
    endTime{eTime}, 
    location{loc}, 
    subject{sub}, 
    leader{leader} 
    {
        addParticipants(leader);
}

std::vector<std::string> Meeting::getParticipantsList(){
    std::vector<std::string> list;

    for (auto n : participants){
        list.push_back(n->getName()); 
    }
    return list;
}

std::ostream& operator<<(std::ostream &os, Meeting& m ){
    os << "subject: " << m.getSubject() << std::endl;
    os << "location: " << m.getLocation() << std::endl;
    os << "startTime" << m.getStartTime() << std::endl;
    os << "endTime: " << m.getEndTime() << std::endl;
    os << "meeting leader: " << m.getLeader()->getName() << std::endl;
    os << "participants: " << std::endl;
    for (auto name : m.getParticipantsList()){
        os << name << std::endl;
    }
} 


std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(const Meeting &m){
    std::vector<std::shared_ptr<Person>> sameTime;
    if (abs(this->endTime - m.endTime) < 1){
        return sameTime;
    }
    if (abs(this->startTime - m.startTime) < 1){
        return sameTime;          
    }
    if (this->day == m.day){
        return sameTime;    
    }
    if (this->location == m.location){
        return sameTime;
    }

    for (auto p : m.participants){
        if (p->hasAvailibleSeat()){
            sameTime.push_back(p);
        }
    }
}