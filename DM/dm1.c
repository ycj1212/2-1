#include <stdio.h>

#define N 5
#define R 3

int selected[R];

void full(int depth, int index)
{
	int i;
	if (R == depth) {
		for (i = 0; i < R; i++) {
			printf("%d ", selected[i]);
		}
		printf("\n");
		return;
	}
	for (i = index; i <= N; i++) {
		selected[depth] = i;
		full(depth +1, i+1);
	}
}

int main()
{
	full(0, 1);
	return 0;
}