#ifndef BASEBALLTEAM_H
#define BASEBALLTEAM_H

#include <iostream>
#include <vector>
#include <sstream>
#include "baseballteammember.h"

class BaseballTeam
{
public:
    BaseballTeam();
    ~BaseballTeam();

    /**
     * Getter about team name.
     */
    std::string getName() const;

    /**
     * Input team and team member information from user.
     */
    void inputTeamData();

    /**
     * Print information about team name and all members name & batting average.
     */
    void showTeamData();

private:
    std::string m_strName;
    std::vector<BaseballTeamMember> m_lMember;
    unsigned short m_nNumber;

    static unsigned short objectCount;

    /**
     * Setter about team name.
     */
    void setName(const std::string name);

    std::string receiveTeamName();
    std::vector<std::string> receiveTeamMemberInformation();
    std::vector<std::string> parseTeamMemberInformation(std::string teamInformation);

    /**
     * Append member
     * @param name Member's name (ex. Tom)
     * @param battingAverage Member's batting average (ex. 0.325)
     *
     */
    void appendMember(std::string name, float battingAverage);
};

#endif // BASEBALLTEAM_H
