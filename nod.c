#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{

	int a = 0;
	int b = 0;
	double c = 0;

	printf("Введите числа\n");
	scanf("%d%d", &a, &b);

	while ((a != 0) && (b != 0))
	{
		if (a > b)
		{
			a = a % b;
		}
		else
		{
			b = b % a;
		}
	}

	c = a + b;
	printf("нод %.2lf\n", c);
	return 0;
}

