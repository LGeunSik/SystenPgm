// wait.c - 자식 프로세스를 생성하고 부모는 wait로 대기
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();  // 자식 프로세스 생성

    if (pid < 0) {
        perror("❌ fork 실패");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스
        printf("👶 자식 프로세스 시작 (PID: %d)\n", getpid());
        sleep(3);  // 3초 후 종료
        printf("👶 자식 프로세스 종료\n");
        return 42;  // 종료 코드
    } else {
        // 부모 프로세스
        printf("👨 부모 프로세스 (PID: %d), 자식 PID: %d\n", getpid(), pid);
        wait(&status);  // 자식 종료까지 대기

        if (WIFEXITED(status)) {
            printf("✅ 자식이 종료되었습니다. 반환 코드: %d\n", WEXITSTATUS(status));
        } else {
            printf("❌ 자식 프로세스 비정상 종료\n");
        }
    }

    return 0;
}
