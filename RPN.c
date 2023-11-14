#include "binaryTree.h"
#include "dastacklib.h"

bool opt(char x){
    return (x == '+') || (x == '-') || (x == '*') || (x == '/');
}
int main(){
    Tree T;
	makenull(&T);
    DataType RPN[] = {'6','2','/','3','+','7','4','-','*'};
    Stack S;
    makeNull(&S);
    int n = sizeof(RPN);
    int i;
    for(i = 0; i<n; i++) {
        if(!opt(RPN[i])){
            push(Create(RPN[i],NULL,NULL),&S);
        }
        else {
            Tree x = pop(&S);
            Tree y = pop(&S);
            push(Create(RPN[i],y,x),&S);
        }

    }
    Tree N = pop(&S);
    LNR(N);

	return 0;
}
