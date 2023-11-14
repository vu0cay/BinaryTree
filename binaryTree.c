
#include "binaryTree.h"

int main(){
	Tree T;
	makenull(&T);
	DataType A_preOrder[] = {'A','B','C','D','E','F','H','K','G','J','I'};
	DataType A_inOrder[] = {'B','D','C','E','A','H','K','F','J','G','I'};
	DataType A_postOrder[] = {'D','C','F','E','B','G','K','I','J','H','A'};
	build_preOrder(A_preOrder,&T,0,10); NLR(T); printf("\n"); 
//	build_inOrder(A_inOrder,&T,0,10); LNR(T); printf("\n");
//	build_postOrder(A_postOrder,&T,0,10); LRN(T); printf("\n");
	
	
	
	return 0;
}
