#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int KeyType;
typedef struct Nodetag{
	KeyType Key;
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
Tree Create(KeyType x,Tree l,Tree r){
	Tree N = (Node*)malloc(sizeof(Node));
	N->Key = x;
	N->left = l;
	N->right = r;

	return N;
}
KeyType RootKey(Tree T){
	return T->Key;
}
Tree LeftChild(Tree T){
	return T->left;
}
Tree RightChild(Tree T){
	return T->right;
}
bool isLeaf(Tree T){
	return (LeftChild(T) == NULL) && (RightChild(T) == NULL);
}
Tree Search(KeyType x, Tree Root){
	if(!isEmpty(Root)){
		if(x == RootKey(Root)) return Root;
		else
		if(x > RootKey(Root)) return Search(x,RightChild(Root));
		else
		if(x < RootKey(Root)) return Search(x,LeftChild(Root));
	} else {
		printf("#Search not found!\n");
		return NULL;
	}
}
void InsertNode(KeyType X,Tree *T){
	if(isEmpty(*T))
	{
        (*T) = Create(X,NULL,NULL);
	}
	else
		if(RootKey(*T) == X)
			printf("Key %d is existing in BST\n", X);
	else
		if( RootKey(*T) > X)
			InsertNode(X,&(*T)->left);
	else
			InsertNode(X,&(*T)->right);
}

KeyType deletemin(Tree *T){
	if(LeftChild(*T)!=NULL){
		return deletemin(&(*T)->left);
	} else {
		KeyType X = RootKey(*T);
		(*T) = RightChild(*T);
		return X;
	}
}
KeyType deletemax(Tree *T){
	if(RightChild(*T) != NULL) deletemax(&(*T)->right);
	else{
		KeyType X = RootKey(*T);
		(*T) = LeftChild(*T);
		return X;
	}
}
void deleteNode(KeyType X, Tree *T){
	if(!isEmpty(*T)){
		if(X > RootKey(*T)) deleteNode(X,&(*T)->right);
		else
		if(X < RootKey(*T)) deleteNode(X,&(*T)->left);
		else
		if(X == RootKey(*T)) {
			// Truong Hop 1:
			if(isLeaf(*T)) (*T) = NULL;
			// Truong Hop 2:
			else if(LeftChild(*T) == NULL && RightChild(*T) != NULL)
					(*T) = RightChild(*T);

			else if(LeftChild(*T) != NULL && RightChild(*T) == NULL)
					(*T) = LeftChild(*T);
			// Truong Hop 3:
			else {
				//(*T)->Key = deletemin(&(*T)->right); // cach 1: thay root = node nho nhat ben phai
				(*T)->Key = deletemax(&(*T)->left); // cach 2: thay root = node lon nhat ben trai
			}
			return;
		}
	} else {
		printf("Not Found\n");
	}
}

// PreOrder (nLR)
void NLR(Tree n){
	if(!isEmpty(n)){
		printf("%d ",RootKey(n));
		NLR(LeftChild(n));
		NLR(RightChild(n));
	}
}
// InOrder (LnR);
void LNR(Tree n){
	if(!isEmpty(n)){
		LNR(LeftChild(n));
		printf("%d ",RootKey(n));
		LNR(RightChild(n));
	}
}
// PostOrder (LRn);
void LRN(Tree n){
	if(!isEmpty(n)){
		LRN(LeftChild(n));
		LRN(RightChild(n));
		printf("%d ",RootKey(n));
	}
}

