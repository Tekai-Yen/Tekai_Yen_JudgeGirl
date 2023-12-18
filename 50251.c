#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxL 100
typedef struct Node {
    char symbol[5];
    int frequency;
    struct Node *left, *right;
}Node;

void print(char sheet[100][5], int n, char s){
    for(int p=0; p<n; p++){
        printf("%s%c", sheet[p], s);
    }
}

void HuffmanDecoding(Node *root, char *data){
    int p = 0, len = strlen(data), count = 0;
    char sheet[100][5], s;
    #ifdef SPACE
        s = ' ';
    #endif
    #ifdef NEWLINE
        s = '\n';
    #endif
    Node *ptr = root;
    for(p=0; p<len; p++){
        if(data[p] == '0') ptr = ptr -> left;
        else ptr = ptr -> right;
        if(ptr -> left == NULL && ptr -> right == NULL){
            strcpy(sheet[count], ptr -> symbol);
            ptr = root;
            count++;
            continue;
        }
        if(p == len-1){//不是leaf但是到最後一位了 -> 錯誤
            printf("-1%c", s);
            return;
        }
    }
    print(sheet, count, s);
}

Node* newNode(char *symbol, int frequency, Node* l, Node* r){
    Node* new = (Node*)malloc(sizeof(Node));
    if(*symbol != '\0')
        strcpy(new->symbol,symbol);
    new->frequency = frequency;
    new->left = l, new->right = r;
    return new;
}
 
int main (){
    // sample Huffman tree  
    Node *root = newNode("\0",31,
                            newNode("\0",18,
                                    newNode("dad",10,NULL,NULL),
                                    newNode("\0",8,
                                            newNode("cat",5,NULL,NULL),
                                            newNode("\0",3,
                                                    newNode("bee",2,NULL,NULL),
                                                    newNode("ant",1,NULL,NULL)
                                                    )
                                            ) 
                                    ),
                            newNode("\0",13,
                                    newNode("fat",7,NULL,NULL),
                                    newNode("end",6,NULL,NULL)
                                    )
                        );
    // sample encoded data
    char data[MaxL];
    while(scanf("%s", data)!=EOF){
        HuffmanDecoding(root, data);
        printf("\n");
    }
    return 0;
}   