#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif

int main(void) {
    char name[100];
    char date[11]; // yyyy-mm-dd + '\0'

    printf("[현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요]: ");
    scanf("%10s", date);
    printf("[당신의 이름을 입력하세요]: ");
    scanf(" %[^\n]", name); // 공백 포함 입력

    printf("**입력이 정상적으로 처리되었습니다.**\n");

    // 3초 대기
#ifdef _WIN32
    Sleep(3000);
#else
    sleep(3);
#endif

    // 화면 클리어
    system(CLEAR);

    // 상단 테두리
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    // 삼각형과 메시지 출력
    const char *lines[] = {
        "[마그라테아 ver 0.1]",
        "풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,",
        "사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,",
        "마그라테아에 오신걸 환영합니다."
    };
    int total_lines = sizeof(lines) / sizeof(lines[0]);

    for (int i = 0; i < total_lines; i++) {
        // 왼쪽 삼각형
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        // 본문
        printf("   %-78s", lines[i]);

        // 오른쪽 역삼각형
        for (int j = total_lines - i; j > 0; j--) {
            printf("*");
        }
        printf("\n");
    }

    // 하단 테두리
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    // 사용자 정보 출력
    int y, m, d;
    sscanf(date, "%d-%d-%d", &y, &m, &d);
    printf("[사용자]: %s                                   [실행 시간]:%d년 %d월 %d일\n", name, y, m, d);

    printf("================================================================================\n");

    return 0;
}
