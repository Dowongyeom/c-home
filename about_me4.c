#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUDGES 100
#define BUFFER_SIZE 1024
#define FIELD_COUNT 7

char *judges_array[MAX_JUDGES];

int count_fields(const char *input) {
    int count = 1;
    for (const char *p = input; *p; p++) {
        if (*p == ',') count++;
    }
    return count;
}

void parse_and_print(const char *judge_data, int index) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, judge_data);

    printf("[심사위원 %d]\n", index + 1);

    char *token = strtok(buffer, ",");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }

    printf("-----------------------------------\n");
}

int main() {
    char project[100];
    int total_judges, selected_members;

    printf("####################################\n");
    printf("#      심사위원 명단 데이터 입력       #\n");
    printf("####################################\n");
    printf("> 참여 프로젝트: ");
    fgets(project, sizeof(project), stdin);
    project[strcspn(project, "\n")] = '\0';  // 줄바꿈 제거

    printf("> 심사 총 인원: ");
    scanf("%d", &total_judges);

    if (total_judges > MAX_JUDGES) {
        printf("최대 심사위원 수는 %d명입니다.\n", MAX_JUDGES);
        return 1;
    }

    printf("> 선발 멤버 수: ");
    scanf("%d", &selected_members);
    getchar();  // 버퍼 클리어

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사위원 정보 입력을 시작합니다.\n", total_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");

    int i = 0;
    while (i < total_judges) {
        printf("*심사위원 %d: ", i + 1);
        char input[BUFFER_SIZE];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        // 필드 수 검사
        if (count_fields(input) != FIELD_COUNT - 1) {
            printf("입력 항목이 정확하지 않습니다. 다시 입력해주세요.\n");
            continue;
        }

        // 메모리 할당 및 복사
        judges_array[i] = malloc(strlen(input) + 1);
        if (judges_array[i] == NULL) {
            printf("메모리 할당 실패\n");
            return 1;
        }
        strcpy(judges_array[i], input);
        i++;
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사위원 정보 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    char confirm;
    printf("\"%s 심사위원 정보를 확인할까요?\" (Y/N): ", project);
    scanf(" %c", &confirm);

    if (confirm == 'Y') {
        printf("####################################\n");
        printf("#        심사위원 데이터 출력        #\n");
        printf("####################################\n");

        for (int j = 0; j < total_judges; j++) {
            parse_and_print(judges_array[j], j);
            free(judges_array[j]);
        }
    } else {
        printf("프로그램을 종료합니다.\n");
    }

    return 0;
}
