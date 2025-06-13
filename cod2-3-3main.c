#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_TRAUMA 20
#define MAX_MENTORS 8
#define MAX_MEMBERS 16
#define MAX_QUESTIONS 5
#define MAX_ANS_LEN 100

/* 문제1 관련 */

typedef struct {
    int id;              // 1~8 멘토 ID
    char name[20];       // 멘토 이름
    int matchedMentee;   // 매칭된 멘티 번호(-1: 없음)
} Mentor;

char* memberNicknames[MAX_MEMBERS] = {
    "Alice", "Bob", "Charlie", "David",
    "Eva", "Frank", "Grace", "Helen",
    "Ian", "Jane", "Karl", "Laura",
    "Mike", "Nina", "Oscar", "Paul"
};

int memberNums[MAX_MEMBERS];    // 닉네임 ASCII 합계 저장
int memberAbility[MAX_MEMBERS]; // 능력치 100~1000

Mentor mentors[MAX_MENTORS];

/* 문제2 관련 */

typedef struct {
    char nickname[20];
    int age;
    char trauma[100];
} Trauma;

typedef struct {
    int qid;
    char question[200];
} Question;

typedef struct {
    char nickname[20];
    char question[200];
    char answer[MAX_ANS_LEN + 1];
} Counseling;

Trauma traumaMembers[MAX_MEMBERS];
int traumaCount = 0;

const Question questions[MAX_QUESTIONS] = {
    {1, "어떤 상황에서 그 트라우마를 경험하셨나요?"},
    {2, "해당 상황이 어떻게 당신의 일상생활과 감정에 어떤 영향을 미치고 있는지 말씀해주세요."},
    {3, "이 트라우마를 어떻게 극복하려고 노력하셨나요?"},
    {4, "트라우마와 관련하여 어떤 감정을 느끼고 계신가요?"},
    {5, "트라우마를 극복하기 위해 어떤 지원이 필요한 것으로 생각하시나요?"}
};

Counseling counselingRecords[MAX_MEMBERS * 3];
int counselingCount = 0;

/* 문제3 관련 */

typedef struct {
    char keyword[20];
    char message[512];
} EasterEgg;

EasterEgg egg = {
    "specter",
    "나는 고백한다. 대학 졸업 후 스타트업 창업이라는 허세에 빠져 치기 어린 행동으로 친구들의 앞길을 막았다. "
    "나는 나의 아이디어가 설득되는 사람이 나 뿐일 때 파괴적인 결과를 보게 된다는 것을 뼈저리게 경험했다. "
    "과거의 아서는 독선과 아집의 망령이다."
};

/* 유틸 함수 */

int parseIntMember(const char *nickname) {
    int sum = 0;
    for (int i = 0; nickname[i]; i++) {
        sum += (int)nickname[i];
    }
    return sum;
}

int getRandomAbility() {
    return rand() % 901 + 100; // 100~1000
}

void initMembers() {
    for (int i = 0; i < MAX_MEMBERS; i++) {
        memberNums[i] = parseIntMember(memberNicknames[i]);
        memberAbility[i] = getRandomAbility();
    }
}

void inputMentors() {
    printf("멘토를 8명 등록하세요.\n");
    for (int i = 0; i < MAX_MENTORS; i++) {
        mentors[i].id = i + 1;
        printf("멘토 #%d 이름 입력: ", mentors[i].id);
        scanf("%19s", mentors[i].name);
        mentors[i].matchedMentee = -1;
    }
}

void matchMentoring() {
    initMembers();
    inputMentors();

    /* 매칭 초기화 */
    for (int i = 0; i < MAX_MENTORS; i++) {
        mentors[i].matchedMentee = -1;
    }

    /* 매칭 수행 (보너스: 멘토 당 멘티 1:1 보장) */
    int menteeAssigned[MAX_MEMBERS] = {0};

    for (int i = 0; i < MAX_MEMBERS && i < MAX_MENTORS; i++) {
        int mod = memberNums[i] % MAX_MENTORS;
        mod = (mod == 0) ? MAX_MENTORS : mod;  // 0이면 8로
        int mentorIndex = mod - 1;
        if (mentors[mentorIndex].matchedMentee == -1) {
            mentors[mentorIndex].matchedMentee
