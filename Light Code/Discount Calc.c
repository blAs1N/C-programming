#include <stdio.h>

int main() {
	int price, dis, reduce = 0;
	
	printf("��ǰ�� ������ �Է����ּ��� : ");
	scanf("%d", &price);
	printf("�������� �Է����ּ���(���ڸ� �Է����ּ���) : ");
	scanf("%d", &dis);
	
	reduce = price - price * dis / 100;
	
	printf("���� ���� : %d", reduce); 
}
