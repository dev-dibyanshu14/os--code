#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int f1[2],f2[2],m,n;
	char buff[100];
	pid_t p;
	pipe(fd1);
	pipe(fd2);
	p=fork();
	if(p>0){
		close(fd1[0]);
		close(fd2[1]);
		printf("passing value to child-->pipe\n");
		write(fd[1],"hello\n",6);
		m=read()

