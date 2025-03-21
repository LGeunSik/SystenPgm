#include <stdio.h>

int main() {
    char name[100];
    char student_id[20];

    printf("학번을 입력하세요: ");
    scanf("%s", student_id);

    printf("이름을 입력하세요: ");
    scanf("%s", name);

    printf("학번: %s\n", student_id);
    printf("이름: %s\n", name);

    return 0;
}

