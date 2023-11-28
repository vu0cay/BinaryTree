// NGUYEN HOANG VU 28-11-2023
// TEST CASE https://stackoverflow.com/questions/3955680/how-to-check-if-my-avl-tree-implementation-is-correct
#define el printf("\n") 
#include "AVL_tree.h"

int main(){
	
	AVLTree T;
	T = NULL;	
	int loop = 1;
	while(loop){
		int opt;
		printf("opt = 1 InsertNode x to Tree, opt = 2 deleteNode x from Tree, opt = 0 Exit!\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:{
				fflush(stdin);
				KeyType x; 
				printf("Insert Node x = ");
				scanf("%c",&x);		
				fflush(stdin);
				T = insert_node(x,T);
				printf("cay AVL vua tao la =\n");
				NLR(T); 
			}	break;
			case 2:{
				fflush(stdin);
				KeyType x; 
				printf("Delete Node x = ");
				scanf("%c",&x);
				fflush(stdin);
				T = delete_node(x,T);	
				printf("cay AVL sao khi xoa =\n"); NLR(T); printf("\n");
			}
				break;
			case 0:
				loop = 0;
				break;
		}
		printf("\n");	
	}
	
	return 0;
}

