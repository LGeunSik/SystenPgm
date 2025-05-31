// date.c
#include <stdio.h>
#include <time.h>

int main() {
    time_t t;
    struct tm *tm_info;

    time(&t);  // 현재 시간 얻기
    tm_info = localtime(&t);  // 지역 시간으로 변환

    printf("현재 날짜 및 시간: %s", asctime(tm_info));  // 문자열 형태로 출력
    return 0;
}
