#include <stdio.h>
#include <stdlib.h> 
#define LEN 1000

struct node {
    int value;
    struct node * next;
};

struct node *merge(struct node *list1, struct node *list2){
    if(list1 -> value < list2 -> value){
        struct node *tmp = list2;
        list2 = list1;
        list1 = tmp;
    }
    struct node *current = list1, *ptr, *previous = list2, *temp;
    while(current != NULL){
        ptr = previous = list2;
        while(1){
            if(current -> value < ptr -> value){
                previous -> next = current;
                temp = current -> next;
                current -> next = ptr;
                current = temp;
                break;
            }
            if(ptr == NULL){
                previous -> next = current;
                temp = current -> next;
                current -> next = NULL;
                current = temp;
                break;
            }
            previous = ptr;
            ptr = ptr -> next;
        }
    }
    return list2;
}

struct node * build(int v[], int n) {
    struct node * head, * ptr;
    int i;
    if (!n)
        return 0;
    head = (struct node *) malloc(sizeof(struct node));
    ptr = head;
    head -> value = v[0];
    for (i = 1; i < n; i++) {
        ptr -> next = (struct node *) malloc(sizeof(struct node));
        ptr = ptr -> next;
        ptr -> value = v[i];
    }
    ptr -> next = 0;
    return head;
}
 
void print(struct node * ptr) {
    printf("%d", ptr -> value);
    if (ptr -> next) {
        putchar(' ');
        print(ptr -> next);
    }
}
 
int main() {
    int n1, n2;
    int v1[LEN], v2[LEN];
    int i;
    struct node * list1, * list2;
 
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
        scanf("%d", &v1[i]);
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
        scanf("%d", &v2[i]);
    list1 = build(v1, n1);
    list2 = build(v2, n2);
 
    print(merge(list1, list2));
    putchar('\n');
    return 0;
}