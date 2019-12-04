# BaseballGame
BaseballGame Repository 는 CodeSquard 의 마스터즈 코스 온라인 테스를 위한 저장소입니다.</br>
step-2 Branch 는 step-1 에 이어 야구게임 만들기 2단계에 해당하는 *step-2* 에 대한 요구사항을 구현 한 브랜치 입니다.  
## 추가 된 Class 설명
### BaseballTeam Class
팀 번호/팀 명/멤버 명/멤버의 타율을 저장하고 있는 class 이다.  
해당 class 는 아래와 같은 function 이 정의되어 있다.
* 사용자로부터 팀 이름/팀원 정보(팀원 이름, 타율) 입력
```c++
void BaseballTeam::inputTeamData()
```
* 팀 정보 (팀 이름/팀원 정보) 출력
```c++
void BaseballTeam::showTeamData()
```
* 팀명 반환
```c++
std::string BaseballTeam::getName() const
```
* 특정 팀원의 타율 반환
```c++
double BaseballTeam::getMemberBattingAverage(const unsigned short memberIndex) const
```
* 특정 팀원의 이름 반환
```c++
std::string BaseballTeam::getMemberName(const unsigned short memberIndex) const
```
## 내용이 추가되거나 변경된 Class 설명
### BaseballManager class
#### 사용자에게 메뉴 출력 및 선택 기능 추가
```c++
void BaseballGameManager::showMenu() 
// 사용자에게 선택 할 수 있는 항목을 출력하는 함수.
```
```c++
unsigned short BaseballGameManager::receiveUserMenuSelect() const 
// Console 을 통해 사용자에게 입력을 받는 함수. 
```
```c++
bool BaseballGameManager::checkUserMenuSelectionAvailable(const unsigned short userInput) const
// 사용자의 입력에 대한 에러 여부를 반환하는 함수.
// Caller 는 반환값이 true 가 될 때 까지 재 호출한다.
```
#### 사용자의 선택에 따라 기능을 수행하는 함수 추가.
```c++
void performUserMenuSelection(const unsigned short userInput);
```
#### 동작 Flow 수정.
* step-1 에서는 게임 시작 후 3 아웃에 게임이 종료 되었으나 6회말까지 진행되도록 수정.
* step-1 에서는 다음 타자 등장 시 '다음 타자가 등장하였습니다' 문구였으나 step-2 에서는 StatusPrinter 에 추가 된  
void showAttackTeam(const std::string teamName), void showInningTopBottom(const unsigned short inning)  
함수 및 변경된 void showAttackTeam(const std::string teamName) 를 호출을 통해 요구사항 충족하도록 변경.
### StatusPrinter class
#### showAttackTeam, showInningTopBottom 함수 추가 및 showBatterEnter 함수 수정
```c++
void StatusPrinter::showAttackTeam(const std::string teamName)
//'코드스쿼드 공격' 을 출력하는 함수
```
```c++
void StatusPrinter::showInningTopBottom(const unsigned short inning)
//현재의 x회, 초/말 을 출력하는 함수
```
```c++
void StatusPrinter::showBatterEnter(const unsigned short batterNumber, const std::string batterName)
//'x번, 마우스' 와 같이 타석에 들어선 멤버를 출력하는 함수.
```
### ScoreBoard
####각 팀의 점수를 관리하기 위한 member 및 function 들의 추가.
```c++
unsigned short ScoreBoard::getScore(const bool isHomeTeam) const
//홈 or 원정팀의 점수를 얻어오기 위한 함수.
```
```c++
void ScoreBoard::setScore(const unsigned short score, const bool isHomeTeam)
//홈 or 원정팀의 점수를 설정하기 위한 함수.
```

### OfficialScorer
#### Hits (안타), Ball 발생 시 한 회에 4 안타시 1점 증가 및 이후 안타는 1점씩 추가되는 로직 추가
OfficialScorer::calculateHitOccurs() 및 OfficialScorer::calculateBallOccurs() 로직 수정.
