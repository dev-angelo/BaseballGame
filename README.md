# BaseballGame
BaseballGame Repository 는 CodeSquard 의 마스터즈 코스 온라인 테스를 위한 저장소입니다.</br>
step-3 Branch 는 step-1,step-2 에 이어 야구게임 만들기 3단계에 해당하는 *step-3* 에 대한 요구사항을 구현 한 브랜치 입니다.  
## 내용이 추가되거나 변경된 Class 설명
### ScoreBoard class
* 투구수/삼진/각 회차별 점수 기록을 저장하는 멤버 추가
```c++
void setTeamPitchingCount(const unsigned short pitchingCount, const bool isHomeTeam);
//홈/원정 팀의 투구수를 저장하기 위한 함수.
```
```c++
void setTeamThreeStrikeCount(const unsigned short threeStrikeCount, const bool isHomeTeam);
//홈/원정 팀의 삼진수를 저장하기 위한 함수.
```
```c++
void setTeamHitsCount(const unsigned short hitsCount, const bool isHomeTeam);
//홈/원정 팀의 안타수를 저장하기 위한 함수
```
```c++
unsigned short getTeamPitchingCount(const bool isHomeTeam) const;
//홈/원정 팀의 투구수를 얻어오기 위한 함수
```
```c++
unsigned short getTeamThreeStrikeCount(const bool isHomeTeam) const;
//홈/원정 팀의 삼진수를 얻어오기 위한 함수.
```
```c++
unsigned short getTeamHitsCount(const bool isHomeTeam) const;
//홈/원정 팀의 안타수를 얻어오기 위한 함수.
```
* 전광판 UI 를 표시하는 기능 추가
```c++
void ScoreBoard::showScoreBoard(const unsigned short currentInning,
                                const unsigned short currentBatterIndex)
//전광판 UI 를 표시하는 기능을 하는 함수.
```
### BaseballManager class
* Skip 이닝을 설정하기 위한 Get/Set 함수
```c++
void BaseballGameManager::setSkipInning(const unsigned short skipInning)
```
```c++
unsigned short BaseballGameManager::getSkipInning() const
```
위의 getSkipInning 은 BaseballManager::playInning() 함수 내에서 아래와 같이 skip 유무 기준으로 작용된다.
```
while ( false == isInningEnd(m_pScoreBoard->getOutCount()) ) {
    if ( ( getSkipInning() * 2 - 1 < nCurrentInning) &&(m_pScoreBoard->getTeamPitchingCount(true) != 0))
        receiveUserMenuSelectInGame(nCurrentInning);

    bEndTheAtBat = playAttack(nCurrentInning, nCurrentBatterIndex);

    if ( true == bEndTheAtBat )
        nCurrentBatterIndex = (nCurrentBatterIndex + 1) % 9;
}
```
* 사용자로부터 투구마다 Skip 유무를 결정하도록 하는 기능.
```c++
void BaseballGameManager::receiveUserMenuSelectInGame(const unsigned short nCurrentInning)
//이 함수 사용자로부터 입력을 받으며 그냥 enter 시는 스킵 미 적용, 숫자 입력 후 엔터시에는 숫자에 해당하는 회 말까지 스킵이 된다.
//사용자의 잘못된 입력에 대한 예외처리도 구현.
```
