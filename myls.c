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
        {"all", no_argument, NULL, 'a'},
        {"long", no_argument, NULL, 'l'}, 
        {"recursive", no_argument, NULL, 'R'},
        {NULL, no_argument, NULL, 0}
    };
	int long_index;
    int opt;
    const char short_option[] = "alR";
    
    int flag_a = 0, flag_l = 0, flag_R = 0;
    
    
    while((opt = getopt_long(argc, argv, short_option, long_option, &long_index)) != -1)
    {
        switch(opt)
        {
        case 'a': flag_a = 1;
            break;
        case 'l': flag_l = 1;
            break;
        case 'R': flag_R = 1;
            break;
        case '?': printf("Unknown parameter: -%c\n", optopt);
        }
    }

        DIR* k;
    if (argv[optind] != NULL)                  //чтобы открывал папку имя которой мы ввели
    {
        k = opendir(argv[optind]);
    }
    else
    {
        k = opendir(".");
    }
    struct dirent* dirs;


	if (flag_a == 1)
    {
        while ((dirs = readdir(k)) != NULL)
        {
            
            printf("%s ", dirs->d_name);
        }
    }
    
    if (flag_a == 0)
    {
      
        if (argv[optind] == NULL)
        {
        	while ((dirs = readdir(k)) != NULL)
        	{
            
            	if ('.' != dirs->d_name[0])
                	printf("%s ", dirs->d_name);
            
        	}
        }
        
        if((argv[optind] != NULL) && (strcmp(".", argv[optind]) == 0))
        {
        	while ((dirs = readdir(k)) != NULL)
        	{
            	if ('.' != dirs->d_name[0])
            	{
                	printf("%s ", dirs->d_name);
            	}
        	}
        }
        if((argv[optind] != NULL) && (strcmp("..", argv[optind]) == 0))
       	{
        	k = opendir("..");
        	while ((dirs = readdir(k)) != NULL)
        	{
            	if ('.' != dirs->d_name[0])
            	{
            	    printf("%s ", dirs->d_name);
            	}
        	}  
        }
        
    }


   /* struct stat* buf;



    if (flag_l == 1)
    {
        if (argv[optind] == NULL)
        {
            while ((dirs = readdir(k)) != NULL)
            {
                printf("%s ", dirs->d_name);
                stat(dirs->d_name,  buf);
                printf("%n 55555\n", buf->st_mode);
            }
        }
    }
*/


	return 0;
}

