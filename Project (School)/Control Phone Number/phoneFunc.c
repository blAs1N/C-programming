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

	int* phoneDatas = Search(phoneList[numOfData]->name);

	if (phoneDatas[0] != -1) {
		for (int i = 0; phoneDatas[i] != -1; i++) {
			if (!strcmp(phoneList[numOfData]->phoneNum, phoneList[phoneDatas[i]]->phoneNum)) {
				printf("������ ������ �ֽ��ϴ�.\n");
				SAFE_FREE(phoneDatas);
				return;
			}
		}
	}

	SAFE_FREE(phoneDatas);
	printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
	numOfData++;
}

void ShowAllData() {
	for (int i = 0; i < numOfData; i++)
		ShowPhoneInfo(phoneList[i]);
}

void SearchPhoneData() {
	char* wantName = InputName();
	int* phoneDatas = Search(wantName);

	if (phoneDatas[0] != -1) {
		for (int i = 0; phoneDatas[i] != -1; i++)
			ShowPhoneInfo(phoneList[phoneDatas[i]]);
	}
		
	else
		printf("�Է��Ͻ� �̸��� �����ϴ�\n");

	SAFE_FREE(wantName);
}

void DeletePhoneData() {
	char* deleteName = InputName();
	int* phoneDatas = Search(deleteName);

	if (phoneDatas[0] != -1) {
		int choice, i = 0;

		while (phoneDatas[i++] != -1) {
			printf("NUM. %d\n", i);
			ShowPhoneInfo(phoneList[phoneDatas[i - 1]]);
		}

		printf("����: ");
		scanf("%d", &choice);

 		for (int delPhone = (phoneDatas[choice] - 1); delPhone < numOfData - 1; delPhone++)
			phoneList[delPhone] = phoneList[delPhone + 1];

		numOfData--;
		printf("������ �Ϸ�Ǿ����ϴ�.\n");
	}

	else
		printf("�Է��Ͻ� �̸��� �����ϴ�\n");

	SAFE_FREE(deleteName);
}

int* Search(char* name) {
	int* result = (int*)malloc((numOfData + 1) * sizeof(int));
	int numOfResult = 0;
	memset(result, -1, (numOfData + 1) * sizeof(int));

	for (int i = 0; i < numOfData; i++) {
		if (!strcmp(name, phoneList[i]->name))
			result[numOfResult++] = i;
	}

	return result;
}

char* InputName() {
	char* name = (char*)malloc(NAME_LEN * sizeof(char));
	printf("ã�� �̸���? ");
	scanf("%s", name);

	return name;
}

void Destructor() {
	for (int i = 0; phoneList[i] != NULL; i++) { SAFE_FREE(phoneList[i]); }
}