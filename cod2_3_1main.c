#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MEMBERS 8
#define MAX_NAME 30

// 멘토 구조체
typedef struct {
    int id;
    char name[MAX_NAME];
    int menteeId;
} Mentor;

// 전역 배열
int trainees[MAX_MEMBERS];        // 연습생 숫자 ID
int abilities[MAX_MEMBERS];       // 연습생 능력치
Mentor mentors[MAX_MEMBERS];      // 멘토 목록

// 닉네임 -> ASCII 합
int parseIntMember(const char *nickname) {
    int sum = 0;
    for (int i = 0; nickname[i] != '\0'; i++) {
        sum += (int)nickname[i];
    }
    return sum;
}

// 능력치 랜덤 부여
int getRandomAbility() {
    return rand() % 901 + 100; // 100~1000
}

// 연습생 초기화
void initTrainees() {
    char nick[MAX_MEMBERS][MAX_NAME] = {
        "goeun", "wonchul", "youngjin", "hyekyung",
        "aseo", "nana", "ray", "mint"
    };
    for (int i = 0; i < MAX_MEMBERS; i++) {
        trainees[i] = parseIntMember(nick[i]);
        abilities[i] = getRandomAbility();
    }
}

// 멘토 등록
void inputMentors() {
    printf("\n[멘토 입력 - 최대 8명]\
