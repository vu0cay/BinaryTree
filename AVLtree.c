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
	
	NLR(T); printf("\n");
	// case test xoa 45, 
	while(1){
		KeyType x;
		scanf("%d",&x);
		T = delete_node(x,T);
		NLR(T); printf("\n");
	}
	return 0;
}
/*
int n,i;
	scanf("%d",&n);
	for( i = 1; i<=n; i++) {
		int x; 
		scanf("%d",&x);
		T = insert_node(x,T);
	}
	NLR(T); printf("\n");
	while(1){
		printf("nhap ptu muon xoa ");
		KeyType del;
		scanf("%d",&del);
		T = delete_node(del,T);
		NLR(T); printf("\n");
	}
*/
