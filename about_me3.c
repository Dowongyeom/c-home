// candidates.c

#include <stdio.h>
#include <stdlib.h>

#define NUM_CANDIDATES 6

// 후보자 정보 배열
char *candidate01[12], *candidate02[12], *candidate03[12],
     *candidate04[12], *candidate05[12], *candidate06[12];

char **candidates[NUM_CANDIDATES] = {
    candidate01, candidate02, candidate03,
    candidate04, candidate05, candidate06
};

// 후보자 속성 이름
const char *member_info[12] = {
    "성명", "생일", "성별", "메일 주소", "국적", "BMI",
    "주 스킬", "보조 스킬", "TOPIK", "MBTI", "소개", "만 나이"
};

// 현재 날짜로 만 나이 계산
int calculate_age(int year, int month, int day) {
    int current_year = 2025;
    int current_month = 4;
    int current_day = 7;

    int age = current_year - year;
    if (current_month < month || (current_month == month && current_day < day)) {
        age--;
    }
    return age;
}

// 생일 문자열에서 연/월/일 추출
void parse_birth(const char *birth, int *year, int *month, int *day) {
    sscanf(birth, "%4d/%2d/%2d", year, month, day);
}

int main() {
    char group_name[50];
    int i;

    // 그룹명 입력 (getchar 사용)
    printf("오디션 그룹명을 입력하세요: ");
    fgets(group_name, sizeof(group_name), stdin);
    for (i = 0; group_name[i] != '\0'; i++) {
        if (group_name[i] == '\n') {
            group_name[i] = '\0';
            break;
        }
    }

    // 입력 화면
    printf("####################################\n");
    printf("[%s] 오디션 후보자 데이터 입력\n", group_name);
    printf("####################################\n");

    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("후보자 #%d의 정보를 입력합니다.\n", i + 1);
        printf("---------------------------------\n");

        candidates[i][0] = (char *)malloc(50);  // 이름
        printf("1. 성명: ");
        fgets(candidates[i][0], 50, stdin);

        candidates[i][1] = (char *)malloc(20);  // 생일
        printf("2. 생일(YYYY/MM/DD 형식): ");
        fgets(candidates[i][1], 20, stdin);

        candidates[i][2] = (char *)malloc(5);  // 성별
        printf("3. 성별(F/M): ");
        fgets(candidates[i][2], 5, stdin);

        candidates[i][3] = (char *)malloc(50);  // 메일
        printf("4. 메일 주소: ");
        fgets(candidates[i][3], 50, stdin);

        candidates[i][4] = (char *)malloc(20);  // 국적
        printf("5. 국적: ");
        fgets(candidates[i][4], 20, stdin);

        candidates[i][5] = (char *)malloc(10);  // BMI
        printf("6. BMI: ");
        fgets(candidates[i][5], 10, stdin);

        candidates[i][6] = (char *)malloc(20);  // 주 스킬
        printf("7. 주 스킬: ");
        fgets(candidates[i][6], 20, stdin);

        candidates[i][7] = (char *)malloc(50);  // 보조 스킬
        printf("8. 보조 스킬: ");
        fgets(candidates[i][7], 50, stdin);

        candidates[i][8] = (char *)malloc(5);  // TOPIK
        printf("9. 한국어 등급(TOPIK): ");
        fgets(candidates[i][8], 5, stdin);

        candidates[i][9] = (char *)malloc(10);  // MBTI
        printf("10. MBTI: ");
        fgets(candidates[i][9], 10, stdin);

        candidates[i][10] = (char *)malloc(200);  // 자기소개
        printf("11. 소개: ");
        fgets(candidates[i][10], 200, stdin);

        // 나이 계산
        int y, m, d;
        parse_birth(candidates[i][1], &y, &m, &d);
        candidates[i][11] = (char *)malloc(5);
        sprintf(candidates[i][11], "%d", calculate_age(y, m, d));

        printf("=================================\n");
    }

    // 출력 화면
    printf("\n####################################\n");
    printf("[%s] 오디션 후보자 데이터 조회\n", group_name);
    printf("####################################\n");

    printf("=========================================================================================================\n");
    printf("성   명(나이) | 생   일     | 성별 | 메   일               | 국적   | BMI  | 주스킬 | 보조스킬     | TOPIK | MBTI  \n");
    printf("=========================================================================================================\n");

    for (i = 0; i < NUM_CANDIDATES; i++) {
        char name_with_age[100];
        char birth_fmt[20];
        int year, month, day;

        sscanf(candidates[i][1], "%d/%d/%d", &year, &month, &day);
        sprintf(birth_fmt, "%04d%02d%02d", year, month, day);
        sprintf(name_with_age, "%s(%s)", candidates[i][0], candidates[i][11]);

        // 줄바꿈 제거
        for (int j = 0; j < 11; j++) {
            char *p = candidates[i][j];
            while (*p) {
                if (*p == '\n') *p = '\0';
                p++;
            }
        }

        const char *topik;
        if (atoi(candidates[i][8]) == 0) topik = "원어민";
        else sprintf(candidates[i][8], "%d급", atoi(candidates[i][8])), topik = candidates[i][8];

        printf("%-12s| %-10s | %-4s | %-20s | %-6s | %-4s | %-6s | %-10s | %-5s | %-5s\n",
               name_with_age, birth_fmt, candidates[i][2],
               candidates[i][3], candidates[i][4], candidates[i][5],
               candidates[i][6], candidates[i][7], topik, candidates[i][9]);

        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("%s\n", candidates[i][10]);
        printf("---------------------------------------------------------------------------------------------------------\n");
    }

    // 메모리 해제
    for (i = 0; i < NUM_CANDIDATES; i++) {
        for (int j = 0; j < 12; j++) {
            free(candidates[i][j]);
        }
    }

    return 0;
}
