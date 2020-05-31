#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node btreenode;
typedef btreenode *btree;

btree root;

btree insert_btree(int data){
	btree ptr,parent;
	/* create new node */
	btree new;
	new = (btree)malloc(sizeof(btreenode));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	/* Insert new node */
	if (root == NULL){
		root = new;
		return root;
	}
	else{
		ptr = root;
		/* Scan for parent node */
		while(ptr != NULL){
			parent = ptr;
			if (data < ptr->data)
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		if (data < parent->data)
			parent->left = new;
		else
			parent->right = new;
		return root;
	}
}

void search_btree(int data){
	btree ptr;
	ptr = root;
	int times = 1;
	while(ptr != NULL){
		if (data < ptr->data){
			ptr = ptr->left;		
			times = times + 1;
		}
		else if (data > ptr->data){
			ptr = ptr->right;
			times = times + 1;
		}
		else{
			printf("Find %d in %d times.\n",data,times);		
			break;
		}
	}
	if (ptr == NULL){
		printf("Failed to find %d.\nNow insert %d.\n",data,data);
		insert_btree(data);
	}

}

void inorder(btree ptr){
	if(ptr != NULL){
		inorder(ptr->left);
		printf("[%d]",ptr->data);
		inorder(ptr->right);
	}
}

btree delete_btree(int data){
	btree ptr,parent;
	ptr = root;
	parent = ptr;
	/* Basic case */
	if (root == NULL)
		return root;

	/* Search data */
	while(ptr != NULL){
		if (data < ptr->data){
			parent = ptr;
			ptr = ptr->left;		
		}
		else if (data > ptr->data){
			parent = ptr;
			ptr = ptr->right;
		}
		else	
			break;
	}
	if (ptr == NULL){
		//printf("Failed to find %d.\n",data);
		return root;
	}
	
	/* No child */
	if (ptr->left == NULL && ptr->right == NULL){
		if (data < parent->data)
			parent->left = NULL;
		else
			parent->right = NULL;
		free(ptr);
		return root;
	}
	/* Only one child */
	else if ((ptr->left != NULL && ptr->right == NULL)||(ptr->left == NULL && ptr->right != NULL)){
		if (data < parent->data){
			if (ptr->left != NULL)
				parent->left = ptr->left;
			else
				parent->left = ptr->right;
		}
		else{
			if (ptr->left != NULL)
				parent->right = ptr->left;
			else
				parent->right = ptr->right;
		}
		free(ptr);
		return root;
	}
	/* Two children */	
	else{

		btree max,maxpar,tmp;
		max = ptr->left;
		if (max->right != NULL){
			while(max->right != NULL){
				maxpar = max;
				max = max->right;
			}
			maxpar->right = NULL;
		}
		/* Delete root node with two children */		
		if (parent == ptr){
			maxpar->right = NULL;
			max->left = ptr->left;
			max->right = ptr->right;
			root = max;
		}
		/* Delete other node with two children */
		else{
			max->right = ptr->right;
			if (data < parent->data)
				parent->left = max;
			else
				parent->right = max;
		}

		free(ptr);	
		return root;
	}	

}







int main(){
	int data[] = {5,10,2,3,6,7,1};
	int DataSize = sizeof(data)/sizeof(int);
	for(int i=0;i<DataSize;i++)
		root = insert_btree(data[i]);	
	inorder(root);
	printf("\n=================\n");	
	int select;
	int value;
	do{
		printf("Choose action(0:leave 1:insert 2:delete 3:search):");
		scanf("%d",&select);
	}while((select < 0)||(select > 3));
		
	while(select != 0){
		switch (select){
			case 1:
				printf("Insert Data:");
				scanf("%d",&value);
				root = insert_btree(value);
				inorder(root);
				printf("\n=================\n");
				break;
			case 2:
				printf("Delete Data:");
				scanf("%d",&value);
				root = delete_btree(value);
				inorder(root);
				printf("\n=================\n");
				break;
			case 3:
				printf("Search Data:");
				scanf("%d",&value);
				search_btree(value);
				printf("=================\n");
				break;
		}
		do{
			printf("Choose action(0:leave 1:insert 2:delete 3:search):");
			scanf("%d",&select);
		}while((select < 0)||(select > 3));

	}
	printf("=================\n");	
	inorder(root);
	printf("\n");	
	return 0;

}






