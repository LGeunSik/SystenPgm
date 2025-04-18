7주차 강의 입니다.
Important
프로그램을 열시
출력장치 / 입력장치/ 저장장치

실제 사용자
유저 사용자

set user-ID
유효 사용자 ID는 그 실행 파일의 소유자로 바뀜

kill 명령어
외부에서 그 프로세스를 제거 시킬수있다.

7장

안전한 원격 접속 SSh

9장
cron
 cron 시스템
 유닉스의 명령어 스케줄링 시스템으로
 crontab 파일에 명시된 대로 주기적으로 명령을 수행한다.
 crontab 파일 등록법
 crontab 파일
 7개의 필드로 구성
 분 시 일 월 요일 [사용자] 명령

10장
bash 문법

!! 바로전 명령 실행
!n 이벤트 번호가 n인 명령 재실행

cat/ gcc -o hello hello.c
등 파일을 누가 실행시키는가 -> 셀
사용자가 어떤 일을 할때 도와주고 도구를 제공하는 비서같은 -> 셀

cdmod

11장

gcc 


🧠 6장 프로세스 요약
📌 6.1 프로세스란?
프로세스(Process): 실행 중인 프로그램

PID: 프로세스 고유 ID

부모 프로세스: 프로세스는 부모에 의해 생성됨

🔸 프로세스 종류
시스템 프로세스: 데몬 등 시스템 운영용

사용자 프로세스: 사용자가 실행한 프로그램

📋 프로세스 상태 보기

ps 명령어

ps

ps -f

ps -ef | more

항목	설명

UID	사용자 ID

PID	프로세스 ID

PPID	부모 프로세스 ID

C	우선순위


STIME	시작 시간

TTY	터미널

TIME	CPU 시간

CMD	명령어 이름

🔎 특정 프로세스 검색: pgrep

pgrep sshd

pgrep -l sshd    # 이름과 PID

pgrep -


🔎 특정 프로세스 검색: pgrep<br>

pgrep sshd

pgrep -l sshd       # PID와 이름
pgrep -ln sshd      # 가장 최근 프로세스
주요 옵션<br>

-l: PID와 이름 함께 출력<br>

-f: 경로까지 출력<br>

-n: 가장 최근 프로세스만 출력<br>

-x: 정확히 일치하는 프로세스만 출력<br>

-a: 전체 명령줄과 PID 출력<br>

<br>
🛠️ 6.2 작업 제어<br>
⚙️ 후면 처리<br>
bash
복사
편집
명령어 &
프로세스를 백그라운드에서 실행<br>

예: sleep 10 &<br>

💤 쉘 재우기<br>
bash
복사
편집
sleep 초
지정한 시간 동안 쉘을 멈춤<br>

예: (echo 시작; sleep 5; echo 끝)<br>

⛔ 강제 종료<br>
Ctrl-C: 현재 실행 중인 프로세스를 강제 종료<br>

Ctrl-Z: 현재 실행 중인 프로세스를 일시 정지<br>

🔄 전환 명령어<br>
fg: 중지된 작업을 전면으로<br>

bg: 중지된 작업을 후면으로 전환<br>

📤 후면 입출력<br>
출력 리다이렉션: 명령어 > 출력파일 &<br>

입력 리다이렉션: 명령어 < 입력파일 &<br>

<br>
🔚 6.3 프로세스 제어<br>
🔪 종료: kill 명령어<br>
bash
복사
편집
kill PID
kill %작업번호
kill -9 PID        # SIGKILL
kill -STOP PID     # 정지
kill -CONT PID     # 계속
프로세스를 종료하거나 시그널을 보냄<br>

⏳ 기다리기: wait 명령어<br>
bash
복사
편집
wait PID
wait
지정한 PID의 종료를 기다림<br>

인수가 없으면 모든 자식 프로세스 종료 대기<br>

🔼 우선순위: nice, renice<br>
bash
복사
편집
nice -n 10 명령어
renice -n 5 -p PID
우선순위는 -20(높음) ~ 19(낮음)<br>

실행 중인 프로세스의 우선순위 변경<br>

<br>
👤 6.4 사용자 ID와 그룹 ID<br>
실제 사용자 ID: 프로세스를 실행시킨 사용자의 ID<br>

유효 사용자 ID: 실제 권한을 판별하는 데 사용됨<br>

bash
복사
편집
id       # 현재 사용자 정보
echo $UID $EUID
📛 set-user-id, set-group-id<br>
set-user-id가 설정된 파일을 실행하면 UID가 파일 소유자로 변경<br>

예: /bin/passwd 는 root UID를 가짐<br>

bash
복사
편집
chmod 4755 파일     # set-user-id 설정
chmod 2755 파일     # set-group-id 설정
<br>
⚡ 6.5 시그널과 프로세스<br>
시그널은 소프트웨어 인터럽트로 프로세스를 제어함<br>

예: SIGINT, SIGKILL, SIGTSTP 등<br>

주요 시그널<br>
시그널	의미	기본 처리

SIGINT	Ctrl-C로 종료 요청	종료

SIGKILL	종료 불가능한 강제 종료	종료

SIGTSTP	Ctrl-Z로 중지 요청	정지

SIGTERM	일반적인 종료 요청	종료

SIGCHLD	자식 프로세스 종료 통지	무시

bash

복사

편집

kill -l             # 시그널 리스트 출력

kill -9 PID         # SIGKILL 시그널 전송

kill -STOP PID      # 일시 정지

kill -CONT PID      # 재개

<br>






