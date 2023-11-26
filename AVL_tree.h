#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;

typedef struct Nodetag{
	int Bal;
	KeyType key;
	struct Nodetag *left;
	struct Nodetag *right;
} Node;

typedef Node* AVLTree;

AVLTree Create(KeyType k, AVLTree x, AVLTree y){
	AVLTree newnode = (Node*)malloc(sizeof(Node));
	
	newnode->key = k;
	newnode->Bal = 0;
	newnode->right = x;
	newnode->left = y;
	
	return newnode;
}

int max(int x, int y){
	return x>y ? x:y;
}

int get_height(AVLTree T){
	
	if(T == NULL) return -1;
	else
	if(T->left == NULL && T->right == NULL) return 0;
	else 
	return 1 + max(get_height(T->left),get_height(T->right));
}
// lech ben trai cua con trai

AVLTree LL_Rotation(AVLTree root){
	AVLTree newTree = root->left;
	root->left = newTree->right;
	newTree->right = root;
	
	root->Bal = get_height(root->left) - get_height(root->right);
	newTree->Bal = get_height(newTree->left) - get_height(newTree->right);
	
	return newTree;
}
// lech ben phai cua con phai
AVLTree RR_Rotation(AVLTree root){
	AVLTree newTree = root->right;
	
	root->right = newTree->left;
	newTree->left = root;
	
	root->Bal = get_height(root->left) - get_height(root->right);
	newTree->Bal = get_height(newTree->left) - get_height(newTree->right);
	
	return newTree;
}
// lech ben trai cua con phai LR 
AVLTree LR_Rotation(AVLTree root){
	AVLTree RChild_root = root->right;
	AVLTree newTree = RChild_root->left;
	
	RChild_root->left = newTree->right;
	root->right = newTree->left;
	
	newTree->left = root;
	newTree->right = RChild_root;
	root->Bal = get_height(root->left) - get_height(root->right);
	RChild_root->Bal = get_height(RChild_root->left) - get_height(RChild_root->right);
	newTree->Bal = get_height(newTree->left) - get_height(newTree->right);
	return newTree;
	
}
// lech ben phai cua con trai RL
AVLTree RL_Rotation(AVLTree root){
	AVLTree LChild_root = root->left;
	AVLTree newTree = LChild_root->right;
	
	LChild_root->right = newTree->left;
	root->left = newTree->right;
	
	newTree->right = root;
	newTree->left = LChild_root;
	root->Bal = get_height(root->left) - get_height(root->right);
	LChild_root->Bal = get_height(LChild_root->left) - get_height(LChild_root->right);
	newTree->Bal = get_height(newTree->left) - get_height(newTree->right);
	
	return newTree;
	
}

AVLTree insert_node(KeyType x, AVLTree T){
	if(T == NULL){
		T = Create(x,NULL,NULL);
	} else{
		if(x == T->key) {
			printf("da co %d trong BST\n",x);
		}
		else
		if(x > T->key) {
			
			T->right = insert_node(x,T->right);
		}
		else if(x < T->key) {
			
			T->left = insert_node(x,T->left);
		}
	}
	// update balance
	
	T->Bal = get_height(T->left) - get_height(T->right);	
	 //cay mat can bang
	if(T->Bal > 1){ // lech con trai
		if(T->left->Bal >= 0){ // Truong hop LEFT LEFT lech trai cua con trai
			printf("left left\n");
			T = LL_Rotation(T);
		}
		else if(T->left->Bal <= -1){ // Truong hop Right Left lech phai cua con trai
			printf("right left\n");
			T = RL_Rotation(T);
		}
	}
	else if(T->Bal < -1){ // lech con phai
		if(T->right->Bal <= 0){ // Truong hop Right Right lech phai cua con phai
			
			printf("right right\n");
			T = RR_Rotation(T);
		}
		else if(T->right->Bal >= 1){ // Truong hop Left Right lech trai cua con phai
			printf("left right\n");
			T = LR_Rotation(T);
			
		}
	}

	return T;
}

// nho nhat ben phai
AVLTree deletemin(AVLTree *T){
	if((*T)->left == NULL) return NULL;
	else{
		while((*T)->left != NULL) (*T) = (*T)->left;
		
		AVLTree oldnode = (*T);
		(*T) = (*T)->right;
		return oldnode;
	}
}
AVLTree deletemax(AVLTree *T){
	if(*T == NULL) return NULL;
	else{
		while((*T)->right != NULL) *T = (*T)->right;
	
		AVLTree oldnode = *T;
		
		*T = (*T)->left;
		
		return oldnode;
	}
}

AVLTree delete_node(KeyType x,AVLTree T){
	if(T == NULL) printf("cay T rong\n");
	else{
		if(x == T->key) {
			if(T->left == NULL && T->right == NULL){
				T = NULL;
			} 
			else if(T->left == NULL && T->right != NULL){
				T = T->right;
			} 
			else if(T->right == NULL && T->left != NULL){
				T = T->left;
			}
			else {
				T->key = deletemax(&T->left)->key;
				//T->key = deletemin(T->right)->key;  
				
			}			
		} else if(x > T->key) T->right = delete_node(x,T->right);
		else if(x < T->key) T->left = delete_node(x,T->left);
	}

	if(T != NULL) T->Bal = get_height(T->left) - get_height(T->right);	
	if(T != NULL){
		T->Bal = get_height(T->left) - get_height(T->right);	
		if(T->Bal > 1){ // lech con trai
			if(T->left->Bal >= 0){ // Truong hop LEFT LEFT lech trai cua con trai
				printf("left left\n");
				T = LL_Rotation(T);
			}
			else if(T->left->Bal <= -1){ // Truong hop Right Left lech phai cua con trai
				printf("right left\n");
				T = RL_Rotation(T);
			}
		}
		else if(T->Bal < -1){ // lech con phai
			if(T->right->Bal <= 0){ // Truong hop Right Right lech phai cua con phai
				
				printf("right right\n");
				T = RR_Rotation(T);
			}
			else if(T->right->Bal >= 1){ // Truong hop Left Right lech trai cua con phai
				printf("left right\n");
				T = LR_Rotation(T);
				
			}
		}	
	}
	
	return T;
}
void NLR(AVLTree T){
	if(T != NULL){
		printf("%d, Balance %d\n",T->key,T->Bal);
		NLR(T->left);
		NLR(T->right);
	}
}

void LNR(AVLTree T){
	if(T != NULL){
		NLR(T->left);
		printf("%d, Balance %d\n",T->key,T->Bal);
		NLR(T->right);
	}
}
void LRN(AVLTree T){
	if(T != NULL){
		NLR(T->left);
		NLR(T->right);
		printf("%d, Balance %d\n",T->key,T->Bal);
	}
}


