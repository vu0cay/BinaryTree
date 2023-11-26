#define el printf("\n") 
#include "AVL_tree.h"

int main(){
	
	AVLTree T;
	T = NULL;
	
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
	
	printf("cay AVL vua tao la =\n");
	NLR(T); printf("\n");

	while(1){
		KeyType x;
		printf("Nhap gia tri phan tu trong cay AVL can xoa = ");
		scanf("%d",&x);
		T = delete_node(x,T);
		printf("cay AVL sao khi xoa =\n"); NLR(T); printf("\n");
	}
	return 0;
}
