#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void) {
	int M, N;

	int i = 1;
	int k = 100;
	int j = 0;
	int temp = 0;
	scanf("%d %d", &M, &N);
	while (i * i < M)i++;
	while (k * k > N)k--;
	if (i == k+1) printf("-1"); 
	else {
		
		for (j = i; j <= k; j++) {
			temp += (j) * (j);
		}
		printf("%d\n", temp);
		printf("%d\n", i * i);
	}
}