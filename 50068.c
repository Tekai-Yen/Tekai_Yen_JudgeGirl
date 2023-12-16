#include <stdio.h>
#include <stdlib.h>
#define MAX 1000 
typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;

void record_address(Node *address[], Node *root, int index){
    address[index] = root;
    if(root -> left != NULL){
        record_address(address, root -> left, index*2);
    }
    if(root -> right != NULL){
        record_address(address, root -> right, index*2+1);
    }
}

void traversal(Node *root, int N, int command[]){
    Node *address[10000000];
    int current_index = 1;
    record_address(address, root, 1);

    for(int p=0; p<N; p++){
        Node *ptr = root;
        int current = root -> label;
        if(command[p] == 0){
            printf("%d\n", root -> label);
            return;
        }
        if(command[p] == 1){
            printf("%d\n", root -> label);
        }
        if(command[p] == 2){
            current_index /= 2;
            if(current_index < 1){
                printf("%d\n", current);
                return;
            }
            root = address[current_index];
        }
        if(command[p] == 3){
            if(root -> left != NULL){
                root = root -> left;
                current_index *= 2;
            }
            else{
                printf("%d\n", current);
                return;
            }
        }
        if(command[p] == 4){
            if(root -> right != NULL){
                root = root -> right;
                current_index *= 2;
                current_index++;
            }
            else{
                printf("%d\n", current);
                return;
            }
        }
        if(command[p] == 5){
            if(current_index == 1){
                printf("%d\n", current);
                return;
            }
            current_index /= 2;
            root = address[current_index];
            if(root -> left != NULL && root -> left != ptr){
                current_index *= 2;
                root = root -> left;
            }
            else if(root -> right != NULL && root -> right != ptr){
                current_index = current_index * 2 + 1;
                root = root -> right;
            }
            else{
                printf("%d\n", current);
                return;
            }
        }
    }
}

Node* newNode(int label, Node *l, Node *r) {
    Node *u = (Node *) malloc(sizeof(Node));
    u->label = label, u->left = l, u->right = r;
    return u;
}
 
int main() {
    Node *root = newNode(
            6,
            newNode(
                3,
                newNode(1, 
                        NULL, 
                        newNode(2, NULL, NULL)
                        ),
                newNode(5, 
                        newNode(4, NULL, NULL), 
                        NULL
                        )                
            ),
            newNode(
                7,
                NULL,
                NULL                
            )
    );
 
    int N, command[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &command[i]);        
    }
    traversal(root, N, command);
    return 0;
}