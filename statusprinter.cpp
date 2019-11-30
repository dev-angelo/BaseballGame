#include "statusprinter.h"
#include "pitchingresult.h"


StatusPrinter::StatusPrinter()
{

}

StatusPrinter::~StatusPrinter()
{

}

void StatusPrinter::showPitchingResult(unsigned short strike,
                                       unsigned short ball,
                                       PitchingResult pitchingResult)
{
    //Todo: Implement simple output of pitching result to console screen

    if ( PitchingResult::STRIKE == pitchingResult ) {

    }
    else if ( PitchingResult::BALL == pitchingResult ) {

    }
    else if ( PitchingResult::HITS == pitchingResult ) {

    }
    else if ( PitchingResult::OUT == pitchingResult ) {

    }
}

void StatusPrinter::showScoreBoard(unsigned short strikeCount, unsigned short ballCount, unsigned short outCount)
{
    //Todo: Implement to display current score board (ex. 2S 0B 1O) to console screen
}

void StatusPrinter::showNextBatter()
{
    //Todo: Implement to display next batter's appearance (ex. 다음 타자가 타석에 입장했습니다.) to console screen
}

void StatusPrinter::showGameEndComment(unsigned short hitsCount)
{
    //Todo: Implement to game end comment. (ex. 최종 안타수 : 5 \n GAME OVER)
}

void StatusPrinter::showStrikeOccurs(unsigned short strike, unsigned short ball)
{
    //Todo: Implement to display strike occurs
}

void StatusPrinter::showBallOccurs(unsigned short strike, unsigned short ball)
{
    //Todo: Implement to display ball occurs
}

void StatusPrinter::showHitsOccurs()
{
    //Todo: Implement to display hits occurs
}

void StatusPrinter::showOutOccurs()
{
    //Todo: Implement to display out occurs
}

void StatusPrinter::showThreeStrikeOutOccursComment()
{
    //Todo: Implement to display out occurs by 3 strike (2strike + 1strike)
}

void StatusPrinter::showFourBallHitsOccursComment()
{
    //Todo: Implement to display hits occurs by 4 ball (3ball + 1ball)
}
