#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *left;
    struct node *right;
    int data;
};

void print(int sheet[], int count){
    for(int p=0; p<count; p++){
        if(p == 0) printf("%d", sheet[p]);
        else printf(" %d", sheet[p]);
    }
    printf("\n");
}

void print_it(int sheet[], int count, struct node *root){
    if(root -> left == NULL && root -> right == NULL){
        sheet[count] = root -> data;
        print(sheet, count+1);
        return;
    }
    if(root -> left != NULL){
        sheet[count] = root -> data;
        print_it(sheet, count+1, root -> left);
    }
    if(root -> right != NULL){
        sheet[count] = root -> data;
        print_it(sheet, count+1, root -> right);
    }
    
} 

void print_all_paths(struct node *root){
    int sheet[1000];
    print_it(sheet, 0, root);
}
 
struct node *insert_bs_tree(struct node *root, int data)
{
    struct node *current;
    if (root == NULL)
    {
        current = (struct node *)malloc(sizeof(struct node));
        assert(current != NULL);
        current->data = data;
        current->left = NULL;
        current->right = NULL;
        return current;
    }
 
    if (data < root->data)
        root->left = insert_bs_tree(root->left, data);
    else
        root->right = insert_bs_tree(root->right, data);
    return root;
}
 
int main(void)
{
    int n;
    struct node *root = NULL;
 
    while (scanf("%d", &n) != EOF)
        root = insert_bs_tree(root, n);
 
    print_all_paths(root);
}