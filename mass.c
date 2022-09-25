#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void func(int *a, int N)
{
		for(i = 0; i < N; i++)
	{
		if (a[i] % 2 == 0)
		{
			a[i] = a[i] * 2;
		}
		if (a[i] % 2 != 0)
		{
			a[i] = a[i] + 2;
		}
	}
}
int main()
{
	int N = 0;
	int i = 0;
	printf("Введите сколько элементов\n");
	scanf("%d", &N);
	int *a = (int *)calloc(N, sizeof(int));
	for(i = 0; i < N; i++)
	{
		scanf("%d, ", &a[i]);
	}

	func(a, N);
	for(i = 0; i < N; i++)
	{
		printf("%d, ", a[i]);
	}
	free(a);
	return 0;
}