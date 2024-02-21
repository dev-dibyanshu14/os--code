#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int a, b;
	a = open("Input.txt", O_RDONLY | O_CREAT, 0777);
	char buff[1];
	char *c = buff;
	
	while((b = read(a, c, 1))>0){
		write(1, c, 1);
	}
	
	return 0;
}

