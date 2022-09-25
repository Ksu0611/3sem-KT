#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char point[10][10];
	char col;
	int n = 0;
	int x = 0;
	int y = 0;                // задаем переменные
	int k = 0;
	int j = 0;
	int op = 0;
	scanf("%d", &n);
	for (k = 0; k < 10; k++)     // заполняем массив координатами
	{
		for(j = 0; j< 10; j++)
			{
				point[k][j] = 'N'; // окрашиваем точки в N
			}
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &op);     // спрашиваем функцию и выполняем
		if (op == 1)
		{
			scanf("%d%d", &x, &y);
			scanf("%c", &col);
		}
		if (op == 2)
		{
			scanf("%d%d", &x, &y);
			printf("%c\n", point[x][y]);
		}
	}
}