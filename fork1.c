#include<stdio.h>
void main()
{
    int pid1,pid2,pid3,pid4;

    printf("Parent ID is >> %d << Root ID is >> %d << \n",getpid(),getppid());
    pid2=fork();
    pid1=fork();

    if(pid1 == 0)
        printf("Process 1 ID >> %d << Parent ID >> %d <<\n",getpid(),getppid());

    if(pid2==0)
    {

        printf("Process 2 ID >> %d << Parent ID is >> %d <<\n",getpid(),getppid());

        pid3=fork();
        pid4=fork();

        if(pid3==0)
            printf("Process 3 ID >> %d << Parent ID is >> %d <<\n",getpid(),getppid());

        if(pid4==0)
            printf("Process 4 ID >> %d << Parent ID is >> %d <<\n",getpid(),getppid());

    }
}
