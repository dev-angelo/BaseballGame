#include "scoreboard.h"

ScoreBoard::ScoreBoard() :
    m_nStrikeCount(0),
    m_nBallCount(0),
    m_nHitsCount(0),
    m_nOutCount(0)
{
    m_lScore[0] = 0;
    m_lScore[1] = 0;
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

void ScoreBoard::setScore(const unsigned short score, const bool isHomeTeam)
{
    if ( true == isHomeTeam ) {
        m_lScore[0] = score;
    }
    else {
        m_lScore[1] = score;
    }
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

unsigned short ScoreBoard::getScore(bool isHomeTeam)
{
    unsigned short nScore = 0;

    if ( true == isHomeTeam ) {
        nScore = m_lScore[0];
    }
    else {
        nScore = m_lScore[1];
    }

    return nScore;

}
