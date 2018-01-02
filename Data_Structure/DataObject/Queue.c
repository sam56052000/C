#include "stdio.h"
#include "stdlib.h"

#define USE_STATIC_QUEUE	0
#define USE_CIRCULAR_QUEUE	0
#define USE_DYNAMIC_QUEUE 	1

#define MAXSIZE	4
#define SUCCESS	0
#define FAILED	1

void QueueDataCopy(int source_start, int source_end, int *trg_addr)
{
	int i = (source_end - source_start) / sizeof(int);

	do
	{
		*( trg_addr++ ) = *((int *)source_start);

		source_start += sizeof(int);
	}
	while(--i != 0);
}

typedef struct 
{
	int *addr;
	int rear;
	int front;

	#if USE_DYNAMIC_QUEUE
	 int size;
	#endif

} Queue_t;

void CreatQueue(Queue_t *Queue)
{
	#if USE_DYNAMIC_QUEUE
	 Queue -> size = 4;
	 Queue -> addr = (int *)(malloc(Queue -> size * sizeof(int)));
	#else
	 Queue -> addr = (int *)(malloc(MAXSIZE * sizeof(int)));
	#endif

	#if USE_STATIC_QUEUE
	 Queue -> rear	= -1;
	 Queue -> front = -1;
	#else
	 Queue -> rear	= 0;
	 Queue -> front = 0;
	#endif
}

int IsQueueFull(Queue_t *Queue)
{
 	#if USE_STATIC_QUEUE
	 if(Queue -> rear == MAXSIZE)
	#else
	 if(Queue -> rear == Queue -> front)
	#endif

	#if USE_DYNAMIC_QUEUE
	 {
	 	int *newaddr;
	 	int start = (Queue -> front + 1) % Queue -> size;

	 	newaddr = (int *)(malloc(Queue -> size * 2 * sizeof(int)));

	 	if(start < 2)
	 	/* Queue not wrap around*/
	 	{
	 		int start_addr = (int)(Queue -> addr + start);
	 		int end_addr = (int)(Queue -> addr + start + Queue -> size - 1);
	 		QueueDataCopy(start_addr, end_addr, newaddr);
	 	}
	 	else
	 	/* Queue wrap around*/
	 	{
	 		int start_addr = (int)(Queue -> addr + start);
	 		int end_addr = (int)(Queue -> addr + start + Queue -> size);
	 		QueueDataCopy(start_addr, end_addr, newaddr);
	 		start_addr = (int)(Queue -> addr);
	 		end_addr = (int)(Queue -> addr + Queue -> rear + 1);
	 		QueueDataCopy(start_addr, end_addr, newaddr + Queue -> size - start);
	 	}

	 	Queue -> front = 2 * Queue -> size - 1;
	 	Queue -> rear = Queue -> size - 2;
	 	Queue -> size *= 2;

	 	free(Queue -> addr);
	 	Queue -> addr = newaddr;
	 }
	#else
	 {
		printf("Queue is Full\n");

		return FAILED;
	 }
	#endif

	return SUCCESS;
}

void Queue_Put(Queue_t *Queue, int input)
{
 	#if USE_STATIC_QUEUE
	 Queue -> rear += 1;
 	#else
	 #if USE_DYNAMIC_QUEUE
	  Queue -> rear = (Queue -> rear + 1) % Queue -> size;
	 #else
	  Queue -> rear = (Queue -> rear + 1) % MAXSIZE;
	 #endif
 	#endif
	
	if(!IsQueueFull(Queue))
		Queue -> addr [ Queue -> rear ] = input;
}


int IsQueueEmpty(Queue_t *Queue)
{	
	if(Queue -> rear == Queue -> front)
	{
		printf("Queue is Empty\n");

		return FAILED;
	}

	return SUCCESS;
}

int Queue_Pop(Queue_t *Queue)
{
	if(!IsQueueEmpty(Queue))
	{
		#if USE_STATIC_QUEUE
		 Queue -> front += 1;
		#else
		 #if USE_DYNAMIC_QUEUE
	  	  Queue -> front = (Queue -> front + 1) % Queue -> size;
	 	 #else
	  	  Queue -> front = (Queue -> front + 1) % MAXSIZE;
	 	 #endif
		#endif

		return Queue -> addr [ Queue -> front ];
	}
}

main()
{
	Queue_t Queue1;

	CreatQueue(&Queue1);

	Queue_Put(&Queue1, 1);
	printf("rear = %d, front = %d\n", Queue1.rear, Queue1.front);
	Queue_Put(&Queue1, 2);
	printf("rear = %d, front = %d\n", Queue1.rear, Queue1.front);
	Queue_Put(&Queue1, 3);
	printf("rear = %d, front = %d\n", Queue1.rear, Queue1.front);
	printf("%d\n", Queue_Pop(&Queue1));
	printf("rear = %d, front = %d\n", Queue1.rear, Queue1.front);
	Queue_Put(&Queue1, 4);
	printf("rear = %d, front = %d\n", Queue1.rear, Queue1.front);


	printf("%d\n", Queue_Pop(&Queue1));
	printf("rear = %d, front = %d\n", Queue1.rear, Queue1.front);
	printf("%d\n", Queue_Pop(&Queue1));
	printf("rear = %d, front = %d\n", Queue1.rear, Queue1.front);
	printf("%d\n", Queue_Pop(&Queue1));
	printf("rear = %d, front = %d\n", Queue1.rear, Queue1.front);
}