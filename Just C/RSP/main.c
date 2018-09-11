#include <stdio.h>

/* [Notice for C/C++]
* - �⺻ �����Ǵ� ���� �ڵ�� ������� ���ظ� �������� �����Ǿ����ϴ�.
* - �����ڵ��� Ȱ���� ���û����̸� �ڵ带 ���� �ۼ��Ͽ��� �����մϴ�.
*
* - ������ ���� ó���� �ý�����, ��Ʈ��ũ/�������� ���� ���� ������
* - main�� int������ ������ �� return 0�� �׻� �ϴ� ���� �����մϴ�
* - �������� �迭 ũ�⿡ ���� Stack Overflow ������ �����ϼ���
* - (C++) cin/cout���� scanf/printf�� ����ϱ⸦ �����մϴ�. (����� ���ɿ� ���� ����)
*/

int main()
{   //���α׷��� ���ۺ� 
	int player[5];
	int winner = 0; //�� ������ �¸��ϴ� ����� ���� �����Ѵ�
	int i, j, allSame, count = 1;
	for (i = 0; i < 5; i++) {
		scanf("%d", &player[i]);
	}

	allSame = player[0];
	for (i = 0; i < 5; i++) {

		if (player[i] != allSame) {
			allSame = player[i];
			count++;

			if (count > 2) {
				printf("0\n");
				return 0;
			}
		}
	}

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (i == j) { break; }

			if (player[i] > player[j]) {
				winner++;
				break;
			}

			if (player[i] == 1 && player[j] == 3) {
				winner++;
				break;
			}
		}
	}

	//���� ����Ѵ� 
	printf("%d\n", winner);
	return 0;
}