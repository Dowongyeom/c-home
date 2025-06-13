#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 외부 함수 선언들 (각 문제별로 이후에 정의)
void matchMentoring();
void overcomeTrauma();
void setExerciseRoutine();
void getExerciseRoutine();

// 공통 유틸 함수
void printMainMenu();
void printSubMenu1();
void printSubMenu2();

int main() {
    int mainChoice;
    char subChoice;

    srand(time(NULL));  // 랜덤 초기화

    while (1) {
        printMainMenu();
        scanf("%d", &mainChoice);
        getchar(); // 버퍼 비우기

        switch (mainChoice) {
            case 1:
                printSubMenu1();
                scanf(" %c", &subChoice);
                subChoice = toupper(subChoice);

                if (subChoice == 'A') {
                    matchMentoring();
                } else if (subChoice == 'B') {
                    overcomeTrauma();
                } else {
                    printf("잘못된 선택입니다.\n");
                }
                break;

            case 2:
                printSubMenu2();
                scanf(" %c", &subChoice);
                subChoice = toupper(subChoice);

                if (subChoice == 'C') {
                    setExerciseRoutine();
                } else if (subChoice == 'D') {
                    getExerciseRoutine();
                } else {
                    printf("잘못된 선택입니다.\n");
                }
                break;

            case 0:
                printf("프로그램을 종료합니다.\n");
                return 0;

            default:
                printf("올바른 숫자를 입력하세요.\n");
        }
    }
    return 0;
}
