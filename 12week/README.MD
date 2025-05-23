12주차 입니다.
주요개념 <BR>
fork() -> 자기 복제임
부모는 자식의 PID를 리턴받음 (0보다 큼)

자식은 0을 리턴받는다

🧩 Chapter 9: 프로세스 제어 요약<br>
✅ 9.1 프로세스 생성<br>
fork() 시스템 호출을 통해 부모 프로세스가 자식 프로세스를 생성함<br>

자식은 0을, 부모는 자식의 PID를 리턴받음 → 리턴값으로 부모/자식 구분 가능<br>

fork()는 자기복제(自己複製) 방식으로 동작하며, 부모-자식은 병행 실행됨<br>

c
복사
편집
pid = fork();
if (pid == 0) { /* 자식 코드 */ }
else { /* 부모 코드 */ }
fork()를 2번 호출하면 최대 4개의 프로세스가 생성됨 (2ⁿ 방식)<br>

✅ 9.2 프로세스 기다리기<br>
wait() 또는 waitpid()로 자식 프로세스의 종료를 대기할 수 있음<br>

wait(&status)는 아무 자식이나 하나 종료될 때까지 대기<br>

waitpid(pid, &status, 0)은 지정된 자식(pid)의 종료를 대기<br>

종료된 자식의 종료 코드는 status >> 8 또는 WEXITSTATUS(status)로 확인 가능<br>

✅ 9.3 프로그램 실행 (exec)<br>
exec() 계열 함수로 현재 프로세스를 다른 프로그램으로 대체함<br>

fork() 후 자식에서 exec() 호출 → 새로운 프로그램 실행<br>

exec()는 성공 시 리턴하지 않으며, 실패 시 -1 리턴<br>

c
복사
편집
execl("/bin/ls", "ls", "-l", NULL);
execvp(argv[1], &argv[1])로 명령줄 인수로 받은 명령 실행 가능<br>

✅ 9.4 system() 함수<br>
system("명령어")는 내부적으로 fork() + exec() + waitpid() 조합<br>

/bin/sh -c "명령어"를 실행함<br>

종료 코드는 WEXITSTATUS(status)로 확인<br>

c
복사
편집
int status = system("date");
✅ 9.5 입출력 재지정<br>
dup2(fd, 1)를 사용해 파일을 표준 출력(1)으로 리디렉션할 수 있음<br>

명령어의 출력 결과를 파일로 저장 가능<br>

c
복사
편집
fd = open("out.txt", O_WRONLY|O_CREAT|O_TRUNC, 0600);
dup2(fd, 1);  // stdout을 out.txt로
✅ 9.6 프로세스 그룹<br>
프로세스 그룹은 여러 프로세스의 집합이며, 리더는 자신의 PID와 GID가 같음<br>

getpgrp()로 그룹 ID 확인, setpgid(pid, pgid)로 그룹 설정<br>

c
복사
편집
setpgid(0, 0);  // 자신의 프로세스를 새로운 그룹 리더로 만듦
kill -pid, kill 0, kill -9 -pid 등을 통해 그룹 전체에 시그널 전송 가능<br>

✅ 9.7 시스템 부팅<br>
시스템 부팅 시 fork/exec 호출을 통해 주요 프로세스가 실행됨<br>

프로세스	역할
swapper	커널 내부의 스케줄러 역할
init	/etc/inittab에 따라 시스템 초기화
getty	로그인 프롬프트 제공
login	사용자 인증 수행
shell	명령어 대기 및 실행 처리

🧠 핵심 요약<br>
fork()로 프로세스를 복제하고, exec()로 다른 프로그램으로 교체할 수 있음<br>

wait()/waitpid()로 자식의 종료를 감지하고 처리 가능<br>

dup2()로 출력 리디렉션 구현, system()은 간단한 명령 실행에 사용됨<br>

프로세스 그룹은 시그널 관리와 관련 있으며, 시스템 부팅도 fork/exec 기반으로 진행됨<br>
