3주차 시스템프로그램이 강의 입니다.
##디렉터리 내용 확인

```bash
$ whoami
chang
$ who
chang tty2 2022-01-09 12:19 (tty2)
$ ls
공개
다운로드
문서
바탕화면
비디오
사진
음악
템플릿

# 디렉터리 생성: `mkdir`

## 중간 디렉터리 자동 생성 옵션 `-p`

- `-p` 옵션을 사용하면 필요한 경우 중간 디렉터리를 자동으로 생성해줍니다.

## 예시

`~/dest` 디렉터리가 없는 경우:

```bash
$ mkdir ~/dest/dir1
mkdir: '/home/chang/dest/dir1' 디렉터리를 만들 수 없습니다: 그런 파일이나 디렉터리가 없습니다
디렉터리 삭제 : rmdir(remove directory)
20
 사용법
 주의: 빈 디렉토리만 삭제할 수 있다.
 예
$ rmdir test
rmdir: failed to remove ‘test’: 디렉터리가 비어있지 않음
$ rmdir 디렉터리+
디렉터리(들)을 삭제한다.

# 📄 간단한 파일 만들기: `touch`

## 📌 사용법

`touch` 명령어를 사용하여 **빈 파일**을 간단하게 생성할 수 있습니다.

- 파일 크기는 `0`이며, **파일 이름만 존재하는 빈 파일**이 만들어집니다.

---

## 📝 예시

```bash
$ touch cs1.txt
$ ls -asl cs1.txt
0 -rw-rw-r--. 1 chang chang 0 5월  9 15:10 cs1.txt

# 📂 파일 내용 보기: `cat`

## 📌 사용법

`cat` 명령어는 **파일의 내용을 그대로 화면에 출력**합니다.

- 파일을 지정하지 않으면 **표준 입력**을 통해 입력받은 내용을 출력합니다.
- `-n` 옵션을 사용하면 **라인 번호**를 함께 출력할 수 있습니다.

---

## 📝 예시

### 기본 사용법

```bash
$ cat cs1.txt
Unix is a multitasking, multi-user computer operating system originally
developed in 1969 by a group of AT&T employees at Bell Labs, including
Ken Thompson, Dennis Ritchie, Brian Kernighan, Douglas McIlroy,
and Joe Ossanna.

