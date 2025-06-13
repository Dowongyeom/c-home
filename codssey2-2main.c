#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMBER_COUNT 5
#define ITEM_COUNT 7
#define MAX_NAME_LEN 20
#define MAX_LINE 100

/* 멤버 이름과 닉네임 구조체 */
typedef struct {
    char name[MAX_NAME_LEN];
    char nickname[MAX_NAME_LEN];
} Member;

/* 멤버 배열 */
Member milliways_members[MEMBER_COUNT] = {
    {"고은", "goeun"},
    {"원철", "wonchul"},
    {"영진", "youngjin"},
    {"혜경", "hyekyung"},
    {"아서", "arthur"}
};

/* 체력 테스트 항목 이름 */
const char *health_items[ITEM_COUNT] = {
    "1마일 러닝", "스피드 스프린트", "푸시업", 
    "스쿼트", "팔굽혀 펴기", "수영", "무게 들기"
};

/* 체력 점수 배열: [멤버][항목] */
float health_scores[MEMBER_COUNT][ITEM_COUNT] = {0};

/* 닉네임으로 멤버 인덱스 찾기 */
int find_member_index(const char *nickname) {
    int i;
    for (i = 0; i < MEMBER_COUNT; i++) {
        if (strcmp(milliways_members[i].nickname, nickname) == 0) {
            return i;
        }
    }
    return -1;
}

/* 쉼표 구분 입력 문자열 파싱 */
int parse_scores(const char *line, float *parsed) {
    int i = 0;
    const char *start = line;
    char temp[16];
    while (i < ITEM_COUNT) {
        int j = 0;
        while (*start != ',' && *start != '\0') {
            temp[j++] = *start++;
        }
        temp[j] = '\0';
        parsed[i++] = atof(temp);
        if (*start == ',') start++;
    }
    return i;
}

/* 체력 상태 입력 */
void setHealth(void) {
    char nickname[MAX_NAME_LEN];
    char input_line[MAX_LINE];
    float parsed[ITEM_COUNT];
    int i, index;

    printf("\n[체력 상태 입력]\n");
    printf("닉네임 입력: ");
    scanf("%s", nickname);
    getchar();  // 개행 제거

    index = find_member_index(nickname);
    if (index == -1) {
        printf("닉네임을 찾을 수 없습니다.\n");
        return;
    }

    printf("7개 항목 데이터를 쉼표로 입력하세요\n");
    printf("입력 형식 예: 8.3,12.4,2.1,3.5,3.2,7.5,1.5\n");
    printf("입력: ");
    fgets(input_line, MAX_LINE, stdin);
    input_line[strcspn(input_line, "\n")] = 0;  // 개행 제거

    if (parse_scores(input_line, parsed) != ITEM_COUNT) {
        printf("입력 오류: 7개 항목이 필요합니다.\n");
        return;
    }

    for (i = 0; i < ITEM_COUNT; i++) {
        health_scores[index][i] = parsed[i];
    }

    printf("체력 데이터가 저장되었습니다.\n");
}

/* 체력 상태 조회 */
void getHealth(void) {
    char nickname[MAX_NAME_LEN];
    int i, j, index;

    printf("\n[체력 상태 조회]\n");
    printf("조회할 닉네임 입력 (전체 조회: all): ");
    scanf("%s", nickname);

    if (strcmp(nickname, "all") == 0) {
        for (i = 0; i < MEMBER_COUNT; i++) {
            printf("\n[%s (%s)]\n", milliways_members[i].name, milliways_members[i].nickname);
            for (j = 0; j < ITEM_COUNT; j++) {
                printf("  %s: %.2f\n", health_items[j], health_scores[i][j]);
            }
        }
    } else {
        index = find_member_index(nickname);
        if (index == -1) {
            printf("닉네임을 찾을 수 없습니다.\n");
            return;
        }

        printf("\n[%s (%s)] 체력 정보:\n", 
               milliways_members[index].name, 
               milliways_members[index].nickname);
