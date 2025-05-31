// kill.c - 지정한 PID에 시그널 전송 (기본 SIGTERM, 선택 SIGKILL 등)
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main() {
    int pid;
    int sig = SIGTERM;  // 기본 시그널은 SIGTERM(15)

    printf("종료할 프로세스의 PID를 입력하세요: ");
    scanf("%d", &pid);

    char choice;
    printf("SIGKILL(강제종료: -9)로 종료할까요? (y/n): ");
    scanf(" %c", &choice);  // 공백 포함해 입력 버퍼 초기화

    if (choice == 'y' || choice == 'Y') {
        sig = SIGKILL;
    }

    // 시그널 전송
    if (kill(pid, sig) == 0) {
        printf("✔ PID %d 프로세스에 시그널(%d) 전송 성공\n", pid, sig);
    } else {
        perror("❌ 시그널 전송 실패");  // 권한 없음, 존재하지 않는 PID 등
        return 1;
    }

    return 0;
}
