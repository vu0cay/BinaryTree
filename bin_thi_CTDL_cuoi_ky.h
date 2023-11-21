#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int KeyType;
typedef struct Nodetag{
	KeyType key;
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
	N->key = x;
	N->left = l;
	N->right = r;

	return N;
}
KeyType RootKey(Tree T){
	return T->key;
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
Tree insert_node(KeyType X,Tree T){
	if(isEmpty(T))
	{
        T = Create(X,NULL,NULL);
	}
	else
	{
		if(RootKey(T) == X)
			printf("Key %d is existing in BST\n", X);
		else
			if( RootKey(T) > X)
			T->left = insert_node(X,T->left);
		else
			T->right = insert_node(X,T->right);
	}
}
KeyType deletemax(Tree *T){
	if( (*T)->right != NULL) return deletemax(&(*T)->right);

	KeyType X = (*T)->key;
	(*T) = (*T)->left;
	return X;
	
}
KeyType deletemin(Tree *T){
	if( (*T)->left != NULL) return deletemin(&(*T)->left);

	KeyType X = (*T)->key;
	(*T) = (*T)->right;
	return X;
	
}
Tree delete_node(KeyType X, Tree T){
	if(T != NULL){
		if(X > T->key) T->right = delete_node(X,T->right);
		else
		if(X < T->key) T->left = delete_node(X,T->left);
		else
		if(X == T->key) {
			// Truong Hop 1:
			if( (T->left == NULL) && (T->right == NULL) ) {
			     T = NULL;
			}
			// Truong Hop 2:
			else if( (T->left == NULL) && (T->right != NULL) )
					T = T->right;
			else if( (T->left != NULL) && (T->right == NULL) )
					T = T->left;
			// Truong Hop 3:
			else {
				//(*T)->Key = deletemin(&(*T)->right); // cach 1: thay root = node nho nhat ben phai
				T->key = deletemin(&(T->right)); // cach 2: thay root = node lon nhat ben trai
			}
		
		}
	} 
	return T;
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

