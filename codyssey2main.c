#include <stdio.h>
#include <stdlib.h>

// 전역 변수로 체력과 지식 점수 관리 (포인터 미사용 조건 반영)
int stamina_score = -1;
int knowledge_score = -1;

// 함수 선언
void show_main_menu();
void handle_main_menu();
void show_sub_menu();
void handle_sub_menu();
void input_stamina();
void input_knowledge();
void show_status();

int main() {
    handle_main_menu(); // 최소화된 main
    return 0;
}

// 메인 메뉴 출력
void show_main_menu() {
    printf("\n==== Magrathea ====\n");
    printf("1. 체력과 지식\n");
    printf("0. 종료\n");
    printf("===================\n");
    printf("선택: ");
}

// 메인 메뉴 처리
void handle_main_menu() {
    int choice;
    while (1) {
        show_main_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                handle_sub_menu();
                break;
            case 0:
                printf("프로그램을 종료합니다.\n");
                return;
            default:
                printf("잘못된 입력입니다.\n");
        }
    }
}

// 하위 메뉴 출력
void show_sub_menu() {
    printf("\n-- 체력과 지식 메뉴 --\n");
    printf("1. 체력 준비 점수 입력\n");
    printf("2. 지식 준비 점수 입력\n");
    printf("3. 현재 상태 보기\n");
    printf("0. 주 메뉴로 돌아가기\n");
    printf("---------------------\n");
    printf("선택: ");
}

// 하위 메뉴 처리
void handle_sub_menu() {
    int choice;
    while (1) {
        show_sub_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                input_stamina();
                break;
            case 2:
                input_knowledge();
                break;
            case 3:
                show_status();
                break;
            case 0:
                return; // 주 메뉴로 복귀
            default:
                printf("잘못된 입력입니다.\n");
        }
    }
}

// 체력 점수 입력
void input_stamina() {
    printf("체력 점수를 입력하세요 (0~100): ");
    scanf("%d", &stamina_score);
    printf("체력 점수가 저장되었습니다.\n");
}

// 지식 점수 입력
void input_knowledge() {
    printf("지식 점수를 입력하세요 (0~100): ");
    scanf("%d", &knowledge_score);
    printf("지식 점수가 저장되었습니다.\n");
}

// 현재 상태 출력
void show_status() {
    printf("\n[현재 상태]\n");
    printf("체력 점수: %d\n", stamina_score >= 0 ? stamina_score : 0);
    printf("지식 점수: %d\n", knowledge_score >= 0 ? knowledge_score : 0);
}
