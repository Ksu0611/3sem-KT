#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int N = 0;
	printf("Введите сколько кораблей\n");
	scanf("%d", &N);
	int *a = (int *)calloc(N, sizeof(int));
	int i = 0;
	int s = 0;
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		s = s + a[i];
	}
	s = s / N;
	printf("В каждом %d сундуков\n", s);
	for(i = 0; i < N; i++)
	{
		printf("%d\n", s - a[i]);
	}
	free(a);
	return 0;
}