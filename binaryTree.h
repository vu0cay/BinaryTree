#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef char DataType;
typedef struct Nodetag{
	DataType data;	
	struct Nodetag* left;
	struct Nodetag* right;
} Node;
typedef Node* Tree;
void makenull(Tree *pT){
	(*pT) = NULL;
}
bool isEmpty(Tree T){
	return T == NULL;
}
Tree Create(DataType v, Tree l, Tree r){
	Tree n = (Node*)malloc(sizeof(Node));
	n->data = v;
	n->left = l;
	n->right = r;
	
	return n;
}
Tree LeftChild(Tree n){
	if(!isEmpty(n)) return n->left;
	else return NULL;
}
Tree RightChild(Tree n){
	if(!isEmpty(n)) return n->right;
	else return NULL;
}
bool IsLeaf(Tree n){
	if(n != NULL)
		return (LeftChild(n) == NULL) && (RightChild(n) == NULL);
	
	return 0;
}
int nb_nodes(Tree T){
	if(isEmpty(T)) return 0;
	return 1 + nb_nodes(LeftChild(T)) + nb_nodes(RightChild(T));
}

void build_preOrder(DataType A[],Tree *pT,int l,int r){
	if(l > r) return;
	
	int mid = (l+r)/2;

	(*pT) = Create(A[l],NULL,NULL);
	
	build_preOrder(A,&(*pT)->left,l+1,mid);
	build_preOrder(A,&(*pT)->right,mid+1,r);
}
void build_inOrder(DataType A[],Tree *pT,int l,int r){
	if(l > r) return;
	
	int mid = (l+r)/2;

	(*pT) = Create(A[mid],NULL,NULL);
	
	build_inOrder(A,&(*pT)->left,l,mid-1);
	build_inOrder(A,&(*pT)->right,mid+1,r);
}
void build_postOrder(DataType A[],Tree *pT,int l,int r){
	if(l > r) return;
	
	int mid = (l+r)/2;

	(*pT) = Create(A[r],NULL,NULL);
	
	build_postOrder(A,&(*pT)->left,l,mid-1);
	build_postOrder(A,&(*pT)->right,mid,r-1);
}
// PreOrder (nLR)
void NLR(Tree n){
	if(!isEmpty(n)){
		printf("%c ",n->data);
		NLR(LeftChild(n));
		NLR(RightChild(n));
	}
}
// InOrder (LnR);
void LNR(Tree n){
	if(!isEmpty(n)){
		LNR(LeftChild(n));
		printf("%c ",n->data);
		LNR(RightChild(n));
	}
}
// PostOrder (LRn);
void LRN(Tree n){
	if(!isEmpty(n)){
		LRN(LeftChild(n));
		LRN(RightChild(n));
		printf("%c ",n->data);
	}
}



