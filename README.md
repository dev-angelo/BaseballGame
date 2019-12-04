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
