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
        {"add", no_argument, NULL, 'a'},
        {"sub", no_argument, NULL, 's'}, 
        {"mul", no_argument, NULL, 'm'},
        {"div", no_argument, NULL, 'd'},
        {NULL, no_argument, NULL, 0}
    };
    int long_index;
    int opt;
    int res = 0;
    const char short_option[] = "asmd";
    
    int flag_a = 0, flag_s = 0, flag_m = 0, flag_d = 0; 

    while((opt = getopt_long(argc, argv, short_option, long_option, &long_index)) != -1)
    {
        switch(opt)
        {
        case 'a': flag_a = 1;
            break;
        case 's': flag_s = 1;
            break;
        case 'm': flag_m = 1;
            break;
        case 'd': flag_d = 1;
            break;
        case '?': printf("Unknown parameter: -%c\n", optopt);
        }
    }    

    printf("a = %d , s = %d, m = %d, d = %d\n", flag_a, flag_s, flag_m, flag_d);

    if (flag_a == 1)
    {
    	res = atoi(argv[optind]) + atoi(argv[optind + 1]);
    }
    if (flag_s == 1)
    {
    	if (res == 0) 
    		res = atoi(argv[optind]) - atoi(argv[optind + 1]);
    	else
    		res = res - atoi(argv[optind + 1]);    		
    }
    if (flag_m == 1)
    {
    	if (res == 0) 
    		res = atoi(argv[optind]) * atoi(argv[optind + 1]);
    	else
    		res = res * atoi(argv[optind + 1]);    		
    }
    if (flag_d == 1)
    {
    	if (res == 0) 
    		res = atoi(argv[optind]) / atoi(argv[optind + 1]);
    	else
    		res = res / atoi(argv[optind + 1]);    		
    }

    printf("%d\n", res);
    return 0;
}