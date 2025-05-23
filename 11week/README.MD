11주차 내용입니다.
📁 Chapter 7: 파일 및 레코드 잠금 요약<br>
✅ 7.1 파일 잠금 (File Lock)<br>
여러 프로세스가 동일한 파일에 접근하면 데이터 충돌이 발생할 수 있음<br>

파일/레코드 잠금을 사용하면 동시에 접근하지 못하도록 막아 데이터 정합성을 유지할 수 있음<br>

🔒 잠금 예시<br>
잠금 없음	잠금 있음
A와 B가 동시에 잔액 100만 원을 읽고 입금 처리 → 데이터 충돌	A가 잠금 후 입금 처리 → B는 A가 끝날 때까지 대기 → 정합성 유지

✅ flock() 함수<br>
파일 전체 잠금을 설정하는 시스템 호출<br>

헤더: <sys/file.h> 필요<br>

사용법: int flock(int fd, int operation);<br>

🛠️ flock()의 operation 종류<br>
매크로	의미
LOCK_SH	공유 잠금 (다중 읽기 가능)
LOCK_EX	배타 잠금 (단일 접근)
LOCK_UN	잠금 해제
LOCK_NB	비차단 잠금 (잠김 상태면 즉시 실패)

✅ 7.2 레코드 잠금 (Record Lock)<br>
파일 전체가 아닌 특정 바이트 범위에 잠금을 설정<br>

fcntl() 시스템 호출을 사용하여 구현<br>

🔧 fcntl() 구조체<br>
c
복사
편집
struct flock {
  short l_type;    // 잠금 타입 (읽기, 쓰기, 해제)
  short l_whence;  // 기준 위치 (SEEK_SET 등)
  off_t l_start;   // 시작 위치
  off_t l_len;     // 길이 (0은 끝까지)
  pid_t l_pid;     // 프로세스 ID
};
⚙️ fcntl() 호출 방식<br>
c
복사
편집
fcntl(fd, F_SETLK, &fl);   // 비차단 잠금 설정<br>
fcntl(fd, F_SETLKW, &fl);  // 차단 잠금 설정 (대기)<br>
✅ 레코드 잠금의 장점<br>
파일의 특정 영역만 잠글 수 있어 병렬 접근 가능성 증가<br>

다중 프로세스 환경에서 정교한 동시성 제어 가능<br>

🧠 Chapter 8: 프로세스 요약<br>
✅ 8.1 쉘과 프로세스<br>
쉘(Shell): 사용자와 운영체제 사이에서 명령어를 받아 처리하는 명령어 처리기(command processor)<br>

명령어를 입력하면 쉘이 이를 전면 처리하거나 후면 처리할 수 있음<br>

🔹 전면 처리 vs 후면 처리<br>
전면 처리: 실행이 끝날 때까지 쉘이 대기<br>

후면 처리: 명령어 끝에 &를 붙여 백그라운드에서 실행<br>

bash
복사
편집
$ (sleep 100; echo done) &
$ jobs         # 백그라운드 작업 확인
$ fg %1        # 작업 번호로 포그라운드 복귀
✅ 8.2 프로그램 실행<br>
프로세스(process): 실행 중인 프로그램<br>

각 프로세스는 고유한 PID(Process ID)를 가짐<br>

🔹 프로그램 실행 구조<br>
exec()를 통해 프로그램 실행<br>

main() 함수가 argc, argv를 통해 명령줄 인수를 받음<br>

환경 변수는 environ 또는 getenv()로 접근 가능<br>

c
복사
편집
int main(int argc, char *argv[]) {
    printf("argv[0]: %s\n", argv[0]);
}
✅ 8.3 프로그램 종료<br>
🔸 종료 방식<br>
정상 종료: main() 함수 리턴 or exit() 호출<br>

비정상 종료: abort(), 시그널 등<br>

🔸 exit vs _exit<br>
함수	설명
exit()	출력 버퍼 비우기, 스트림 닫기 등 정리 수행 후 종료
_exit()	정리 없이 즉시 종료

🔸 exit 처리기 (atexit)<br>
c
복사
편집
atexit(handler);
exit()가 호출되면 등록된 처리기들이 역순으로 실행됨<br>

✅ 8.4 프로세스 ID & 사용자 ID<br>
🔸 프로세스 ID<br>
getpid(): 현재 프로세스 ID 반환<br>

getppid(): 부모 프로세스 ID 반환<br>

🔸 사용자/그룹 ID<br>
함수	설명
getuid()	실제 사용자 ID
geteuid()	유효 사용자 ID
getgid()	실제 그룹 ID
getegid()	유효 그룹 ID

🔸 set-user-ID (SUID)<br>
passwd 명령처럼 일반 사용자도 root 권한 필요 작업을 수행 가능<br>

실행파일에 s 비트 설정: chmod 4755 file<br>

✅ 8.5 프로세스 이미지<br>
🔹 프로세스 구조<br>
영역	설명
텍스트(text)	실행 코드 영역
데이터(data)	전역 및 정적 변수
힙(heap)	동적 메모리 할당 영역 (malloc)
스택(stack)	함수 호출 스택
U-영역	열린 파일, 작업 디렉토리 등 정보

🧩 핵심 개념 정리<br>
쉘은 명령어를 입력받아 실행시키는 소프트웨어<br>

프로세스는 실행 중인 프로그램이고, PID를 가진다<br>

사용자 ID는 실제/유효로 구분되며, 권한 제어에 사용된다<br>

exit()는 정리 후 종료, _exit()는 즉시 종료한다<br>

프로세스는 코드, 데이터, 힙, 스택으로 구성된 이미지 구조를 갖는다<br>
