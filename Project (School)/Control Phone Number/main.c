#include "common.h"
#include "screenOut.h"
#include "phoneManager.h"

int main() {
	const void(* const funcs[6])() = { InputPhoneData, ShowAllData,
		SearchPhoneData, DeletePhoneData, ChangePhoneNum, InitAll };

	const int quit = 7;
	int inputMenu = 0;

	manager = ManagerCtor();
	Load();

	while (1) {
		ShowMenu();
		printf("�����ϼ��� : ");
		scanf("%d", &inputMenu);
		InputFlush();

		if (inputMenu == quit) {
			puts("�̿��� �ּż� �����մϴ�.");
			break;
		}
		
		if (inputMenu < quit)
			funcs[inputMenu - 1]();

		getchar();
	}

	ManagerDtor();
	return 0;
}