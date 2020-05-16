#include <stdlib.h>
#include <stdio.h>

struct Queue{
	int data;
	struct Queue *next;
	struct Queue *last;
};
typedef struct Queue node;
typedef node *link;

link front=NULL, rear=NULL;

/* Push Queue */
void PushQueue(int data){
	link new;
	new = (link)malloc(sizeof(node));
	/* Save data */
	new->data = data;
	new->next = NULL;
	/* link node */
	if (front == NULL){
		front = new;
		rear = new;
	}
	else{
		//new->last = rear;
		rear->next = new;
		rear = rear->next;
	}
}

/* Pop Queue */
int PopQueue(){
	link freeNode;
	int data;

	freeNode = front;
	/* whether Queue is empty */
	if (front == NULL){
		printf("Queue is empty.\n");
		return -1;
	}
	else{
		data = front->data;
		front = front->next;
		free(freeNode);
		return data;
	}

}

int main(){
	int select, PushData, PopData, frontRecord;
	int i, j;
	link ptr, prev;

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
				ptr = front;
				while (ptr != NULL){
					printf("[ %d ]\n",ptr->data);	
					ptr = ptr->next;				
				}
				printf("Pop Data: %d\n",PopData);
				break;

			/* push data */		
			case 1:
				printf("Push Data:");
				scanf("%d",&PushData);
				PushQueue(PushData);
				/* print */
				ptr = front;
				while (ptr != NULL){
					printf("[ %d ]\n",ptr->data);	
					ptr = ptr->next;				
				}
				break;
		}

		
		




		do{
			printf("Select action(0:pop 1:push 2:leave):");
			scanf("%d",&select);
		}while(select < 0 || select > 2);
	}

	printf("============================\n");
	/* print */
	ptr = front;
	while (ptr != NULL){
		printf("[ %d ]\n",ptr->data);	
		ptr = ptr->next;				
	}


	/* Free Memory */
	ptr = front;
	while (ptr != NULL){
		prev = ptr;	
		ptr = ptr->next;
		free(ptr);
	}


	return 0;

}





