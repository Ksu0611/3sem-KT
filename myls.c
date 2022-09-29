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

/*void strmode(int mode, char * buff) 
{
    buf[0] = '-';
    if (S_IWUSR & mode)
        buff[1] = 'r';
    else
        buff[1] = '-';
    if (S_IXUSR & mode)
        buff[2] = 'w';
    else
        buff[2] = '-';
    if (S_IXUSR & mode)
        buff[3] = 'x';
    else
        buff[3] = '-';
    if (S_IRGRP & mode)
        buff[4] = 'r';
    else
        buff[4] = '-';
    if (S_IWGRP & mode)
        buff[5] = 'w';
    else
        buff[5] = '-';
    if (S_IXGRP & mode)
        buff[6] = 'x';
    else
        buff[6] = '-';
    buff[7] = '-';
    buff[8] = '-';
    buff[9] = '-';
}*/

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
    struct stat* buf = (struct stat*) calloc (1, sizeof(*buf));
    char * buff;

	if ((flag_a == 1) && (flag_l == 0))
    {
        while ((dirs = readdir(k)) != NULL)
        {
            
            printf("%s ", dirs->d_name);
        }
    }
    
    if ((flag_a == 0) && (flag_l == 0))
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

    if ((flag_a == 1) && (flag_l == 1))
    {
        while ((dirs = readdir(k)) != NULL)
        {
  
            printf("%s ", dirs->d_name);
            stat(dirs->d_name,  buf);
    printf((S_ISDIR(buf->st_mode))  ? "d" : "-"); 
    printf((buf->st_mode & S_IRUSR) ? "r" : "-");
    printf((buf->st_mode & S_IWUSR) ? "w" : "-");
    printf((buf->st_mode & S_IXUSR) ? "x" : "-");
    printf((buf->st_mode & S_IRGRP) ? "r" : "-");
    printf((buf->st_mode & S_IWGRP) ? "w" : "-");
    printf((buf->st_mode & S_IXGRP) ? "x" : "-");
    printf((buf->st_mode & S_IROTH) ? "r" : "-");
    printf((buf->st_mode & S_IWOTH) ? "w" : "-");
    printf((buf->st_mode & S_IXOTH) ? "x " : "- ");
                    printf("%d ", buf->st_nlink);
                    printf("%d ", buf->st_gid);
                    printf("%d ", buf->st_rdev);
                    printf("%d ", buf->st_blocks);
                    printf("%d ", buf->st_atime);
                    printf("%d \n", buf->st_ctime);
        }
    }



    if ((flag_a == 0) && (flag_l == 1))
    {
      
        if (argv[optind] == NULL)
        {
            while ((dirs = readdir(k)) != NULL)
            {
            
                if ('.' != dirs->d_name[0])
                {

                    printf("%s ", dirs->d_name);
                    stat(dirs->d_name,  buf);
    printf((S_ISDIR(buf->st_mode))  ? "d" : "-"); 
    printf((buf->st_mode & S_IRUSR) ? "r" : "-");
    printf((buf->st_mode & S_IWUSR) ? "w" : "-");
    printf((buf->st_mode & S_IXUSR) ? "x" : "-");
    printf((buf->st_mode & S_IRGRP) ? "r" : "-");
    printf((buf->st_mode & S_IWGRP) ? "w" : "-");
    printf((buf->st_mode & S_IXGRP) ? "x" : "-");
    printf((buf->st_mode & S_IROTH) ? "r" : "-");
    printf((buf->st_mode & S_IWOTH) ? "w" : "-");
    printf((buf->st_mode & S_IXOTH) ? "x " : "- ");
                    printf("%d ", buf->st_nlink);
                    printf("%d ", buf->st_gid);
                    printf("%d ", buf->st_rdev);
                    printf("%d ", buf->st_blocks);
                    printf("%d ", buf->st_atime);
                    printf("%d \n", buf->st_ctime);
                }
            
            }
        }
        
        if((argv[optind] != NULL) && (strcmp(".", argv[optind]) == 0))
        {
            while ((dirs = readdir(k)) != NULL)
            {
                if ('.' != dirs->d_name[0])
                {
                    printf("%s ", dirs->d_name);
                    stat(dirs->d_name,  buf);
    printf((S_ISDIR(buf->st_mode))  ? "d" : "-"); 
    printf((buf->st_mode & S_IRUSR) ? "r" : "-");
    printf((buf->st_mode & S_IWUSR) ? "w" : "-");
    printf((buf->st_mode & S_IXUSR) ? "x" : "-");
    printf((buf->st_mode & S_IRGRP) ? "r" : "-");
    printf((buf->st_mode & S_IWGRP) ? "w" : "-");
    printf((buf->st_mode & S_IXGRP) ? "x" : "-");
    printf((buf->st_mode & S_IROTH) ? "r" : "-");
    printf((buf->st_mode & S_IWOTH) ? "w" : "-");
    printf((buf->st_mode & S_IXOTH) ? "x " : "- ");
                    printf("%d ", buf->st_nlink);
                    printf("%d ", buf->st_gid);
                    printf("%d ", buf->st_rdev);
                    printf("%d ", buf->st_blocks);
                    printf("%d ", buf->st_atime);
                    printf("%d \n", buf->st_ctime);                
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
                    stat(dirs->d_name,  buf);
    printf((S_ISDIR(buf->st_mode))  ? "d" : "-"); 
    printf((buf->st_mode & S_IRUSR) ? "r" : "-");
    printf((buf->st_mode & S_IWUSR) ? "w" : "-");
    printf((buf->st_mode & S_IXUSR) ? "x" : "-");
    printf((buf->st_mode & S_IRGRP) ? "r" : "-");
    printf((buf->st_mode & S_IWGRP) ? "w" : "-");
    printf((buf->st_mode & S_IXGRP) ? "x" : "-");
    printf((buf->st_mode & S_IROTH) ? "r" : "-");
    printf((buf->st_mode & S_IWOTH) ? "w" : "-");
    printf((buf->st_mode & S_IXOTH) ? "x " : "- ");
                    printf("%d ", buf->st_nlink);
                    printf("%d ", buf->st_gid);
                    printf("%d ", buf->st_rdev);
                    printf("%d ", buf->st_blocks);
                    printf("%d ", buf->st_atime);
                    printf("%d \n", buf->st_ctime);
                }
            }  
        }
        
    }



	return 0;
}

