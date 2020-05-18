#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 8
int Queue[MAXSIZE];
int front = -1, rear = -1;

void PushQueue(int data){
	rear = (rear + 1) % MAXSIZE;
	/* whether Queue is full*/	
	if (rear == front){
		printf("Queue is full.\n");
		rear = rear - 1;
	}
	else{
		Queue[rear] = data;
	}
}


int PopQueue(){
	int data;
	/* whether Queue is full */	
	if (rear == front){
		printf("Queue is empty.\n");
		return -1;
	}
	else{
		data = Queue[front + 1];
		front = (front + 1) % MAXSIZE;
		return data;
	}
}

int main(){
	int select, PushData, PopData;
	int i;
	do{
		printf("Select ation(0:pop 1:push 2:leave):");
		scanf("%d",&select);
	}while(select < 0 || select > 2);


	while(select != 2){

		switch (select){
			/* Pop data */			
			case 0:
				PopData = PopQueue();
				i=rear;
				while(i > front){
					printf("[ %d ]\n",Queue[i]);
					i--;
				}
				printf("Pop data: %d\n",PopData);
				break;
			/* Push data*/
			case 1:
				printf("Push Data:");
				scanf("%d",&PushData);
				PushQueue(PushData);
				i=rear;
				while(i > front){
					printf("[ %d ]\n",Queue[i]);
					i--;
				}
				break;
		}

		do{
			printf("Select ation(0:pop 1:push 2:leave):");
			scanf("%d",&select);
		}while(select < 0 || select > 2);


	}

	printf("=======================\n");
	i=rear;
	while(i > front){
		printf("[ %d ]\n",Queue[i]);
		i--;
	}




	return 0;
}
