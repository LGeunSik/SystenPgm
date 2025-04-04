#include <stdio.h>

void printBinary(int num) {
    for (int i = 7; i >= 0; i--) {
        // 2의 i 제곱을 이용하여 각 비트를 출력
        printf("%d", (num >> i) & 1);
    }
}

int countOnes(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1; // 현재 비트가 1인지 확인
        num >>= 1;        // 오른쪽으로 비트 이동
    }
    return count;
}

int main() {
    int num;

    // 0~255 범위의 정수 입력받기
    printf("0부터 255까지의 정수를 입력하세요: ");
    scanf("%d", &num);

    // 유효성 검사
    if (num < 0 || num > 255) {
        printf("잘못된 입력입니다. 0~255 범위의 정수를 입력하세요.\n");
        return 1; // 프로그램 종료
    }

    // 2진수 출력
    printf("2진수: ");
    printBinary(num);
    printf("\n");

    // 1의 개수 출력
    int oneCount = countOnes(num);
    printf("1의 개수: %d\n", oneCount);

    // 상위 4비트 출력
    printf("상위 4비트: ");
    printBinary(num >> 4); // 상위 4비트를 오른쪽으로 이동하여 출력
    printf("\n");

    return 0;
}
