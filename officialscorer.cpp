#include "officialscorer.h"
#include "scoreboard.h"

#include "pitchingresult.h"

OfficialScorer::OfficialScorer(ScoreBoard* scoreBoard) :
    m_pScoreBoard(scoreBoard)
{

}

OfficialScorer::~OfficialScorer()
{

}

bool OfficialScorer::calculatePitchingResult(PitchingResult pitchingResult)
{
    //Todo: Implement logic to manipulate scoreboard based on pitching result.

    if ( PitchingResult::STRIKE == pitchingResult ) {

    }
    else if ( PitchingResult::BALL == pitchingResult ) {

    }
    else if ( PitchingResult::HITS == pitchingResult ) {

    }
    else if ( PitchingResult::OUT == pitchingResult ) {

    }
}

bool OfficialScorer::calculateStrikeOccurs()
{
    //Todo: Implement logic for calculating sbo when the strike occurs.
}

bool OfficialScorer::calculateBallOccurs()
{
    //Todo: Implement logic for calculating sbo when the ball occurs.
}

bool OfficialScorer::calculateHitOccurs()
{
    //Todo: Implement logic for increasement hits count when the hits occurs.
}

bool OfficialScorer::calculateOutOccurs()
{
    //Todo: Implement logic for calculating sbo when the out occurs.
}
