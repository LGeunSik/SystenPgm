10주차 내용입니다.


📘 시스템 프로그래밍 06강 요약<br>
📌 Chapter 1. I/O (Input/Output) 시스템 구조<br>
🔹 I/O 장치 (Devices)<br>
장치 컨트롤러: CPU와 I/O 장치 사이에서 신호를 주고받는 하드웨어<br>

장치 드라이버: OS 내부에서 각 장치를 제어하는 소프트웨어 모듈<br>

I/O 버스: CPU, 메모리, I/O 장치 간의 데이터 전송 경로<br>

🔹 데이터 전송 방식<br>
Programmed I/O (polling): CPU가 장치 상태를 계속 검사함 (비효율적)<br>

Interrupt-driven I/O: 장치가 완료되면 CPU에 인터럽트를 보냄 (효율적)<br>

DMA (Direct Memory Access): CPU 없이 데이터가 메모리로 직접 이동됨<br>

📌 Chapter 2. UNIX 시스템에서의 파일 입출력<br>
🔹 시스템 콜 함수들<br>
함수	설명
open()	파일을 열고 파일 디스크립터(fd)를 반환함
read()	fd로부터 데이터를 읽음
write()	fd에 데이터를 씀
lseek()	파일 내 위치(offset)를 이동함
close()	열린 파일을 닫음

c
복사
편집
int fd = open("file.txt", O_RDONLY);
read(fd, buf, size);
write(fd, buf, size);
lseek(fd, offset, SEEK_SET);
close(fd);
<br>
🔹 파일 디스크립터 (File Descriptor)<br>
UNIX 시스템에서 열린 파일마다 고유 번호를 할당<br>

표준 파일 디스크립터:

0: stdin

1: stdout

2: stderr<br>

📌 Chapter 3. 파일 복사 프로그램 예제<br>
🧪 예제 1: 기본적인 파일 복사
c
복사
편집
int src = open(argv[1], O_RDONLY);
int dst = open(argv[2], O_WRONLY | O_CREAT, 0644);
while ((n = read(src, buf, sizeof(buf))) > 0)
    write(dst, buf, n);
argv[1]은 입력 파일, argv[2]는 출력 파일<br>

read()와 write()를 통해 파일 내용을 복사<br>

O_CREAT: 파일이 없으면 생성<br>

📎 에러 처리 및 권한<br>
perror() 함수로 에러 메시지 출력 가능<br>

파일 생성 시 접근 권한을 명시 (예: 0644)<br>

📌 Chapter 4. 고급 파일 시스템 콜<br>
🔹 dup(), dup2()<br>
dup(fd): fd를 복제함 (가장 작은 사용 가능한 fd로)<br>

dup2(fd1, fd2): fd2에 fd1을 복제함 (기존 fd2를 먼저 닫음)<br>

c
복사
편집
dup2(fd, 1);  // 표준 출력(stdout)을 파일로 변경 가능
🔹 fcntl()<br>
파일 디스크립터 제어 함수<br>

예: fcntl(fd, F_SETFL, O_APPEND)은 파일에 항상 append 모드로 씀<br>

📌 Chapter 5. 파일 디스크립터 테이블<br>
각 프로세스는 자신만의 파일 디스크립터 테이블을 가짐<br>

이 테이블은 커널의 open file table과 연결됨<br>

이 구조 덕분에 fork 이후 부모와 자식이 같은 파일을 공유 가능<br>

📌 Chapter 6. 성능 및 버퍼<br>
🔹 시스템 콜 vs 라이브러리 함수<br>
시스템 콜	표준 입출력
read(), write()	fread(), fwrite()
버퍼링 없음	내부 버퍼링 있음 (성능 향상)

표준 라이브러리 함수는 큰 덩어리로 입출력을 처리하여 성능이 좋음<br>


📘 시스템 프로그래밍 07강 요약<br>
📁 파일 시스템 구조<br>
🔹 구성 요소
부트 블록(Boot Block): 부트스트랩 코드 저장, 파일 시스템 시작에 위치<br>

