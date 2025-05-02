9주차 내용입니다.
오늘의 주제 시스템 호출(system call)


📘 시스템 프로그래밍 05주차 요약<br>
📌 Chapter 5. 프로세스 (Process)<br>
🔹 프로세스란?<br>
실행 중인 프로그램 (A program in execution)<br>

운영체제로부터 자원(CPU, 메모리 등)을 할당받아 동작<br>

정적인 프로그램(program)과 동적인 프로세스(process)는 구분됨<br>

하나의 프로그램이 여러 프로세스로 실행될 수 있음<br>

🔹 프로세스의 구조<br>
텍스트 영역 (Text Segment)<br>

프로그램의 실행 코드가 저장됨<br>

데이터 영역 (Data Segment)<br>

초기화된 전역 변수와 static 변수 저장<br>

BSS 영역 (Block Started by Symbol)<br>

초기화되지 않은 전역 변수와 static 변수<br>

힙 (Heap)<br>

동적 메모리 할당 영역 (e.g., malloc)<br>

위로 성장함<br>

스택 (Stack)<br>

함수 호출 시 지역 변수, 매개변수, 반환 주소 등 저장<br>

아래로 성장함<br>

🔹 프로세스 상태<br>
New: 생성 중<br>

Ready: CPU 할당 대기 중<br>

Running: 실행 중<br>

Waiting (Blocked): 입출력 등 이벤트 대기<br>

Terminated: 실행 종료<br>

→ 이 상태들은 **상태 전이(state transition)**를 통해 변화함<br>

🔹 프로세스 제어 블록 (PCB, Process Control Block)<br>
운영체제가 프로세스를 관리하기 위해 사용하는 데이터 구조<br>

포함 정보:<br>

프로세스 상태<br>

프로그램 카운터 (PC)<br>

CPU 레지스터 정보<br>

메모리 관리 정보<br>

입출력 상태 정보<br>

프로세스 식별자 (PID)<br>

🔹 프로세스 생성과 종료<br>
프로세스 생성: fork() 시스템 호출<br>

부모 프로세스가 자신을 복제해 자식 프로세스를 생성<br>

자식은 독립적 주소 공간을 가짐<br>

반환값: 부모는 자식의 PID, 자식은 0<br>

프로세스 종료: exit() 함수<br>

종료 상태 코드를 반환함<br>

부모 프로세스는 wait() 함수로 자식의 종료를 감지함<br>

🔹 fork() 함수 예제<br>
c
복사
편집
pid_t pid = fork();
if (pid == 0) {
    // 자식 프로세스
} else if (pid > 0) {
    // 부모 프로세스
} else {
    // fork 실패
}
fork() 이후 부모와 자식은 동일한 코드 수행<br>

반환값을 이용해 구분하여 로직 작성 가능<br>

🔹 exec 계열 함수<br>
현재 프로세스를 새로운 프로그램으로 덮어씀<br>

종류: execl, execp, execv, execvp 등<br>

fork() + exec() 조합은 새로운 프로그램 실행의 일반적인 방식<br>

🔹 wait() 함수<br>
부모 프로세스가 자식 프로세스 종료를 기다림<br>

반환값: 종료된 자식의 PID<br>

자식이 먼저 종료되면 **좀비 프로세스(zombie)**가 생기며, wait()을 통해 제거됨<br>

📌 핵심 요약 포인트<br>
프로세스는 실행 중인 프로그램으로, 고유의 메모리 공간을 가짐<br>

fork()로 자식을 만들고, exec()로 새로운 프로그램 실행 가능<br>

wait()로 자식 종료를 감지하고, exit()로 프로세스를 정상 종료<br>

PCB는 프로세스 관리를 위한 핵심 자료 구조<br>

