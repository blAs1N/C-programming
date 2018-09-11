#include <stdio.h>
#include <stdlib.h>

#define SAFE_FREE(x) x = NULL; free(x);

#define ASKIINUM 48
#define MAX_SIZE 8

int Input(const char* guide, const int maxCount);
void Fgets(char* buf, int maxCount, FILE* fp);
void Swap(char* a, char* b);

int main() {
	int n, count = 0;
	char result[MAX_SIZE + 1] = { '0', '0', '0', '0', '0', '0', '0', '0', 0 };
	int size = sizeof(result) / sizeof(result[0]);

	do {
		system("cls");
		puts("�� ���α׷��� 8��Ʈ (10���� 255)������ �ް� �ۼ��Ǿ����ϴ�");
		n = Input("10����: ", 4);
	} while (n > 255);

	while (n > 1) {
		result[count++] = (n % 2) + ASKIINUM;
		n >>= 1;
	}

	result[count] = n + ASKIINUM;

	for (int i = MAX_SIZE - 1; i >= MAX_SIZE / 2; i--)
		Swap(&(result[i]), &(result[MAX_SIZE - 1 - i]));

	puts(result);

	return 0;
}

int Input(const char* guide, const int maxCount) {
	int n;
	char* input = (char*)calloc(maxCount, sizeof(char));

	fputs(guide, stdout);
	Fgets(input, maxCount, stdin);
	n = atoi(input);

	SAFE_FREE(input);
	return n;
}

void Fgets(char* buf, int maxCount, FILE* fp) {
	int i;

	for (i = 0; i < maxCount - 1; i++) {
		buf[i] = fgetc(fp);

		if (buf[i] == '\n') {
			fseek(fp, 0, SEEK_SET);
			for (; i < maxCount; i++) { buf[i] = '\0'; }
			return;
		}
	}

	fseek(fp, 0, SEEK_SET);
	buf[maxCount - 1] = '\0';
}

void Swap(char* a, char* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}