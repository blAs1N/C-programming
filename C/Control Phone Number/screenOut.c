#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

void ShowMenu() {
	system("cls");

	puts("--------�޴�------------");
	puts(" 1. ��ȭ��ȣ �Է�");
	puts(" 2. ��ü ���� ���");
	puts(" 3. ��ȭ��ȣ �˻�");
	puts(" 4. ��ȭ��ȣ ����");
	puts(" 5. ��ȭ��ȣ ����");
	puts(" 6. ���� ��� �ʱ�ȭ");
	puts(" 7. ����");
	puts("------------------------");
	printf("����> ");
}

void ShowPhoneInfo(phoneData* phone) {
	puts("��----------------------");
	printf(" | �� �̸�: %s\n", phone->name);
	printf(" | �� ��ȭ��ȣ: %s\n", phone->phoneNum);
	puts("��-----------------------\n");
}