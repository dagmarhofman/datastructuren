#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    t_queue *queue;

    //stack of 4kb pages!
    queue=(t_queue *)t_queue_create(4096);

    char buf[4096];
    int i;
    char *data;

    bzero(buf,4096);

    strcpy(buf, " aap.");
    for(i=0;i<=15;i++) {
	printf("%i\n", i );
        t_queue_enqueue(queue, buf );
	sprintf(buf, "- %i - \n",i);
    }


    while( queue->sp > 0 ) {
	data = 	(char *)t_queue_dequeue(queue);
        printf("%s\n", data);
	free(data);
    }


    t_queue_destroy(queue);

}