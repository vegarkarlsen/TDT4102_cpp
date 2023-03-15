#include "meeting.h"
#include "iostream"
#include "map"

void Meeting::addParticipants(std::shared_ptr<Person> p){
    this->participants.push_back(p);
    
}

Meeting::Meeting(int DAY, int STARTTIME, int ENDTIME, Campus LOCATION, std::string SUBJECT, std::shared_ptr<Person> LEADER) 
: day{DAY}, startTime{STARTTIME}, endTime{ENDTIME}, location{LOCATION}, subject{SUBJECT}, leader{LEADER}
{
    this->addParticipants(LEADER);
}


std::vector<std::string> Meeting::getParticipantsList() const {
    std::vector<std::string> list;

    for (auto p : this->participants){
        list.push_back(p->getName());
    }
    return list;
}


std::map<Campus, std::string> CampusToString{
    {Campus::aalesund, "aalesund"},
    {Campus::gjoovik, "gjovik"},
    {Campus::trondheim, "trondheim"}
};

std::ostream& operator<<(std::ostream &os, const Meeting &m){
    os << "subject: " << m.getSubject() << "\n"
    << "location: " << CampusToString.at(m.GetLocation()) << "\n"
    << "startTime: " << m.getStartTime() << "\n"
    << "endTime: " << m.getEndTime() << "\n"
    << "participants: " << "\n";

    for (auto name : m.getParticipantsList()){
        os << name << "\n";
    }
    return os;
}

std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(const Meeting &m) const {
    std::vector<std::shared_ptr<Person>> potentialCoDrivers;

    if (this->location != m.location){
        return potentialCoDrivers;
    }
    if (this->day != m.day){
        return potentialCoDrivers;
    }
    if (abs(this->startTime - m.startTime) > 1){
        return potentialCoDrivers;
    }
    if (abs(this->endTime - m.endTime) > 1){
        return potentialCoDrivers;
    }

    for (auto p : m.participants){
        if (p->hasAvailibleSeat()){
            potentialCoDrivers.push_back(p);
        }
    }
    return potentialCoDrivers;
}

