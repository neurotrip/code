#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
  pid_t pid;
  int rv = 0;
  int wstatus;

  switch(pid=fork()) {
  case -1:
          perror("fork"); /* произошла ошибка /
          exit(1); /выход из родительского процесса*/
  case 0:
          printf(" CHILD: Это процесс-потомок!\n");
          printf(" CHILD: Мой PID -- %d\n", getpid());
          printf(" CHILD: PID моего родителя -- %d\n", getppid());
          printf(" CHILD: Выход!\n");
		  char *newargv[] = { "less" , "test.txt", NULL };
	  	  char *filename = "/usr/bin/less";	  
		  execve(filename, newargv, NULL);
		  
          _exit(EXIT_SUCCESS);
  default:
          printf("PARENT: Это процесс-родитель!\n");
          printf("PARENT: Мой PID -- %d\n", getpid());
          printf("PARENT: PID моего потомка %d\n",pid);
          printf("PARENT: Я жду, пока потомок не вызовет exit()...\n");
		  wait(NULL);
          printf("PARENT: Код возврата потомка:%d\n", WEXITSTATUS(rv));
          printf("PARENT: Выход!\n");
  }
}
