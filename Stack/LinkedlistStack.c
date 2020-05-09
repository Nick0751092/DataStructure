#include <stdlib.h>
#include <stdio.h>

struct Stack{
	int data;
	struct Stack *down;
};

typedef struct Stack node;
typedef node *link;

link top=NULL;

/* Check stack is empty or not */
int isempty(){

	/* Stack is empty */	
	if (top==NULL)
		return 1;
	/* Stack is not empty */
	else
		return 0;

}


/* Pop data from stack */
int pop(){

	int popData;
	link tmp;

	if (isempty(top)==1){
			printf("Stack is empty.\n");
			return -1;
		}
	else{
			tmp=top;
			top=top->down;
			popData=tmp->data;
			free(tmp);
			return popData;
		}

}


/* Push data to stack */
void push(int pushData){

	link new;
	/* Memory allocation */
	new=(link)malloc(sizeof(node));
	/* Save data */
	new->data=pushData;
	new->down=top;
	/* Link node */
	top=new;

}




int main(){

	link ptr,tmp;
	int select;
	int popData,pushData;

	do{
		printf("Select action(0:pop 1:push 2:leave):");
		scanf("%d",&select);
		if (select < 0 || select > 2)
			printf("\n");
	}while(select < 0 || select > 2);
	

	while(select != 2){

		/* pop data */
		if (select == 0){
			popData=pop();
			if (popData != -1)
				printf("Pop data:%d\n",popData);
		}
		/* push data */
		else if (select == 1){
			printf("Push data:");
			scanf("%d",&pushData);
			push(pushData);
		}
		
		/* Print stack */
		ptr=top;		
		while(ptr!=NULL){
			printf("[ %d ]\n",ptr->data);
			ptr=ptr->down;
		}

		printf("========================\n");
		
		/* Select action */
		do{
			printf("Select action(0:pop 1:push 2:leave):");
			scanf("%d",&select);
			if (select < 0 || select > 2)
				printf("\n");
		}while(select < 0 || select > 2);

	}


	/* Free memory */
	ptr=top;
	while(ptr!=NULL){
		tmp=ptr;
		ptr=ptr->down;
		free(tmp);
	}

	return 0;
}
