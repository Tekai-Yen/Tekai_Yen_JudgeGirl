#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAXN 16384
#define MAXLENGTH 2

typedef struct node{
    int value;
    struct node *left, *right;
} Node;

int cmp(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}

Node* generate(int data){
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr -> value = data;
    ptr -> left = ptr -> right = NULL;
    return ptr;
}

Node* Tekai(int data[], int N, int a, int b){
    if(N == 0) return NULL;
    if(N < MAXLENGTH){
        Node *ptr = generate(data[b]), *temp, *previous;
        previous = ptr;
        for(int p=b-1; p>=a; p--){
            temp = generate(data[p]);
            previous -> left = temp;
            previous = temp;
        }
        return ptr;
    }
    int sheet[N];
    for(int p=0; p<N; p++){
        sheet[p] = data[a+p];
    }
    qsort(sheet, N, sizeof(int), cmp);
    int target = sheet[MAXLENGTH-1], index;
    for(int p=a; p<=b; p++){
        if(data[p] == target){
            index = p;
            break;
        }
    }
    Node* root = generate(target);
    root -> left = Tekai(data, index-a, a, index-1);
    root -> right = Tekai(data, b-index, index+1, b);
    return root;
}

Node *ConstructTree(int sequence[], int N){
    return Tekai(sequence, N, 0, N-1);
}
 

void PrintTree( Node *root ){
    if (root == NULL)
        return;
    printf("%d\n", root->value);
    PrintTree(root->left);
    PrintTree(root->right);
    return;
}
int main(){
    int N, sequence[MAXN];
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &sequence[i]);
    Node *tree = ConstructTree( sequence, N );
    PrintTree( tree );
    return 0;
}