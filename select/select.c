#include <time.h>
#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
struct sigevent
{
    int sigev_notify;
    int sigev_signo;

    union sigval sigev_vaule;
    void (*sigev_notify_function)(union sigval);
    pthread_attr_t *sigev_notify_attributes;
}
union sigval 
{
    int sigval_int;
    void *sigval_ptr;
}
int main(void)
{
    fd_set rfds;
    struct timeval tv;
    int retval;

    /*Watch stdin to see when it has input. */
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    /*Wait up to five seconds. */
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    retval = select(1, &rfds, NULL, NULL, &tv);

    if(retval == -1 )
        perror("select()");
    else if (retval)
        printf("Data is available now. \n");
        /* FD_ISSET(0,&rfds) will be true.*/
    else 
        printf("No data within five seconds.\n");
    
    exit(EXIT_SUCCESS);

}
