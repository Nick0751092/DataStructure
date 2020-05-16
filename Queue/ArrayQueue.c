#include <stdlib.h>
#include <stdio.h>

# define MAXSIZE 1024
int front = -1;
int rear = -1;
int Queue[MAXSIZE];

void PushQueue(int data){
	/* whether queue is full */
	if (rear == MAXSIZE - 1)
		printf("Queue is full.\n");
	else{	
		rear ++;
		Queue[rear] = data;
	}
}

int PopQueue(){
	int data;
	if (front == rear){
		printf("Queue is empty.\n");
		return -1;
		}
	else{
		return Queue[++front];
	}
}

int main(){
	int select, PushData, PopData, frontRecord;
	int i, j;

	do{
		printf("Select action(0:pop 1:push 2:leave):");
		scanf("%d",&select);
	}while(select < 0 || select > 2);

	while(select != 2){
		switch(select){
			/* pop data */
			case 0:
				PopData = PopQueue();
				/* print */
				i = rear;
				while (i > front){
					printf("[ %d ]\n",Queue[i]);	
					i--;				
				}
				printf("Pop Data: %d\n",PopData);
				break;
			/* push data */		
			case 1:
				printf("Push Data:");
				scanf("%d",&PushData);
				PushQueue(PushData);
				/* print */
				i = rear;
				while (i > front){
					printf("[ %d ]\n",Queue[i]);	
					i--;				
				}
				break;
		}
		do{
			printf("Select action(0:pop 1:push 2:leave):");
			scanf("%d",&select);
		}while(select < 0 || select > 2);
	}

	printf("============================\n");
	i = rear;
	while (i > front){
		printf("[ %d ]\n",Queue[i]);	
		i--;				
	}

	return 0;

}





