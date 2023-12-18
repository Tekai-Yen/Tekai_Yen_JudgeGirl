#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct node{
    int value;
    char name[35], oper;
    struct node *left, *right;
}Node;

Node* generate(){
    Node *ptr = (Node*)malloc(sizeof(Node));
    ptr -> value = -1;
    strcpy(ptr -> name, "\0");
    ptr -> oper = '\0';
    ptr -> left = ptr -> right = NULL;
    return ptr;
}

Node* buildup(){
    char read[50];
    while(scanf("%s", read)){
        if(strlen(read) > 1){

        }
        else if(read[0] == '('){

        }
        else if(read[0] == ')'){

        }
        else if(read[0] >= '0' && read[0] <= '9'){

        }
        else{

        }
    }

}

int main(){
    char expression[1005], temp[1555];
    gets(expression);
    printf("%s\n", expression);
    gets(temp);
    printf("%s", temp);
    return 0;
}