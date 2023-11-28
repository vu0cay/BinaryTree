// Nguyen Hoang Vu 28-11-2023
// TEST CASE: https://stackoverflow.com/questions/3955680/how-to-check-if-my-avl-tree-implementation-is-correct
#include <stdio.h>
#include <stdlib.h>
typedef char KeyType;
typedef struct Nodetag{
	int Bal; // he so can bang = chieu cao con trai - chieu cao con phai
	//quy dinh 
	//neu Bal < -1 thi lech con phai (height right > height left)
	//neu Bal > 1 thi lech con trai (height right < height left) 
	//neu Bal = 0 thi height left == height right
	KeyType key;
	struct Nodetag *left;
	struct Nodetag *right;
} Node;
typedef Node* AVLTree;
// Khoi tao cay co khoa k con trai bang x va con phai bang y
AVLTree Create(KeyType k, AVLTree x, AVLTree y){
	AVLTree newnode = (Node*)malloc(sizeof(Node));
	newnode->key = k;
	newnode->Bal = 0;
	newnode->right = x;
	newnode->left = y;
	return newnode;
}
// ham max tra ve x neu x>y va y neu x<y
int max(int x, int y){
	return x>y ? x:y;
}
// tinh chieu cao cay, nut la co chieu cao = 0, NUll = -1
int get_height(AVLTree T){
	
	if(T == NULL) return -1;
	else
	if(T->left == NULL && T->right == NULL) return 0;
	else 
	return 1 + max(get_height(T->left),get_height(T->right));

}
/*================================CAC_PHEP_XOAY_TREN_CAY_NHI_PHAN_TIM_KIEM========================================*/
// lech ben trai cua con trai, Phep Left-Left
AVLTree LL_Rotation(AVLTree root){
	AVLTree newTree = root->left;
	root->left = newTree->right;
	newTree->right = root;
	
	root->Bal = get_height(root->left) - get_height(root->right);
	newTree->Bal = get_height(newTree->left) - get_height(newTree->right);
	
	return newTree;
}
// lech ben phai cua con phai, Phep Right-Right
AVLTree RR_Rotation(AVLTree root){
	AVLTree newTree = root->right;
	root->right = newTree->left;
	newTree->left = root;
	
	root->Bal = get_height(root->left) - get_height(root->right);
	newTree->Bal = get_height(newTree->left) - get_height(newTree->right);
	
	return newTree;
}
// lech ben trai cua con phai LR , Phep Left-Right
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
// lech ben phai cua con trai RL, Phep Right-Left
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
AVLTree update(AVLTree T){
	T->Bal = get_height(T->left) - get_height(T->right);	
	//cay mat can bang
	if(T->Bal > 1){ // lech con trai
		if(T->left->Bal >= 0){ // Truong hop LEFT LEFT lech trai cua con trai
			printf("cay lech trai \"left\" cua con trai \"left\" tai node %d\n",T->key);
			T = LL_Rotation(T);
		}
		else if(T->left->Bal <= -1){ // Truong hop Right Left lech phai cua con trai
			printf("cay lech phai \"Right\" cua con trai \"Left\" %d\n",T->key);
			T = RL_Rotation(T);
		}
	}
	else if(T->Bal < -1){ // lech con phai
		if(T->right->Bal <= 0){ // Truong hop Right Right lech phai cua con phai
			
			printf("cay lech phai \"Right\" cua con phai \"Right\" %d\n",T->key);
			T = RR_Rotation(T);
		}
		else if(T->right->Bal >= 1){ // Truong hop Left Right lech trai cua con phai
			printf("cay lech phai \"LEFT\" cua con phai \"Right\" %d\n",T->key);
			T = LR_Rotation(T);	
		}
	}
	return T;
}
// Them node vao cay AVL (cay nhi phan tim kiem can bang)
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
	T = update(T); // cap nhat he so can bang va dieu chinh cay AVL
	return T; // tra ve node T sau moi lan de quy
}

// Ham tra ve node nho nhat cua cay T
AVLTree deletemin(AVLTree T){
	if(T == NULL) return NULL;
	else {
		AVLTree p = T;
		while(p->left != NULL){
			p = p->left;
		}
		return p;
	}
}
// Ham tra ve node lon nhat cua cay T
AVLTree deletemax(AVLTree T){
	if(T == NULL) return NULL;
	else{
		AVLTree p = T;
		while(p->right != NULL){
			p = p->right;
		}
		return p;
	}
}
AVLTree delete_node(KeyType x,AVLTree T){
	if(T == NULL) printf("cay T rong\n");
	else{
		if(x == T->key) { // Tim thay x trong cay AVL
			if(T->left == NULL && T->right == NULL){ // xoa nut la
				T = NULL;
			} 
			else if(T->left == NULL && T->right != NULL){ // xoa nut co 1 con phai
				T = T->right;
			} 
			else if(T->right == NULL && T->left != NULL){ // xoa nut co 1 con trai
				T = T->left;
			}
			else {
				// xoa node lon nhat ben trai
				AVLTree p = deletemax(T->left); //tim node lon nhat cua con trai nut T
				
				T->key = p->key; // doi gia tri p cho T
				T->left = delete_node(p->key,T->left); // xoa gia tri p vua tim dc trong cay con trai nut T
				
			}			
		} else if(x > T->key) T->right = delete_node(x,T->right); // X lon hon nut goc tim ben phai
		else if(x < T->key) T->left = delete_node(x,T->left); // X nho hon nut goc tim ben trai
	}	
	if(T!=NULL){ // neu khong phai la NULL
		T = update(T); // cap nhat he so can bang va dieu chinh cay AVL
	}		
	return T; // tra ve nut T sau moi lan de quy
} 


void NLR(AVLTree T){
	if(T != NULL){		
		printf("%c, Balance %d\n",T->key,T->Bal);
		NLR(T->left);
		NLR(T->right);
	}
}
void LNR(AVLTree T){
	if(T != NULL){
		NLR(T->left);
		printf("%c, Balance %d\n",T->key,T->Bal);
		NLR(T->right);
	}
}
void LRN(AVLTree T){
	if(T != NULL){
		NLR(T->left);
		NLR(T->right);
		printf("%c, Balance %d\n",T->key,T->Bal);
	}
}


