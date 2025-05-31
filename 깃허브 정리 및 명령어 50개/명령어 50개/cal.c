// cal.c
#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int days, i;

    // 각 월의 일수 (윤년은 2월에서 조정)
    int days_in_month[] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

    int year = tm->tm_year + 1900;
    int month = tm->tm_mon;
    tm->tm_mday = 1;  // 1일로 설정

    mktime(tm);  // 요일 계산
    int weekday = tm->tm_wday;  // 0=일요일

    // 윤년 처리
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        days_in_month[1] = 29;

    days = days_in_month[month];

    printf("      %d월 %d년\n", month + 1, year);
    printf("일 월 화 수 목 금 토\n");

    for (i = 0; i < weekday; i++) printf("   ");
    for (i = 1; i <= days; i++) {
        printf("%2d ", i);
        if (++weekday % 7 == 0) printf("\n");
    }
    printf("\n");

    return 0;
}
