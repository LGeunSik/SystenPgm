// tee.c - 표준 입력을 읽어 화면과 파일에 동시에 출력
#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[256];
    
    // 출력 파일명 입력
    printf("저장할 파일명을 입력하세요: ");
    scanf("%s", filename);

    // 파일 쓰기 모드로 열기
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    // 입력 버퍼를 비우고 표준 입력 재개
    getchar(); // 이전 scanf의 개행 제거

    char buffer[1024];

    // 표준 입력에서 한 줄씩 읽음
    while (fgets(buffer, sizeof(buffer), stdin)) {
        // 화면에 출력
        printf("%s", buffer);

        // 파일에 저장
        fputs(buffer, fp);
    }

    fclose(fp);
    printf("✔ 입력이 파일과 화면에 모두 출력되었습니다.\n");
    return 0;
}
