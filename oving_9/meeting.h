#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "person.h"

enum class Campus {trondheim=0, aalesund, gjoovik};

std::ostream& operator<<(std::ostream& os, const Campus &c);



class Meeting{
    private:
        int day;
        int startTime;
        int endTime;
        Campus location;
        std::string subject;
        const std::shared_ptr<Person> leader;
        std::vector<std::shared_ptr<Person>> participants;
    
    public:
        int getDay() const { return day; }
        int getStartTime() const {return startTime; }
        int getEndTime() const { return endTime; }
        Campus getLocation() const {return location; }
        std::string getSubject() const {return subject; }
        std::vector<std::shared_ptr<Person>> getParticipants() const { return participants; }
        std::shared_ptr<Person> getLeader() const { return leader; }

        void addParticipants(std::shared_ptr<Person> p);

        Meeting(int d, int sTime, int eTime, Campus loc, std::string sub, std::shared_ptr<Person> leader);
        
        std::vector<std::string> getParticipantsList();

        std::vector<std::shared_ptr<Person>> findPotentialCoDriving(const Meeting &m);
};