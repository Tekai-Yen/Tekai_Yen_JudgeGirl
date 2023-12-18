# include<stdio.h>
# include<stdlib.h>
# include<assert.h>

struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
};
 
struct list {
    struct treenode *head;
    struct treenode *tail;
};
 
typedef struct treenode TreeNode;
typedef struct list List;

void PFLIU(TreeNode *root, List *ptr){
    if(root == NULL) return;
    int data = root -> value;
    ptr -> tail -> left = root;
    ptr -> tail -> right = NULL;
    ptr -> tail = root;
    TreeNode *L = root -> left, *R = root -> right;
    if(L == NULL && R == NULL) return;
    if(data % 2 == 0){
        PFLIU(L, ptr);
        PFLIU(R, ptr);
    }
    else{
        PFLIU(R, ptr);
        PFLIU(L, ptr);
    }
}

List treeToListFunc(TreeNode * root){
    List haha;
    List *tekai = &haha;
    int data = root -> value;
    tekai -> head = tekai -> tail = root;
    TreeNode *L = root -> left, *R = root -> right;
    if(data % 2 == 0){
        PFLIU(L, tekai);
        PFLIU(R, tekai);
    }
    else{
        PFLIU(R, tekai);
        PFLIU(L, tekai);
    }
    tekai -> tail -> left = tekai -> tail -> right = NULL;
    return haha;
}

TreeNode *buildTree(int **values, TreeNode **roots) {
    int val;
    scanf("%d", &val);
    if(val == 0) return NULL;
    **values = val;
    TreeNode *now = *roots;
    (*values)++; (*roots)++;
    now -> value = val;
    now -> left  = buildTree(values, roots);
    now -> right = buildTree(values, roots);
    return now;
}
 
int main(void) {
    int size;
    scanf("%d\n", &size);
    TreeNode * root = (TreeNode*)calloc(size, sizeof(TreeNode));
 
    int valueRecord[size];
    int *vptr = valueRecord;
    TreeNode *nptr = root;
 
    root = buildTree(&vptr, &nptr);
 
    List ans = treeToListFunc(root);
 
    TreeNode * node = ans.head;
    TreeNode * firstAddr = &root[0];
    TreeNode * lastAddr = &root[size];
    for(; node != NULL; node = node -> left) {
        if (node -> right != NULL) {
            printf("Right node should be null\n");
            break;
        }
        if (firstAddr > node || lastAddr <= node) {
            printf("Memory address out of bound\n");
            break;
        }
        int counter = node - firstAddr;
        if (node -> value != valueRecord[counter]) {
            printf("You can't modify the value in the given treeNode\n");
            break;
        }
        printf("%d ", node -> value);
    }
 
     free(root);
    return 0;
}