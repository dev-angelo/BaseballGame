#ifndef BASEBALLGAMEMANAGER_H
#define BASEBALLGAMEMANAGER_H

class PitchingResultGenerator;
class ScoreBoard;
class OfficialScorer;
class StatusPrinter;
class BaseballTeam;

class BaseballGameManager
{

public:
    BaseballGameManager();
    ~BaseballGameManager();

    /**
     * It is called for starting Baseball Game.
     */
    void run();

private:
    PitchingResultGenerator *m_pPitchingResultGenerator;
    ScoreBoard *m_pScoreBoard;
    OfficialScorer *m_pOfficialScorer;
    StatusPrinter *m_pStatusPrinter;

    BaseballTeam *m_pHomeTeam;
    BaseballTeam *m_pAwayTeam;

    BaseballTeam *m_pCurrentAttackTeam;

    /**
     * Play one inning.
     *
     */
    void playInning(BaseballTeam* pBaseballTeam);

    /**
     * Determine whether the game is finished through outCount.
     *
     * @param outCount Number of out.
     * @return finished (true) or not finished (false).
     */
    bool isGameEnd(const unsigned short outCount) const;

    /**
     * Show baseball game menu.
     */
    void showMenu();

    /**
     * Receive user's menu select input.
     */
    unsigned short receiveUserMenuSelect() const;

    /**
     * Perform the menu selected by user.
     */
    void performUserMenuSelection(const unsigned short userInput);

    void performInputTeamData();
    void performShowTeamData();

    bool checkUserMenuSelectionAvailable(const unsigned short userInput) const;

    void startGame();
    bool playAttack(const double battingAverage) const;
}
;

#endif // BASEBALLGAMEMANAGER_H
