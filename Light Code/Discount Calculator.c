#include <stdio.h>

int main() {
	unsigned int price, reduce = 0;
	unsigned short dis = 0;
	
	printf("��ǰ�� ������ �Է����ּ��� : ");
	scanf("%d", &price);
	printf("�������� �Է����ּ���(���ڸ� �Է����ּ���) : ");
	scanf("%d", &dis);
	
	reduce = price - price * dis / 100;
	
	printf("���� ���� : %d", reduce); 
}
