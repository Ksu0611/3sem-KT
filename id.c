#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

int main()
{
	int id = getuid();
	int group_id = getgid();
	struct passwd * ppp = getpwuid(id);
	struct group * ggg = getgrgid(group_id);
	struct group * uuu = getgrent();
	int i = 0;

	printf("uid=%d(%s) gid=%d(%s) группы=%d(%s) ", id, ppp->pw_name, getgid(), ppp->pw_name, ggg->gr_gid, ppp->pw_name);
	while((uuu != NULL))
	{
		while (*uuu->gr_mem != NULL)
		{
			if (strcmp(ppp->pw_name, *uuu->gr_mem) == 0)
			{
				printf("%d(%s) ", uuu->gr_gid, uuu->gr_name);
				uuu->gr_mem++;
			}
			else
				uuu->gr_mem++;
		}
		getgrent();

	}
	return 0;
}