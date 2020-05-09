#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct employee{
	int ID,salary;
	char name[10];
	struct employee *next;
};

typedef struct employee node;
typedef node *link;


/* find node */
link findnode(link head,int ID){
	link ptr;
	ptr=head;
	while(ptr!=NULL){
		if (ptr->ID==ID){
			return ptr;
		}
	ptr=ptr->next;
	}
	return ptr;
}


/* insert node*/
link insertnode(link head,link ptr,int ID,char name[10],int salary){
	
	link InsertNode;
	// Memory Allocation
	InsertNode=(link)malloc(sizeof(node));
	if (!InsertNode){
		printf("Error! Memory allocation failure.\n");
		exit(1);
	}
	// Save Data
	InsertNode->ID=ID;
	strcpy(InsertNode->name,name);
	InsertNode->salary=salary;
	InsertNode->next=NULL;
	// Insert node in front of the first node
	if (ptr==NULL){
		InsertNode->next=head;
		return InsertNode;
	}
	// Insert node behind the last node
	else if (ptr->next==NULL){
		ptr->next=InsertNode;
		return head;
	}
	// Insert node between the first node and the last node
	else{
		InsertNode->next=ptr->next;
		ptr->next=InsertNode;
		return head;
	}

}


/* remove node */
link removenode(link head,link ptr){
	
	link present;
	present=head;

	// remove the first node
	if (ptr->ID==head->ID){
		head=present->next;
	}
	else{
		while(present->next!=ptr){
			present=present->next;
		}
		// remove the last node
		if (ptr->next==NULL){
			present->next=NULL;
		}
		// remove the node between the first and the last one
		else{
			present->next=ptr->next;
			ptr->next=NULL;
		}
	}
	// free memory
	free(ptr);
	return head;

}


int main(){

	link head,ptr,new;
	link prev,present;



	int IDData[5]={1001,1003,1008,1011,1015};
	char nameData[5][10]={"Nick","Amy","Wolf","Jack","Mark"};
	int salaryData[5]={50000,40000,45000,32000,60000};

	int i;
	int select,IDSelect;
	int ID,salary;
	char name[10];

	// Memory Allocation
	head=(link)malloc(sizeof(node));
	// Save data to link node
	head->ID=IDData[0];
	strcpy(head->name,nameData[0]);
	head->salary=salaryData[0];
	head->next=NULL;

	ptr=head;

	for(i=1;i<5;i++){
		// Memory Allocation
		new=(link)malloc(sizeof(node));
		
		// Save data to link node
		new->ID=IDData[i];
		strcpy(new->name,nameData[i]);
		new->salary=salaryData[i];
		new->next=NULL;
		
		// connect link node
		ptr->next=new;
		ptr=ptr->next;
	}

	ptr=head;
	while(ptr!=NULL){
		printf("ID:%d Name:%s Salary:%d\n",ptr->ID,ptr->name,ptr->salary);
		ptr=ptr->next;
	}
	printf("==========================\n");
	printf("(1)Insert (2)Delete (3)Leave:");
	scanf("%d",&select);

	while(select!=3){

		printf("Select insert or delete ID:");
		scanf("%d",&IDSelect);
	
		// Find node
		ptr=findnode(head,IDSelect);

		if (select==1){
			
			// Get Data
			printf("New ID:");
			scanf("%d",&ID);
			printf("New name:");
			scanf("%s",name);
			printf("New Salary:");
			scanf("%d",&salary);
			
			// Insert node
			head=insertnode(head,ptr,ID,name,salary);

		}
		else if (select==2){

			// Delete node
			head=removenode(head,ptr);

		}


	printf("==========================\n");
	ptr=head;
	while(ptr!=NULL){
		printf("ID:%d Name:%s Salary:%d\n",ptr->ID,ptr->name,ptr->salary);
		ptr=ptr->next;
	}
	printf("==========================\n");
	printf("(1)Insert (2)Delete (3)Leave:");
	scanf("%d",&select);



	}
	
	/* free memory */
	present=head;
	while(present!=NULL){
		prev=present;
		present=present->next;
		free(prev);
	}

	return 0;
}




