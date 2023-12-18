#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include<string.h>
#define SYM_MAX_LEN 8
#define SYM_MAX_NUM 100000
 
typedef struct Node {
    char symbol[SYM_MAX_LEN];
    int frequency;
    struct Node *left, *right;
} Node;

Node* buildHuffmanTree(char* s[SYM_MAX_NUM], int n){
    Node data[SYM_MAX_NUM];
    int node_num = 0, dealt;
    for(int p=0; p<n; p++){//處理完frequency跟array
        dealt = 0;
        for(int q=0; q<node_num; q++){
            if(strcmp(s[p], data[q].symbol) == 0){
                data[q].frequency++;
                dealt = 1;
                break;
            }
        }
        if(dealt == 0){
            data[node_num].frequency = 1;
            strcpy(data[node_num].symbol, s[p]);
            data[node_num].left = data[node_num].right = NULL;
            node_num++;
        }
    }
    Node* Set[SYM_MAX_NUM];
    

}
 
void printTree(Node* node){
    if(node->left == NULL && node->right == NULL){
        printf("%d %s\n", node->frequency, node->symbol);
        return;
    }
    printf("%d\n", node->frequency);
    printTree(node->left);
    printTree(node->right);
}
 
int main(){
    int n;
    char* s[SYM_MAX_NUM];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        s[i] = (char*)malloc(sizeof(char) * SYM_MAX_LEN);
        scanf("%s", s[i]);
    }
    Node *root = buildHuffmanTree(s, n);
    printTree(root);
 
    for(int i = 0; i < n; i++){
        free(s[i]);
    }
}