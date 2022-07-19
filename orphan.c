#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int status;

    printf("%s\n", "Text before forking");

    int re = fork();

    if (re < 0)
    {
        printf("%s\n", "fork failed");
    }

    else if (re == 0)
    {
        //        execlp("ls", "", NULL);
        sleep(10);
        printf("%s %d %s %d\n", "I am the child with pid :", getpid(), "with parents pid:", getppid());
    }

    else
    {
        // sleep(10);
        // re = wait(&status);
        printf("%s %d %s %d\n", "I am the parent with pid:", getpid(), "and got child's pid:", re);
    }

    return 0;
}
