#include "RSP.h"

void Input(char* guide, int* UI, int* CI) {
	printf("%s", guide);							// �ȳ��� ���
	scanf("%d %d", UI, CI);							// �Է�, ���� �Է� �� rerty�� 2
}

void Process(int user, int com) {
	if (user == com) { printf("���º��Դϴ�.\n"); }
	else if ((user + 1 == com) || (user + 1 == 3) && (com == 0)) { printf("�¸��Դϴ�!\n"); }
	else { printf("�й��Դϴ�.\n"); }
}

int random(int area, int start) {
	srand(time(NULL));
	return (rand() % area + start);
}

char getKey() {
	if (kbhit())
		return getch();
}