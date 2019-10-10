/* 20144626 양철주 */

#include <stdio.h>
#include <stdlib.h>

void comb(int* p, int N, int R, int depth, int idx);
void combOver(int* p, int N, int R, int depth, int idx);
void perm(int* f, int* p, int N, int R, int depth);
void permOver(int* p, int N, int R, int depth);

int main()
{
	int* p = NULL;
	int* f = NULL;
	int n, r;
	int sel1, sel2;

	printf("n 입력: ");
	scanf_s("%d", &n);
	printf("r 입력: ");
	scanf_s("%d", &r);

	p = (int*)malloc(sizeof(int)*n);

	printf("[1: 조합, 2: 순열]? >> ");
	scanf_s("%d", &sel1);
	printf("[1: 중복O, 2: 중복X]? >> ");
	scanf_s("%d", &sel2);
	
	if (sel1 == 1 && sel2 == 1) {
		combOver(p, n, r, 0, 1);	// 중복을 허용하는 조합
	}
	else if (sel1 == 1 && sel2 == 2) {
		comb(p, n, r, 0, 1);	// 중복을 허용하지 않는 조합
	}
	else if (sel1 == 2 && sel2 == 1) {
		permOver(p, n, r, 0);	// 중복을 허용하는 순열
	}
	else if (sel1 == 2 && sel2 == 2) {
		f = (int*)malloc(sizeof(int) * (n+1));
		perm(f, p, n, r, 0);	// 중복을 허용하지 않는 순열
		free(f);
	}

	free(p);

	return 0;
}

void comb(int* p, int N, int R, int depth, int idx)
{
	int i;
	if (R == depth) {
		for (i = 0; i < R; i++) {
			printf("%d ", p[i]);
		}
		printf("\n");
		return;
	}
	for (i = idx; i <= N; i++) {
		p[depth] = i;
		comb(p, N, R, depth + 1, i + 1);
	}
}

void combOver(int* p, int N, int R, int depth, int idx)
{
	int i;
	if (R == depth) {
		for (i = 0; i < R; i++) {
			printf("%d ", p[i]);
		}
		printf("\n");
		return;
	}
	for (i = idx; i <= N; i++) {
		p[depth] = i;
		combOver(p, N, R, depth + 1, i);
	}
}

void perm(int* f, int* p, int N, int R, int depth)
{
	int i;
	if (R == depth) {
		for (i = 0; i < R; i++) {
			printf("%d ", p[i]);
		}
		printf("\n");
		return;
	}
	for (i = 1; i <= N; i++) {
		if (f[i] == 1)continue;
		f[i] = 1;
		p[depth] = i;
		perm(f, p, N, R, depth + 1);
		f[i] = 0;
	}
}

void permOver(int* p, int N, int R, int depth)
{
	int i;
	if (R == depth) {
		for (i = 0; i < R; i++) {
			printf("%d ", p[i]);
		}
		printf("\n");
		return;
	}
	for (i = 1; i <= N; i++) {
		p[depth] = i;
		permOver(p, N, R, depth + 1);
	}
}