#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	int fd[2];
	pipe (fd);
	pid_t one = fork();

	if (one == 0) //ребёнок
	{
		close(fd[0]);
		int arr[3];
		scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
		for(int k = 0; k < 4; k++)
		{
			int size = write(fd[1], &arr[k], 16);
		}
		/*int size = write(fd[1], arr[1], 4);
		int size = write(fd[1], arr[2], 4)
		int size = write(fd[1], arr[3], 4)*/
		close(fd[1]);
	}
	if (one != 0) //родитель
	{
		close(fd[1]);

		int string1[4];
		int sum = 0;
		for(int v = 0; v < 4; v++)
		{
			int size = read(fd[0], &string1[v], 16);
		}

		for(int i = 0; i<4; i++)
		{
			printf("%d элемент: %d  ", i, string1[i]);
			sum = sum + string1[i];
			printf("sum: %d\n", sum);
		}

		/*int size = read(fd[0], string1[1], 4);
		int size = read(fd[0], string1[2], 4);
		int size = read(fd[0], string1[3], 4);
		printf("%d %d %d %d\n", string1[0], string1[1], string1[2], string1[3]);*/
		printf("%d\n", sum);
		close(fd[0]);
	}
}