#include <stdlib.h>
#include <stdio.h>
 
struct node{

	int data;
	int lBit, rBit;
	struct node *left;
	struct node *right;

};
typedef struct node tBtreeNode;
typedef tBtreeNode *tBtree;

tBtree rootNode;

void Add_tBtree(int data){

	/* Create New node */
	tBtree newNode;
	newNode = (tBtree)malloc(sizeof(tBtreeNode));
	newNode->data = data;
	newNode->lBit = 1;//thread
	newNode->rBit = 1;//thread	

	tBtree child;
	tBtree parent = NULL;

	/* Scan for parent */
	child = rootNode;
	while (child != NULL){
		parent = child;
		if (data < child->data){
			if (child->lBit == 0)
				child = child->left;
			else
				break;
		}
		else{
			if (child->rBit == 0)
				child = child->right;
			else
				break;
		}
	}

	/* Insert node */
	if (parent == NULL){
		rootNode = newNode;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	else{
		/* data smaller than parent->data */
		if (data < parent->data){
			newNode->left = parent->left;
			newNode->right = parent;

			parent->lBit = 0;
			parent->left = newNode;
		}
		/* data larger than or equal parent->data */
		else{
			newNode->left = parent;
			newNode->right = parent->right;

			parent->rBit = 0;
			parent->right = newNode;
		}
	}

}

void inorder(int DataSize){
	tBtree ptr;
	ptr = rootNode;

	if (ptr == NULL)
		printf("No Threaded Binary Tree!\n");
	else{
		while(ptr->lBit == 0)
			ptr = ptr->left;
		printf("[%d]",ptr->data);
		for(int i=0;i<DataSize-1;i++){
			/* find the next ptr */
			if (ptr->rBit == 1){
				ptr = ptr->right;
			}
			else{
				ptr = ptr->right;
				while(ptr->lBit == 0)
					ptr = ptr->left;
			}
			printf("[%d]",ptr->data);
		}
	}


}

int main(){
	
	int DataArray[] = {0,10,5,6,23,4,3,16};
	int DataSize = sizeof(DataArray)/sizeof(int);
	for (int i=0;i<DataSize;i++){
		Add_tBtree(DataArray[i]);
	}

	printf("=========================\n");
	printf("Sorted Array:\n");
 	inorder(DataSize);
	printf("\n=========================\n");
	return 0;
}







