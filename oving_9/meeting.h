#pragma once
#include <vector>
#include <memory>

#include "person.h"



enum class Campus{trondheim=0, aalesund, gjoovik};



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
        int getDay() const {return day; }
        int getStartTime() const { return startTime; }
        int getEndTime() const {return endTime; }
        Campus GetLocation() const {return location; }
        std::string getSubject() const {return subject; }
        std::shared_ptr<Person> getLeader() const {return leader; }

        void addParticipants(std::shared_ptr<Person> p);

        Meeting(int DAY, int STARTTIME, int ENDTIME, Campus LOCATION, std::string SUBJECT, std::shared_ptr<Person> LEADER);

        std::vector<std::string> getParticipantsList() const ;

        std::vector<std::shared_ptr<Person>> findPotentialCoDriving(const Meeting &m) const;




};

std::ostream& operator<<(std::ostream &os, const Meeting &m);