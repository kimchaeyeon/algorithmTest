#include<stdio.h>

void queens(int i, int n, int col[]);
int promising(int i, int col[]);

void main() {
	int i = 0;
	int n = 0;
	int* col;

	printf("몇개의 여왕말을 두고 싶으신가요?\n");
	scanf_s("%d", &n);
	printf("각 행의 여왕말이 몇번째 위치에 있는지 차례로 출력!\n");

	col = (int*)malloc(sizeof(int)*n);

	queens(0, n, col);
	scanf_s("%d", &n);

	free(col);

	return 0;

}

void queens(int i, int n, int col[]) {
	int x;
	int y;
	if (promising(i, col)) {
		if (i == n) {

			for (x = 1; x <= n; x++) {
				printf(" %d", col[x]);
			}
			printf(" 인 경우가 있습니다");
			printf("\n");
		}
		else {
			for (y = 1; y <= n; y++) {
				col[i + 1] = y;
				queens(i + 1, n, col);
			}
		}
	}

}

int promising(int i, int col[]) {
	int k = 1;
	int sswitch = 1;
	while (k < i && sswitch) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
			sswitch = 0;
		k++;
	}
	return sswitch;
}

