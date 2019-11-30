#include "baseballgamemanager.h"

#include "pitchingresultgenerator.h"
#include "scoreboard.h"
#include "officialscorer.h"
#include "statusprinter.h"

#include "pitchingresult.h"

#include <iostream>

#define MAXIMUM_STRIKE_COUNT 2
#define MAXIMUM_BALL_COUNT 3

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
    //Todo: Implement logic to process sequence described in requirement.
}

void BaseballGameManager::playInning()
{
    //Todo: Implement logic to process one inning.
}

bool BaseballGameManager::isGameEnd(unsigned short outCount)
{
    //Todo: 1. Implement logic to determine whether the game is over and 2. return the result

    return true;
}
