#include "common.h"
#include "phoneData.h"
#include "screenOut.h"
#include "phoneFunc.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData* phoneList[LIST_NUM];

void InputPhoneData() {
	phoneList[numOfData] = (phoneData*)malloc(sizeof(phoneData));

	printf("�̸� �Է�: ");
	scanf("%s", phoneList[numOfData]->name);
	printf("��ȭ��ȣ �Է�: ");
	scanf("%s", phoneList[numOfData]->phoneNum);
	printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
	numOfData++;
}

void ShowAllData() {
	for (int i = 0; i < numOfData; i++)
		ShowPhoneInfo(phoneList[i]);
}

void SearchPhoneData() {
	char* wantName = InputName();
	
	int numOfPhone = Search(wantName);

	if (numOfPhone != -1)
		ShowPhoneInfo(phoneList[numOfPhone]);
	else
		printf("�Է��Ͻ� �̸��� �����ϴ�\n");

	free(wantName);
}

void DeletePhoneData() {
	char* deleteName = InputName();

	int numOfPhone = Search(deleteName);

	if (numOfPhone != -1) {
 		for (int i = numOfPhone; i < numOfData; i++)
			phoneList[i] = phoneList[i + 1];
		numOfData--;
		printf("������ �Ϸ�Ǿ����ϴ�.\n");
	}

	else
		printf("�Է��Ͻ� �̸��� �����ϴ�\n");

	free(deleteName);
}

int Search(char* name) {
	for (int i = 0; i < numOfData; i++) {
		if (!strcmp(name, phoneList[i]->name))
			return i;
	}

	return -1;
}

char* InputName() {
	char* name = (char*)malloc(NAME_LEN * sizeof(char));
	printf("ã�� �̸���? ");
	scanf("%s", name);

	return name;
}

void Destructor() {
	for (int i = 0; phoneList[i] != NULL; i++)
		free(phoneList[i]);
}