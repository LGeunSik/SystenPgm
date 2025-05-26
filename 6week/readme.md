6주차 내용입니다.
📘 6장 프로세스 요약<br>
🧠 6.1 프로세스<br>
프로세스(Process): 실행 중인 프로그램<br>

PID: 프로세스 번호는 고유함<br>

부모 프로세스: 다른 프로세스에 의해 생성됨<br>

프로세스 종류:

시스템 프로세스: 데몬 등 부팅 시 생성<br>

사용자 프로세스: 사용자의 명령에 의해 생성<br>

🔍 ps 명령어<br>
현재 시스템의 프로세스 상태 출력<br>

ps -ef: 전체 프로세스 정보 확인<br>

주요 항목:

UID, PID, PPID, STIME, CMD 등<br>

🔍 pgrep 명령어<br>
특정 프로세스만 리스트<br>

pgrep -l sshd: PID + 이름<br>

pgrep -n sshd: 가장 최근 실행된 sshd 출력<br>

🧭 6.2 작업 제어<br>
▶️ 후면 실행<br>
명령어 &: 명령어를 백그라운드에서 실행<br>

sleep 10 & → 즉시 쉘에 제어권 반환<br>

⏸️ 쉘 재우기<br>
sleep 초: 지정 시간 동안 쉘 대기<br>

❌ 프로세스 종료<br>
Ctrl-C: 강제 종료 (SIGINT)<br>

Ctrl-Z: 일시 중지 (SIGTSTP)<br>

🔁 전환 명령어<br>
fg: 후면 작업을 전면으로<br>

bg: 중지된 작업을 후면에서 계속 실행<br>

🛠️ 6.3 프로세스 제어<br>
🔫 kill 명령어<br>
프로세스를 종료하는 명령<br>

kill PID 또는 kill %작업번호<br>

⏳ wait 명령어<br>
자식 프로세스가 종료될 때까지 대기<br>

wait PID 또는 wait (모든 자식 기다림)<br>

⚖️ 우선순위 조정<br>
nice: 프로세스 시작 시 우선순위 조정<br>

renice: 실행 중인 프로세스의 우선순위 변경<br>

👤 6.4 사용자 ID<br>
real UID: 로그인한 사용자 ID<br>

effective UID: 권한 판단에 사용됨<br>

🔐 Set-User-ID<br>
실행 파일에 setuid 설정 시, 실행자는 소유자 권한으로 실행됨<br>

예: /bin/passwd → root 권한으로 실행됨<br>

bash
복사
편집
chmod u+s 파일  # setuid
chmod g+s 파일  # setgid
📡 6.5 시그널과 프로세스<br>
시그널: 소프트웨어 인터럽트 (예기치 않은 사건 알림)<br>

📋 주요 시그널<br>
시그널	의미	기본 처리
SIGINT	Ctrl-C	종료
SIGKILL	강제 종료	종료
SIGTSTP	Ctrl-Z	정지
SIGSEGV	잘못된 메모리 참조	종료(코어덤프)
SIGCHLD	자식 종료 알림	무시
SIGALRM	알람 시계	종료

🧨 시그널 보내기
bash
복사
편집
kill -9 PID         # SIGKILL
kill -STOP PID      # 정지
kill -CONT PID      # 계속 실행
✅ 핵심 정리<br>
프로세스는 실행 중인 프로그램이며 PID를 가짐<br>

쉘은 사용자와 운영체제 사이의 인터페이스<br>

전면 ↔ 후면 작업 제어는 fg/bg로 조절<br>

각 프로세스는 사용자 ID(UID)와 유효 UID를 가짐<br>

setuid, setgid 설정으로 권한 제어 가능<br>

kill로 시그널을 보내 프로세스를 제어할 수 있음<br>
