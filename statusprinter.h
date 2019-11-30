#ifndef STATUSPRINTER_H
#define STATUSPRINTER_H

enum class PitchingResult;

class StatusPrinter {

public:
    StatusPrinter();
    ~StatusPrinter();

    /**
     * Print pitching result in hangul on console.
     *
     * @param strike Current Number of strike
     * @param ball Current Number of ball
     * @param pitchingResult Result of pitching. (please refer to pitchingresult.h)
     */
    void showPitchingResult(unsigned short strike,
                            unsigned short ball,
                            PitchingResult pitchingResult);

    /**
     * Print current score board on console.
     *
     * @param strikeCount Current number of Strike.
     * @param ballCount Current number of Ball.
     * @param outCount Current number of Out.
     */
    void showScoreBoard(unsigned short strikeCount,
                        unsigned short ballCount,
                        unsigned short outCount);

    /**
     * Print the next batter on console.
     */
    void showNextBatter();

    /**
     * Print game end comment on console.
     *
     * @param hitsCount Number of hits when the match ends.
     */
    void showGameEndComment(unsigned short hitsCount);

private:
    /**
     * Print announce when strike occurs on console.
     *
     * @param strikeCount Current number of Strike.
     * @param ballCount Current number of Ball.
     */
    void showStrikeOccurs(unsigned short strike,
                          unsigned short ball);

    /**
     * Print announce when ball occurs on console.
     *
     * @param strikeCount Current number of Strike.
     * @param ballCount Current number of Ball.
     */
    void showBallOccurs(unsigned short strike,
                        unsigned short ball);

    /**
     * Print announce when hits occurs on console.
     */
    void showHitsOccurs();

    /**
     * Print announce when out occurs on console.
     */
    void showOutOccurs();

    /**
     * Print out comment on console.
     */
    void showThreeStrikeOutOccursComment();

    /**
     * Print out comment on console.
     */
    void showFourBallHitsOccursComment();
};

#endif // STATUSPRINTER_H
