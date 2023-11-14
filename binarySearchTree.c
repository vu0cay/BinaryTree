/*
16
90 30 50 10 25 35 20 30 15 80 75 45 65 5 55 100
*/
#include "binarySearchTree.h"

int main(){
	int n;
	int i;
    scanf("%d",&n);
	Tree T;
	makenull(&T);
    KeyType A[n+1];
	for(i = 0; i<n; i++) {
		scanf("%d",&A[i]);
		InsertNode(A[i],&T);
	}
	NLR(T); printf("\n");
    deleteNode(35,&T);
    deleteNode(65,&T);
    InsertNode(43,&T);
    deleteNode(50,&T);
    NLR(T);
	return 0;
}
