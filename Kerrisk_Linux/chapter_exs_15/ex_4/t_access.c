#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "/home/code/Kerrisk_Linux/lib/tlpi_hdr.h"

void myaccess(const char *pathname, int mode, char *namemode);

int main(int argc, char *argv[]) 
{
	const char *filename = "testfile";
	char *readf = "Чтение";
	char *writef = "Запись";
	char *xusf = "Выполнение";
	
	if (access(filename, F_OK) == -1) 
		errExit("Файла не существует");
	
	myaccess(filename, R_OK, readf);
	myaccess(filename, W_OK, writef);
	myaccess(filename, X_OK, xusf);

	exit(EXIT_SUCCESS);
}

void myaccess(const char *pathname, int mode, char *namemode)
{
	if (access(pathname, mode) == -1) 
		printf("%s запрещно\n", namemode);
	else 
		printf("%s разрешено\n", namemode);
}

