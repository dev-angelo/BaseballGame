#include "baseballgamemanager.h"

#include "pitchingresultgenerator.h"
#include "scoreboard.h"
#include "officialscorer.h"
#include "statusprinter.h"

#include "pitchingresult.h"

#include <iostream>

#define MAXIMUM_OUT_COUNT 2

BaseballGameManager::BaseballGameManager()
{
    m_pPitchingResultGenerator = new PitchingResultGenerator;
    m_pScoreBoard = new ScoreBoard;
    m_pOfficialScorer = new OfficialScorer(m_pScoreBoard);
    m_pStatusPrinter = new StatusPrinter;
}

BaseballGameManager::~BaseballGameManager()
{
    delete m_pPitchingResultGenerator;
    delete m_pOfficialScorer;
    delete m_pScoreBoard;
    delete m_pStatusPrinter;
}

void BaseballGameManager::startGame()
{
    std::cout << "신나는 야구 게임!" << std::endl;
    std::cout << "첫번째 타자가 입장하였습니다." << std::endl;

    while ( false == isGameEnd(m_pScoreBoard->getOutCount()) ) {
        playInning();
    }

    m_pStatusPrinter->showGameEndComment(m_pScoreBoard->getHitsCount());
}

void BaseballGameManager::playInning()
{
    PitchingResult pitchResult = m_pPitchingResultGenerator->generatePitchingResult();

    m_pStatusPrinter->showPitchingResult(m_pScoreBoard->getStrikeCount(), m_pScoreBoard->getBallCount(),
                                         pitchResult);


    bool bEndTheAtBat = m_pOfficialScorer->calculatePitchingResult(pitchResult);

    if ( (true == bEndTheAtBat ) && (false == isGameEnd(m_pScoreBoard->getOutCount())) ) {
        m_pStatusPrinter->showNextBatter();
    }

    m_pStatusPrinter->showScoreBoard(m_pScoreBoard->getStrikeCount(), m_pScoreBoard->getBallCount(), m_pScoreBoard->getOutCount());
}

bool BaseballGameManager::isGameEnd(unsigned short outCount)
{
    bool result = false;

    if ( MAXIMUM_OUT_COUNT < outCount )
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
