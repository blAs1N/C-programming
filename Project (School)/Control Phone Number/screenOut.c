#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

void ShowMenu() {
	system("cls");

	printf("--------�޴�------------\n");
	printf(" 1. ��ȭ��ȣ �Է�\n");
	printf(" 2. ��ü ���� ���\n");
	printf(" 3. ��ȭ��ȣ �˻�\n");
	printf(" 4. ��ȭ��ȣ ����\n");
	printf(" 5. ���� ��� �ʱ�ȭ\n");
	printf(" 6. ����\n");
	printf("------------------------\n");
	printf("����> ");
}

void ShowPhoneInfo(phoneData* phone) {
	printf("��----------------------\n");
	printf("| �� �̸�: %s\n", phone->name);
	printf("| �� ��ȭ��ȣ: %s\n", phone->phoneNum);
	printf("��-----------------------\n\n");
}