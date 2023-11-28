/* TEST CASE
	T = insert_node(12,T);
	T = insert_node(34,T);	
	T = insert_node(53,T);
	T = insert_node(76,T);
	T = insert_node(15,T);
	T = insert_node(21,T);
	T = insert_node(18,T);	
	T = insert_node(45,T);
	T = insert_node(16,T);
	T = insert_node(55,T);	
	T = insert_node(11,T);
*/

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

