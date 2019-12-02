#include "pitchingresultgenerator.h"
#include "pitchingresult.h"

#include <cstdlib>
#include <ctime>

PitchingResultGenerator::PitchingResultGenerator()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

PitchingResultGenerator::~PitchingResultGenerator()
{

}

PitchingResult PitchingResultGenerator::generatePitchingResult(double battingAverage)
{
    int nStrikePercentage = static_cast<int>(((1 - battingAverage)/2 - 0.035)*10000);
    int nBallPercentage = static_cast<int>(((1 - battingAverage)/2 - 0.035)*10000);
    int nOutPercentage = static_cast<int>(0.1 * 10000);
    int nBattingAverage = static_cast<int>(battingAverage * 10000);
    int nRandomNumber = std::rand() % (nStrikePercentage + nBallPercentage + nOutPercentage + nBattingAverage);
    PitchingResult ePitchingResult = determinePitchingType(nRandomNumber, nOutPercentage, nBattingAverage, nStrikePercentage, nBallPercentage);

    return ePitchingResult;
}

PitchingResult PitchingResultGenerator::determinePitchingType(int generatedRamdomNumber, int outPercentage, int battingAverage, int strikePercentage, int ballPercentage)
{
    PitchingResult ePitchingResult = PitchingResult::STRIKE;

    if ( 0 <= generatedRamdomNumber && generatedRamdomNumber < outPercentage) {
        ePitchingResult = PitchingResult::OUT;
    }
    else if ( outPercentage <= generatedRamdomNumber && generatedRamdomNumber < outPercentage + battingAverage ) {
        ePitchingResult = PitchingResult::HITS;
    }
    else if ( outPercentage + battingAverage <= generatedRamdomNumber && generatedRamdomNumber < outPercentage + battingAverage + strikePercentage ) {
        ePitchingResult = PitchingResult::STRIKE;
    }
    else if ( outPercentage + battingAverage + strikePercentage <= generatedRamdomNumber && generatedRamdomNumber < outPercentage + battingAverage + strikePercentage + ballPercentage ) {
        ePitchingResult = PitchingResult::BALL;
    }
    return ePitchingResult;
}
