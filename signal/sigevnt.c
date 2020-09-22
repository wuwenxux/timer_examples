#include <stdio.h>
#include <signal.h>
void handle_sigint(int sig)
{
    printf("Caught signale %d\n",sig);    
}
int main()
{   
    while(1)
    {
        printf("Hello world!\n");
        sleep(1);
        signal(SIGINT,handle_sigint);
    }
    return 0;
}
