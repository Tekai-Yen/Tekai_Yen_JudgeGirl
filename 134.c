#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int height, data;
    struct node *left, *right;
}Node;

Node* generate(int value){
    Node *ptr = (Node*)malloc(sizeof(Node));
    ptr -> data = value;
    ptr -> left = ptr -> right = NULL;
    return ptr;
}

void insert(Node* ptr, Node* root){
    int level = 1;
    Node* current = root;
    while(level != ptr -> height - 1){
        if(ptr -> data < current -> data)
            current = current -> left;
        else
            current = current -> right;
        //current = ptr -> data < current -> data ? current = current -> left : current = current -> right;
        level++;
    }
    if(ptr -> data < current -> data)
        current -> left = ptr;
    else 
        current -> right = ptr;
}

Node* LCA(Node* current, int a, int b){
    int k = current -> data;
    if(a < k && b < k) return LCA(current -> left, a, b);
    if(a > k && b > k) return LCA(current -> right, a, b);
    return current;
}

int compute(int a, Node* current){
    if(current -> data == a) return 0;
    if(current -> data > a) return 1 + compute(a, current -> left);
    else return 1 + compute(a, current -> right);
}

int main()
{
    int N;
    Node data[1000];
    scanf("%d", &N);
    for(int p=0; p<N; p++) 
        scanf("%d%d", &data[p].data, &data[p].height);
    for(int p=N-1; p>=0; p--){
        for(int q=0; q<p; q++){
            if(data[q].height > data[q+1].height || (data[q].height == data[q+1].height && data[q].data > data[q+1].data)){
                Node temp = data[q];
                data[q] = data[q+1];
                data[q+1] = temp;
            }
        }
    }
    Node* root = &data[0];
    for(int p=1; p<N; p++){
        insert(&data[p], root);
    }
    int M;
    scanf("%d", &M);
    while(M--){
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b){
            int temp = a;
            a = b;
            b = temp;
        }
        Node* key_root = LCA(root, a, b);
        printf("%d\n", compute(a, key_root) + compute(b, key_root));
    }
    return 0;
}