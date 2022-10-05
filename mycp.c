#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char **argv)
{
	const struct option long_option[] =
    {
        {"help", no_argument, NULL, 'h'},
        {"verbose", no_argument, NULL, 'v'}, 
        {"interactive", no_argument, NULL, 'i'},
        {"force", no_argument, NULL, 'f'},
        {NULL, no_argument, NULL, 0}
    };
	int long_index;
    int opt;
    const char short_option[] = "hvif";
    
    int flag_h = 0, flag_v = 0, flag_i = 0, flag_f = 0;
    
    
    while((opt = getopt_long(argc, argv, short_option, long_option, &long_index)) != -1)
    {
        switch(opt)
        {
        case 'h': flag_h = 1;
            break;
        case 'v': flag_v = 1;
            break;
        case 'i': flag_i = 1;
            break;
        case 'f': flag_f = 1;
            break;
        case '?': printf("Unknown parameter: -%c\n", optopt);
        }
    }

    if (flag_h == 1)
    {
        printf("Эта программа копирует содержимое одного файла в другой\n");
        _Exit (EXIT_SUCCESS);
    }
    FILE* f1 = fopen(argv[optind], "r" );
    FILE* f2 = fopen(argv[optind + 1] , "w" );
    char* buff = (char*)malloc(10000*sizeof(char));
    long int l = fread(buff, sizeof(buff[0]), 100000, f1);
    fwrite(buff, sizeof(buff[0]), l, f2);
    fclose(f1);
    fclose(f2);
    if (flag_v == 1)
    {
        printf("%s > %s \n", argv[optind], argv[optind + 1]);
    }
    return 0;
}
