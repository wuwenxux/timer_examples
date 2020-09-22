#include <signal.h>
#include <bits/sigaction.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
static char msg[] = "I received a msg.\n";
int len;
static time_t  lasttime;
void show_msg(int signo)
{
    write(STDERR_FILENO,msg,len);
} 
int main()
{
    struct sigaction act;
    union sigval tsval;
    act.sa_handler = show_msg;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(50,&act,NULL);
    len = strlen(msg);
    time(&lasttime);
    while(1)
    {
        time_t nowtime;
        time(&nowtime);
        if(nowtime - lasttime >= 3)
        {
            sigqueue(getpid(),50,tsval);
            lasttime = nowtime;
        }
    }
    return 0;
}