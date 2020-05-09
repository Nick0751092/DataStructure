#include <stdlib.h>
#include <stdio.h>
#define MAXSTACK 8

int top=-1;
int stack[MAXSTACK];

/* Check stack is empty or not */
int isempty(){
	if (top==-1)
		return 1;
	else
		return 0;
}


/* Pop data from stack */
int pop(){

	/* Stack is empty */
	if (isempty()==1){
		printf("Stack is empty.\n");
		return -1;
	}
	else
		return stack[top--];

}


/* Push data to stack */
int push(int pushData){

	/* Stack is full */
	if (top == MAXSTACK-1){
		printf("Stack is full.\n");
		return -1;
	}
	else{
		top=top+1;
		stack[top]=pushData;
		return stack[top];
	}

}


int main(){

	int select;
	int popData,pushData;
	int k;

	do{
		printf("Select action(0:pop 1:push 2:leave):");
		scanf("%d",&select);
	}while(select < 0 || select > 2);

	while(select != 2){

		/* pop data */
		if (select == 0){
			popData=pop();
			printf("Pop data:%d\n",popData);
		}
		/* push data */
		else if (select == 1){
			printf("Push data:");
			scanf("%d",&pushData);
			push(pushData);
		}
		
		/* Print stack */	
		k=top;
		while(k>=0){
			printf("[ %d ]\n",stack[k]);
			k=k-1;
		}

		printf("========================\n");
		
		/* Select action */
		do{
			printf("Select action(0:pop 1:push 2:leave):");
			scanf("%d",&select);
		}while(select < 0 || select > 2);

	}


	return 0;
}