슈퍼 블록(Super Block): 파일 시스템 전체 정보 저장 (총 블록 수, 사용 가능한 i-node 수 등)<br>

i-리스트(i-list): 모든 i-node들의 리스트<br>

데이터 블록(Data Block): 실제 파일 데이터 저장 공간<br>

🧱 i-Node (아이노드)<br>
하나의 파일당 하나의 i-node 존재<br>

저장 정보:

파일 타입

크기

접근 권한

사용자/그룹 ID

접근/수정 시간

데이터 블록 주소 (포인터)<br>

🔹 블록 포인터 구조
직접 포인터: 10개<br>

간접 포인터: 1개<br>

이중 간접 포인터: 1개<br>

🛠️ 파일 입출력과 커널 구조<br>
🔹 관련 구조체
파일 디스크립터 배열 (Fd array): 각 프로세스가 하나씩 가짐<br>

열린 파일 테이블 (Open File Table): 모든 열린 파일의 상태 정보 저장<br>

동적 i-node 테이블: 열린 파일들의 i-node 정보 저장<br>

🗃️ 파일 상태 정보<br>
🔹 stat() 함수
c
복사
편집
int stat(const char *filename, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *filename, struct stat *buf);
파일 타입, 크기, 권한, 링크 수, 소유자 ID, 시간 정보 등을 조회<br>

🔹 파일 타입 판별 매크로
타입	매크로
일반파일	S_ISREG()
디렉터리	S_ISDIR()
문자 장치	S_ISCHR()
블록 장치	S_ISBLK()
FIFO	S_ISFIFO()
소켓	S_ISSOCK()
심볼릭 링크	S_ISLNK()

🔐 파일 권한 및 소유권<br>
🔹 권한 비트 (st_mode)
사용자/그룹/기타로 나뉘며, rwx 형태로 관리<br>

예: S_IRUSR, S_IWGRP, S_IXOTH 등<br>

🔹 권한 변경
c
복사
편집
int chmod(const char *path, mode_t mode);
int fchmod(int fd, mode_t mode);
🔹 소유자 변경
c
복사
편집
int chown(const char *path, uid_t owner, gid_t group);
⏱️ 시간 속성 변경: utime()<br>
파일의 마지막 접근/수정 시간 변경

c
복사
편집
int utime(const char *filename, const struct utimbuf *times);
📂 디렉터리 처리<br>
🔹 디렉터리 탐색 함수
c
복사
편집
DIR *opendir(const char *path);
struct dirent *readdir(DIR *dirp);
int closedir(DIR *dirp);
🔹 디렉터리 구조체
c
복사
편집
struct dirent {
  ino_t d_ino;
  char d_name[NAME_MAX + 1];
};
🔗 링크 (Link)<br>
🔹 하드 링크 vs 심볼릭 링크
구분	하드 링크	심볼릭 링크
동일 파일 시스템	가능	가능
다른 파일 시스템	불가	가능
삭제 시 영향	원본 유지	원본 삭제 시 링크 무효

🔹 관련 함수
c
복사
편집
int link(const char *existing, const char *new);
int unlink(const char *path);
int symlink(const char *actual, const char *sym);
int readlink(const char *path, char *buf, size_t bufsize);
🧾 핵심 요약<br>
파일 시스템은 부트 블록, 슈퍼 블록, i-노드, 데이터 블록으로 구성됨<br>

i-노드는 파일의 메타데이터를 포함하는 핵심 구조<br>

파일 I/O는 커널의 다양한 자료구조와 연결되어 처리됨<br>

디렉터리는 파일 이름과 i-노드 번호 쌍의 리스트<br>

링크를 통해 파일의 대체 경로를 생성할 수 있으며, 하드링크와 소프트링크는 특성이 다름<br>

