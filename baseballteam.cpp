#include "baseballteam.h"

unsigned short BaseballTeam::objectCount = 0;

BaseballTeam::BaseballTeam() :
    m_strName(""),
    m_nNumber(0)
{
    m_nNumber = objectCount;
    objectCount++;

    m_lMember.clear();
}

BaseballTeam::~BaseballTeam()
{
    m_lMember.clear();
}

void BaseballTeam::setName(const std::string name)
{
    m_strName = name;
}

std::string BaseballTeam::getName() const
{
    return m_strName;
}

void BaseballTeam::inputTeamData()
{
    std::cout << m_nNumber + 1 << "팀의 이름을 입력하세요> ";
    std::string strTeamName = receiveTeamName();
    setName(strTeamName);

    for ( int index = 0 ; index < 9 ; ++index ) {
        std::cout << index + 1 << "번 타자 정보 입력> ";
        std::vector<std::string> memberInformation = receiveTeamMemberInformation();
        appendMember(memberInformation.at(0), std::stof(memberInformation.at(1)));
    }
}

std::string BaseballTeam::receiveTeamName()
{
    std::string strTeamName;

    std::cout << m_nNumber << "팀의 이름을 입력하세요> ";
    std::cin >> strTeamName;

    return strTeamName;
}

std::vector<std::string> BaseballTeam::receiveTeamMemberInformation()
{
    std::vector<std::string> memberInformation;

    std::string strBuffer;
    std::cin >> strBuffer;
    memberInformation = parseTeamMemberInformation(strBuffer);

    return memberInformation;
}

std::vector<std::string> BaseballTeam::parseTeamMemberInformation(std::string buffer)
{
    int count = 0;
    std::string strData;
    std::stringstream streamBuffer; streamBuffer.clear(); streamBuffer.str(buffer);
    std::vector<std::string> memberInformation; memberInformation.clear();

    while(getline(streamBuffer, strData, ',')) {
        if ( 2 <= count ) { break; }
        else { memberInformation.push_back(strData); count++; }
    }

    return memberInformation;
}

void BaseballTeam::appendMember(std::string name, float battingAverage)
{
    m_lMember.push_back(BaseballTeamMember(name, battingAverage));
}

void BaseballTeam::showTeamData()
{
    std::cout << getName() << " 팀 정보" << std::endl;

    for ( std::vector<int>::size_type index = 0 ; index < 9 ; ++index )
    {
        std::cout << index + 1 << " 번 " << m_lMember.at(index).getName() << ", "
                  << m_lMember.at(index).getBattingAverage() << std::endl;
    }
}
