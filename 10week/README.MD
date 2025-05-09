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
