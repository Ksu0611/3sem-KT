#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
	int i =1;
	int j = 47;
	int status = 0;
	int fd[2];
	pipe(fd); //
	pid_t one = fork();
			char string1[6];

	if (one == 0) //ребёнок
	{
		char string[] = "pivo";
		//int size = write(fd[1], string, 5);
		//for( i = 1; i == 1000000000; i++);
		//sleep(10);
		printf("ребенок свой %d\n", getpid());
		printf("ребенок родитель %d\n", getppid());
	}
	if (one != 0) //родитель
	{
		close(fd[0]);
		wait(&status);
		int size = read(fd[0], string1, 5);
		printf("родитель ребенок %d\n", one);
		printf("родитель свой %d\n", getpid());
		printf("родитель дедушку %d\n", getppid());
		printf("%s\n", string1);

	}

	return 0;
}