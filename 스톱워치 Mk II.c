#include <stdio.h>
#include <stdlib.h>

int stopWatch();
int timer();
char getKey();
void close();

int main() {
	int func = 0;
	int scanReturn = 0;
	int retry = 0;
	
	while(1) {
		system("cls");
			do {
				printf("�����ġ�� 1, Ÿ�̸Ӵ� 2, ����� 0�� �����ּ���. ");
				fflush(stdin);
				retry = (scanf("%d", &func) != 1 ? 1 : 0);
				system("cls");
			} while(retry == 1);
			
			switch(func) {
				case 1 : 
				stopWatch();
				break;
				
				case 2 :
				timer();
				break;
				
				case 0 :
				close();
				
				default :
				printf("�� ���� �Է� ���Դϴ�.");
				Sleep(1500);
			}
	}
	return 0;
}

int stopWatch() {
	int time[3] = {0, 0, 0};
	char key = 0;
	
	while(1) {
		key = 0;
		time[2]++;
		
		if(time[2] >= 60) {
			time[2] = 0;
			time[1]++;
		}
		
		if(time[1] >= 60) {
			time[1] = 0;
			time[0]++;
		}

		printf("%2d : %2d : %2d\n�Ͻ� ������ 1, �ʱ�ȭ������ ���ư����� 2, ����� 0�� ��������.\n\n", time[0], time[1], time[2]);

		key = getKey();
		
		if(key == '1') {
			system("pause");
		} else if(key == '2') {
			return 0;
		} else if(key == '0') {
			close();
		}
		
		Sleep(1000);
		system("cls");
	}
}

int timer() {
	int time[3] = {0, 0, 0};
	int retry = 0;
	char key = 0;
	
	do {
		printf("�ð��� �Է����ּ���(�� �� �ʷ� �Է����ּ���). ");
		fflush(stdin);
		retry = (scanf("%d %d %d", &time[0], &time[1], &time[2]) != 3 ? 1 : 0);
		system("cls");
	} while(retry == 1);
		
	while(1) {
		key = 0;
		time[2]--;
		
		if(time[2] < 0) {
			time[2] = 59;
			time[1]--;
		}
		
		if(time[1] < 0) {
			time[1] = 59;
			time[0]--;
		}

		printf("%d : %d : %d\n�Ͻ� ������ 1, �ʱ�ȭ������ ���ư����� 2, ����� 0�� ��������.\n\n", time[0], time[1], time[2]);
		

		key = getKey();
		
		if(key == '1') {
			system("pause");
		} else if(key == '2') {
			return 0;
		} else if(key == '0') {
			close();
		}
		
		if(time[0] == 0 && time[1] == 0 && time[2] == 0) {
			printf("\a�ð��� �� �Ǿ����ϴ�.\n");
			system("pause");
			break;
		}
		
		Sleep(1000);
		system("cls");
	}
}

char getKey() {
	if(kbhit()) {
        return getch();
    }
    
    return 0;
}

void close() {
	system("cls");
	printf("�����մϴ�.");
	exit (0);
}
