#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum {Input = 1, SHOWALL, SEARCH, DELETE, QUIT};

int main() {
	int inputMenu = 0;

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

		case QUIT: {
			puts("�̿��� �ּż� �����մϴ�.");
			return 0;
		}
		}

		system("pause");
	}

	Destructor();
	return 0;
}