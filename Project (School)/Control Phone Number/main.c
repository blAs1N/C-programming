#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum {Input = 1, SHOWALL, SEARCH, DELETE, INIT, QUIT};

int main() {
	int inputMenu = 0;
	Constructor();

	while (1) {
		ShowMenu();
		fputs("�����ϼ��� : ", stdout);
		scanf("%d", &inputMenu);
		fflush(stdin);

		switch (inputMenu) {
		case Input:
			InputPhoneData();
			break;

		case SHOWALL:
			ShowAllData();
			break;

		case SEARCH:
			SearchPhoneData();
			break;

		case DELETE:
			DeletePhoneData();
			break;

		case INIT:
			InitFile();
			break;
		}

		if (inputMenu == QUIT) {
			puts("�̿��� �ּż� �����մϴ�.");
			break;
		}

		system("pause");
	}

	Destructor();
	return 0;
}