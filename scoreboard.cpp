#include "scoreboard.h"
#include <iostream>

ScoreBoard::ScoreBoard() :
    m_nStrikeCount(0),
    m_nBallCount(0),
    m_nHitsCount(0),
    m_nOutCount(0)
{
    initTeamScore();
    initTeamPitchingCount();
    initTeamThreeOutCount();
    initTeamHitsCount();

    m_lTeamName.clear();
    m_lTeamMemberName.clear();
}

ScoreBoard::~ScoreBoard()
{

}

void ScoreBoard::setStrikeCount(const unsigned short strikeCount)
{
    m_nStrikeCount = strikeCount;
}

void ScoreBoard::setBallCount(const unsigned short ballCount)
{
    m_nBallCount = ballCount;
}

void ScoreBoard::setHitsCount(const unsigned short hitsCount)
{
    m_nHitsCount = hitsCount;
}

void ScoreBoard::setOutCount(const unsigned short outCount)
{
    m_nOutCount = outCount;
}

void ScoreBoard::setTeamScore(const unsigned short score,
                          const unsigned short inning,
                          const bool isHomeTeam)
{
    unsigned short nCvtInning = (inning / 2);

    if ( true == isHomeTeam ) {
        m_lTeamScore[0][nCvtInning] = score;
    }
    else {
        m_lTeamScore[1][nCvtInning] = score;
    }
}

void ScoreBoard::setTeamPitchingCount(const unsigned short pitchingCount, const bool isHomeTeam)
{
    if ( true == isHomeTeam )
        m_lTeamPitchingCount[0] = pitchingCount;
    else
        m_lTeamPitchingCount[1] = pitchingCount;
}

void ScoreBoard::setTeamThreeOutCount(const unsigned short threeOutCount, const bool isHomeTeam)
{
    if ( true == isHomeTeam )
        m_lTeamThreeOutCount[0] = threeOutCount;
    else
        m_lTeamThreeOutCount[1] = threeOutCount;
}

void ScoreBoard::setTeamHitsCount(const unsigned short hitsCount, const bool isHomeTeam)
{
    if ( true == isHomeTeam )
        m_lTeamHitsCount[0] = hitsCount;
    else
        m_lTeamHitsCount[1] = hitsCount;
}

void ScoreBoard::setTeamName(std::vector<std::string> teamName)
{
    m_lTeamName = teamName;
}

void ScoreBoard::setTeamMemberName(const std::vector<std::vector<std::string>> teamMemberName)
{
    m_lTeamMemberName = teamMemberName;
}

unsigned short ScoreBoard::getStrikeCount() const
{
    return m_nStrikeCount;
}

unsigned short ScoreBoard::getBallCount() const
{
    return m_nBallCount;
}

unsigned short ScoreBoard::getHitsCount() const
{
    return m_nHitsCount;
}

unsigned short ScoreBoard::getOutCount() const
{
    return m_nOutCount;
}

unsigned short ScoreBoard::getTeamScore(const bool isHomeTeam) const
{
    unsigned short nScore = 0;
    const unsigned short* pCurrentTeamScore = (isHomeTeam == true) ? m_lTeamScore[0] : m_lTeamScore[1];

    for ( int index = 0 ; index < 6 ; ++index ) {
        nScore += *(pCurrentTeamScore + index);
    }

    return nScore;
}

unsigned short ScoreBoard::getTeamScore(const unsigned short inning, const bool isHomeTeam) const
{
    unsigned short nScore = 0;
    unsigned short nCvtInning = (inning / 2);

    if ( true == isHomeTeam ) {
        nScore = m_lTeamScore[0][nCvtInning];
    }
    else {
        nScore = m_lTeamScore[1][nCvtInning];
    }

    return nScore;
}

unsigned short ScoreBoard::getTeamPitchingCount(const bool isHomeTeam) const
{
    unsigned short teamPitchingCount = 0;

    if ( true == isHomeTeam )
        teamPitchingCount = m_lTeamPitchingCount[0];
    else
        teamPitchingCount = m_lTeamPitchingCount[1];

    return teamPitchingCount;
}

unsigned short ScoreBoard::getTeamThreeOutCount(const bool isHomeTeam) const
{
    unsigned short teamThreeOutCount = 0;

    if ( true == isHomeTeam )
        teamThreeOutCount = m_lTeamThreeOutCount[0];
    else
        teamThreeOutCount = m_lTeamThreeOutCount[1];

    return teamThreeOutCount;
}

unsigned short ScoreBoard::getTeamHitsCount(const bool isHomeTeam) const
{
    unsigned short teamHitsCount = 0;

    if ( true == isHomeTeam )
        teamHitsCount = m_lTeamHitsCount[0];
    else
        teamHitsCount = m_lTeamHitsCount[1];

    return teamHitsCount;
}

void ScoreBoard::showScoreBoard()
{
    std::cout << getStrikeCount() << "S " << getBallCount() << "B " << getOutCount() << "O"
              << std::endl << std::endl;
}

void ScoreBoard::initTeamScore()
{
    for ( int teamIndex = 0 ; teamIndex < 2 ; ++teamIndex )
    {
        for ( int memberIndex = 0 ; memberIndex < 6 ; ++memberIndex )
        {
            m_lTeamScore[teamIndex][memberIndex] = 0;
        }
    }
}

void ScoreBoard::initTeamPitchingCount()
{
    for ( int teamIndex = 0 ; teamIndex < 2 ; ++teamIndex )
    {
        m_lTeamPitchingCount[teamIndex] = 0;
    }
}

void ScoreBoard::initTeamThreeOutCount()
{
    for ( int teamIndex = 0 ; teamIndex < 2 ; ++teamIndex )
    {
        m_lTeamThreeOutCount[teamIndex] = 0;
    }
}

void ScoreBoard::initTeamHitsCount()
{
    for ( int teamIndex = 0 ; teamIndex < 2 ; ++teamIndex )
    {
        m_lTeamHitsCount[teamIndex] = 0;
    }
}
