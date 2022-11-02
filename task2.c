#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <assert.h>




int main(int argc, char* argv[])
{
    FILE* f1 = fopen(argv[1], "r" );
    FILE* f2 = fopen(argv[2] , "a+" );

    int status = 0;
	int fd[2];
	pipe(fd); 
	pid_t one = fork();
	int i = 0;
	char buff[100];
    if (one != 0) //родитель
    {
		close(fd[0]);


		while (!feof (f1))
        {
            fgets(buff, 100, f1);
            //printf("%s\n", buff);
            write (fd[1], buff, 100);
            i++;
        }
		close(fd[1]);

		fclose(f1);
    	fclose(f2);	
	}
	if (one == 0) //ребенок
	{

		close(fd[1]);
		char string[100];
        while(read(fd[0], string, 100) != NULL)
        {
        	//printf("%s\n", string);
            fprintf(f2, "%s\n", string);
        }
		close(fd[0]);
		fclose(f1);
    	fclose(f2);

	}

}