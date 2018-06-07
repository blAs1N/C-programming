#include "star.h"

int main() {
	int film, mode;
	void(*fp[MAX_MODE])(int, char*, char*) = { square, triangle_1, triangle_2, triangle_3, triangle_4, pyramid, reverse, diamond, hourglass };

	do {
		film = input("���� ������ �Է����ּ���. ");
	} while (film > 20);

	do {
		mode = input("�簢���� 1, �ﰢ�� 1�� 2, �ﰢ�� 2�� 3,\n�ﰢ�� 3�� 4, ����� 4�� 5, �Ƕ�̵�� 6,\n���Ƕ�̵�� 7, ���̾Ƹ��� 8, �𷡽ð�� 9�� �Է����ּ���. ");
	} while (!(0 < mode && mode <= MAX_MODE));

	char* stars = assign(film, '*'); char* blank = assign(film, ' ');
	fp[mode - 1](film, stars, blank);
	SAFE_FREE(stars); SAFE_FREE(blank);

	system("pause");
	return 0;
}