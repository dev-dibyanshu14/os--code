#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>

int main()
{
	int a = mkdir("My_Directory",0777);
	if(a!=-1)
	{
		printf("# You're directory has been created: \n");
		printf(" \n");
	}

	struct dirent *dptr;
		
	int fd1 = creat("My_Directory/dev1.txt",0777);
	int fd2 = creat("My_Directory/dev2.txt",0777);
	int fd3 = creat("My_Directory/dev3.txt",0777);
	
	if(fd1!=-1 && fd2!=-1 && fd3!=-1)
	{
		printf("* dev1.txt is created.\n");
		printf("* dev2.txt is created.\n");
		printf("* dev3.txt is created.\n");
		printf(" \n");
	}
	
	DIR *dp = opendir("My_Directory");
	
	printf("@ List of files in created directory: \n");
	
	while(NULL!=(dptr = readdir(dp)))
	{
		printf("%s\n", dptr->d_name);
	}
	return 0;
}

