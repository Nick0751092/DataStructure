#include <stdlib.h>
#include <stdio.h>

int main(){

	int select;

	struct student{
		char name[10];
		char stdID[7];
		int Eng;
		int Math;
		struct student *next;
	};
	typedef struct student LinkedList;
	LinkedList *ptr;// Read present ptr
	LinkedList *head;// Head ptr
	LinkedList *dataNew;// New ptr
	LinkedList *prev;// Previous ptr

	// Memory allocation for head ptr
	head=(LinkedList*) malloc(sizeof(LinkedList));
	// Set next ptr of head ptr to NULL
	head->next=NULL;
	// Present ptr == head ptr
	ptr=head;
	

	/* Record next of present ptr-> Set next of new ptr to NULL -> Move present ptr to new ptr*/
	do{

	printf("(1)Add (2)Leave:");
	scanf("%d",&select);
	if (select == 1)
	{
		// Memory allocation for new ptr
		dataNew=(LinkedList*) malloc(sizeof(LinkedList));
		printf("Name ID Eng Math:");
		// Write data to new ptr
		scanf("%s %s %d %d",dataNew->name,dataNew->stdID,&dataNew->Eng,&dataNew->Math);
		// head ptr->next == dataNew
		ptr->next=dataNew;
		//	Set next ptr of head ptr to NULL
		dataNew->next=NULL;
		// Move present ptr to new ptr
		ptr=ptr->next;
	}
	}while(select!=2);


	printf("===========================\n");
	/* Read data by moving struct ptr*/
	ptr=head->next;
	while(ptr != NULL)
	{
	// Print data of present ptr
	printf("Name:%s ID:%s Eng:%d Math:%d\n",ptr->name,ptr->stdID,ptr->Eng,ptr->Math);

	// Move present ptr to next ptr
	ptr=ptr->next;

	}


	/* Free Memory */
	ptr=head;
	while(ptr!=NULL){
	prev=ptr;
	ptr=ptr->next;
	free(prev);
	}

	return 0;

}
