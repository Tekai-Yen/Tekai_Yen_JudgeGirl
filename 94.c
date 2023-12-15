#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

typedef struct Node{
    int data;
    struct Node *left, *right, *parent;
}node;

node* generate(int number){
    node* ptr = (node*)malloc(sizeof(node));
    ptr -> data = number;
    ptr -> left = ptr -> right = ptr -> parent = NULL;
    return ptr;
}

int find_number(int *index, char temp[]){//注意 index也會變喔
    int count = 0, haha = *index, number = 0;
    while(temp[haha] >= '0' && temp[haha] <= '9'){
        count++;
        haha++;
    }
    for(int p=0; p<count; p++){
        number += (temp[*index] - '0') * pow(10, count-p-1);
        (*index)++;
    }
    return number;
}

node* buildup(char temp[], node* root){
    int index = 0, len = strlen(temp);
    while(index < len){
        if(temp[index] == '('){
            root -> left = generate(-1);
            root -> left -> parent = root;
            root = root -> left;
        }
        else if(temp[index] == ')'){
            root -> data = root -> left -> data + root -> right -> data;
            root = root -> parent;
        }
        else if(temp[index] == ','){
            root -> right = generate(-1);
            root -> right -> parent = root;
            root = root -> right;
        }
        else{
            int thenumber = find_number(&index, temp);//函式已經把index設定在下一個位置了
            root -> data = thenumber;
            root = root -> parent;
            index--;
        }
        index++;
    }
}

void traversal(node* root, bool left_first){
    printf("%d\n", root -> data);
    if(left_first){
        if(root -> left != NULL)
            traversal(root -> left, !left_first);
        printf("%d\n", root -> data);
        if(root -> right != NULL)
            traversal(root -> right, !left_first);  
    }
    if(!left_first){
        if(root -> right != NULL)
            traversal(root -> right, !left_first);
        printf("%d\n", root -> data);
        if(root -> left != NULL)
            traversal(root -> left, !left_first);
    }
      
}

int main()
{
    char temp[4050];
    scanf("%s", temp);
    int len = strlen(temp);
    node* root = generate(-1);
    buildup(temp, root);
    traversal(root, true);
    return 0;
}