#include<stdio.h>
 
int main(void){
	float num[2] = {0, 0};
	float value = 0;
	unsigned char a = 0;

 	for(;;) {
 		system("cls");
 		printf("������ �Է��Ͻÿ�(�����Ϸ��� 000�� �Է����ּ���) : ");
		scanf("%f %c %f", &num[0], &a, &num[1]);
		system("cls");
 
		switch(a){
		case '+':
			value = num[0] + num[1];
			printf( "%.1f %c %.1f = %.1f", num[0], a, num[1], value);
			Sleep(2000);
			break;
			
		case '-':
			value = num[0] - num[1];
			printf( "%.1f %c %.1f = %.1f", num[0], a, num[1], value );
			Sleep(2000);
			break;
			
		case '*':
			value = num[0] * num[1];
			printf( "%.1f %c %.1f = %.1f", num[0], a, num[1], value );
			Sleep(2000);
			break;
			
		case '/': 
			if(num[1] == 0) {
				printf("�߸��� �����Դϴ�.\n");
				Sleep(2000);
				break; 
			}
			value = (int)num[0] / (int)num[1]; 
			printf( "%d %c %d = %.1f", num[0], a, num[1], value);
			Sleep(2000);
			break;
		
		case '0':
			printf("�����մϴ�\n");	
			return 0;
		default:
			printf( "����� �� ����" );
			Sleep(2000);
			break;
		}
	}
	return 0;
}
