#include <stdlib.h>
#include <stdio.h>


struct Element{
	int row,column,value;
	struct Element *down,*right;
};
typedef struct Element node;
typedef node *link;


/* Insert node row*/
link insertnode(link headrow,link headcolumn,int RNum,int CNum,int row,int column,int value){
	
	link ptr,ptr2,new;


	/* Memory Allocation */
	new=(link)malloc(sizeof(node));
	// Save Data
	new->row=row;
	new->column=column;
	new->value=value;



	/* Insert column node of row list */
	ptr=headrow;
	while(ptr->column < column && ptr->right != headrow){
		ptr=ptr->right;
	}

	// link the last node
	if (ptr->column < column && column <= CNum){
		new->right=headrow;
		ptr->right=new;
	}
	// link the middle node
	else if (ptr->column > column && column <= CNum){
		new->right=ptr->right;
		ptr->right=new;
	}
	else{
		ptr->value=new->value;
	}

	/* Insert row node of column list */
	ptr2=headcolumn;
	while(ptr2->row < row && ptr2->down != headcolumn){
		ptr2=ptr2->down;
	}

	// link the last node
	if (ptr2->row < row && row <= RNum){
		new->down=headcolumn;
		ptr2->down=new;
	}
	// link the middle node
	else if (ptr2->row > row && row <= RNum){
		new->down=ptr2->down;
		ptr2->down=new;
	}
	else{
		ptr2->value=new->value;
	}




	return headrow,headcolumn;


}









int main(){

	int i,j,k;
	int select;
	int row,column,value;
	int RNum,CNum;
	link ptr,ptr2,prev;
	
	/* Decide sparse matrix size */
	do{
	printf("Enter the size of sparse matrix:(Row Column)");
	scanf("%d %d",&RNum,&CNum);
	}while(RNum > 10 || CNum > 10);

	printf("==============================\n");
	for (i=0;i<RNum;i++){
	printf("[ ");
		for (j=0;j<CNum;j++){
			printf("0 ");
		}
	printf("]\n");
	}



	/* Set head node*/
	link head[RNum+CNum];
	// Memory Allocation
	for (i=0;i<RNum+CNum;i++){
		head[i]=(link)malloc(sizeof(node));	
	}
	
	for (i=0;i<RNum+CNum;i++){
		
		head[i]->row=0;
		head[i]->column=0;
		
		// row head
		if (i>=0 && i < RNum){
			head[i]->right=head[i];
			if (i==RNum-1)
				head[i]->down=head[0];
			else
				head[i]->down=head[i+1];		
		}
		// column head
		else{
			head[i]->down=head[i];
			if (i==RNum+CNum-1)
				head[i]->right=head[RNum];
			else
				head[i]->right=head[i+1];
		}

	}


	/* Add element of sparse matrix*/
	do{
	printf("(1)Add (2)Leave:");
	scanf("%d",&select);
	}while(select > 2 || select < 1);

	while(select!=2){

		printf("Add postion(row column):");
		scanf("%d %d",&row,&column);
		printf("Add value:");
		scanf("%d",&value);


		// Insert node
insertnode(head[row-1],head[RNum+column-1],RNum,CNum,row,column,value);


		do{
		printf("(1)Add (2)Leave:");
		scanf("%d",&select);
		}while(select > 2 || select < 1);

	}

	/* Print sparse array (by row vector)*/
	printf("==============================\n");
	printf("Sparse Matrix:\n");
	for (i=0;i<RNum;i++){
		printf("[ ");
		for (j=0;j<CNum;j++){
			ptr=head[i];
			while(ptr->column != j+1 && ptr->right != head[i]){
				ptr=ptr->right;
			}
			if (ptr->column == j+1)
				printf("%d ",ptr->value);
			else
				printf("0 ");
		}
		printf("]\n");
	}


	/* Print transpose sparse array (by column vector) */
	printf("==============================\n");
	printf("Transpose Sparse Matrix:\n");
	for (i=RNum;i<RNum+CNum;i++){
		printf("[ ");
		for (j=0;j<RNum;j++){
			ptr=head[i];
			while(ptr->row != j+1 && ptr->down != head[i]){
				ptr=ptr->down;
			}
			if (ptr->row == j+1)
				printf("%d ",ptr->value);
			else
				printf("0 ");
		}
		printf("]\n");
	}



	/* Free Memory */
	// free row link
	for (i=0;i<RNum;i++){
		ptr=head[i];
		while (ptr->right!=head[i]){
			prev=ptr;
			ptr=ptr->right;
			free(prev);
		}
	}
	// free column link
	for (i=RNum;i<RNum+CNum;i++){
		free(head[i]);
	}


	return 0;

}



