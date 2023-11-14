#include "binarySearchTree.h"

int main(){
	int n; 
	int i;
	KeyType A[n+1];
	Tree T;
	makenull(&T);
	scanf("%d",&n);
	for(i = 0; i<n; i++) {
		scanf("%d",&A[i]);
		insertNode(A[i],&T);
	}
	NLR(T); printf("\n"); // preOrder
	LNR(T); printf("\n"); // inOrder
	LRN(T); printf("\n"); // postOrder
	printf("\n");
	deleteNode(10,&T);
	NLR(T); printf("\n"); // preOrder
	LNR(T); printf("\n"); // inOrder
	LRN(T); printf("\n"); // postOrder
	return 0;
}
