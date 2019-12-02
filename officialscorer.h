#ifndef OFFICIALSCORER_H
#define OFFICIALSCORER_H

#include <map>

class ScoreBoard;
enum class PitchingResult;

class OfficialScorer
{
public:
    OfficialScorer(ScoreBoard* scoreBoard);
    ~OfficialScorer();

    /**
     * Calculate strike, ball, hits, out through pithing result
     *
     * @param pitchingResult
     * @return If out occurs or on base (true), else (false)
     */
    bool calculatePitchingResult(PitchingResult pitchingResult);

    void clearSBHO();
    void setIsCurrentHomeTeam(const bool isCurrentHomeTeam);

private:
    ScoreBoard* m_pScoreBoard;
    bool m_bIsCurrentHomeTeam;

    /**
     * Calculate strike count when strike occurs
     */
    bool calculateStrikeOccurs();

    /**
     * Calculate ball count when ball occurs
     */
    bool calculateBallOccurs();

    /**
     * Calculate hits count when hits occurs
     */
    bool calculateHitOccurs();

    /**
     * Calculate out count when out occurs
     */
    bool calculateOutOccurs();

    bool getIsCurrentHomeTeam() const;

    void handleSBHOFourBallOccurs();
};

#endif // OFFICIALSCORER_H