📘 시스템 프로그래밍 07강 요약<br>
📁 파일 시스템 구조<br>
🔹 구성 요소
부트 블록(Boot Block): 부트스트랩 코드 저장, 파일 시스템 시작에 위치<br>

슈퍼 블록(Super Block): 파일 시스템 전체 정보 저장 (총 블록 수, 사용 가능한 i-node 수 등)<br>

i-리스트(i-list): 모든 i-node들의 리스트<br>

데이터 블록(Data Block): 실제 파일 데이터 저장 공간<br>

🧱 i-Node (아이노드)<br>
하나의 파일당 하나의 i-node 존재<br>

저장 정보:

파일 타입

크기

접근 권한

사용자/그룹 ID

접근/수정 시간

데이터 블록 주소 (포인터)<br>

🔹 블록 포인터 구조
직접 포인터: 10개<br>

간접 포인터: 1개<br>

이중 간접 포인터: 1개<br>

🛠️ 파일 입출력과 커널 구조<br>
🔹 관련 구조체
파일 디스크립터 배열 (Fd array): 각 프로세스가 하나씩 가짐<br>

열린 파일 테이블 (Open File Table): 모든 열린 파일의 상태 정보 저장<br>

동적 i-node 테이블: 열린 파일들의 i-node 정보 저장<br>

🗃️ 파일 상태 정보<br>
🔹 stat() 함수
c
복사
편집
int stat(const char *filename, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *filename, struct stat *buf);
파일 타입, 크기, 권한, 링크 수, 소유자 ID, 시간 정보 등을 조회<br>

🔹 파일 타입 판별 매크로
타입	매크로
일반파일	S_ISREG()
디렉터리	S_ISDIR()
문자 장치	S_ISCHR()
블록 장치	S_ISBLK()
FIFO	S_ISFIFO()
소켓	S_ISSOCK()
심볼릭 링크	S_ISLNK()

🔐 파일 권한 및 소유권<br>
🔹 권한 비트 (st_mode)
사용자/그룹/기타로 나뉘며, rwx 형태로 관리<br>

예: S_IRUSR, S_IWGRP, S_IXOTH 등<br>

🔹 권한 변경
c
복사
편집
int chmod(const char *path, mode_t mode);
int fchmod(int fd, mode_t mode);
🔹 소유자 변경
c
복사
편집
int chown(const char *path, uid_t owner, gid_t group);
⏱️ 시간 속성 변경: utime()<br>
파일의 마지막 접근/수정 시간 변경

c
복사
편집
int utime(const char *filename, const struct utimbuf *times);
📂 디렉터리 처리<br>
🔹 디렉터리 탐색 함수
c
복사
편집
DIR *opendir(const char *path);
struct dirent *readdir(DIR *dirp);
int closedir(DIR *dirp);
🔹 디렉터리 구조체
c
복사
편집
struct dirent {
  ino_t d_ino;
  char d_name[NAME_MAX + 1];
};
🔗 링크 (Link)<br>
🔹 하드 링크 vs 심볼릭 링크
구분	하드 링크	심볼릭 링크
동일 파일 시스템	가능	가능
다른 파일 시스템	불가	가능
삭제 시 영향	원본 유지	원본 삭제 시 링크 무효

🔹 관련 함수
c
복사
편집
int link(const char *existing, const char *new);
int unlink(const char *path);
int symlink(const char *actual, const char *sym);
int readlink(const char *path, char *buf, size_t bufsize);
🧾 핵심 요약<br>
파일 시스템은 부트 블록, 슈퍼 블록, i-노드, 데이터 블록으로 구성됨<br>

i-노드는 파일의 메타데이터를 포함하는 핵심 구조<br>

파일 I/O는 커널의 다양한 자료구조와 연결되어 처리됨<br>

디렉터리는 파일 이름과 i-노드 번호 쌍의 리스트<br>

링크를 통해 파일의 대체 경로를 생성할 수 있으며, 하드링크와 소프트링크는 특성이 다름<br>


