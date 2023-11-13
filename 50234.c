#include<stdio.h>
#include<assert.h>
#include<math.h>
#define MAX 105

typedef struct{
    int x, y, value;
}block;

void print(int heapsize, int heap[]){
    printf("\n\n");
    for(int p=0; p<heapsize; p++)
        printf("%d ", heap[p]);
    printf("\n\n");
}

int greater(int heap[], int index, int heapsize){
    int l = 2*index+1, r = 2*index+2, largest = index;
    if(l < heapsize && heap[l] > heap[largest])
        largest = l;
    if(r < heapsize && heap[r] > heap[largest])
        largest = r;
    return largest;
}

void heapify(int heap[], int index, int heapsize)
{
    int largest = greater(heap, index, heapsize);
    while(index != largest){
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        index = largest;
        largest = greater(heap, index, heapsize);
    }
}

void build(int heap[], int heapsize)
{
    for(int p=heapsize/2+1 ; p>=0 ; p--){
        heapify(heap, p, heapsize);
    }
}

int GetMax(int heap[], int* heapsize)
{
    (*heapsize)--;
    int hahaha = heap[0];
    heap[0] = heap[*heapsize];
    heap[*heapsize]=0;
    heapify(heap, 0, *heapsize);
    //printf("Get: %d\n", hahaha);=
    return hahaha;
}

void insert(int heap[], int* heapsize, int key)
{
    heap[*heapsize] = key;
    int i =  *heapsize;
    while(i>0 && heap[i] > heap[(i-1)/2]){
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1) / 2;
    }
    (*heapsize)++;
    //printf("insert: %d\n", key);
}

int main()
{
    int N, count = 0, heapsize = 0;//Temp & Exposed are 1-based
    scanf("%d", &N);
    int heap[10020] = {0};//Heap is 0-based
    block queue[10020];//blocks in the heap

    int exposed[N+1][N+1], temp[N+1][N+1][N+1];
    for(int p=1; p<=N; p++)
        for(int q=1; q<=N; q++)
            exposed[p][q] = 0;

    for(int p=1 ; p<=N ; p++){
        for(int x=1 ; x<=p ; x++){
            for(int y=1 ; y<=p ; y++){
                scanf("%d", &temp[x][y][p]);
                if(exposed[x][y] == 0)
                    exposed[x][y] = p;
                count++;
            }
        }
    }
    for(int p=1 ; p<=N ; p++){
        for(int q=1 ; q<=N ; q++){
            int value = temp[p][q][exposed[p][q]];
            block haha = {p, q, value};
            heap[heapsize] = value;
            queue[heapsize] = haha;
            //exposed[p][q]++;
            heapsize++;
        }
    }
    //printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    build(heap, heapsize);
    //printf("?????????????????????????????????????????");
    //print(heapsize, heap);

    //printf("Initial Heapsize = %d\n\n", heapsize);
    while(count>0){
        int target = GetMax(heap, &heapsize);
        printf("%d", target);
        if(count>1)
            printf(" ");
        //heapsize--;
        for(int p=0 ; p<heapsize+1 ; p++){//搜尋移除的位置，並把下面一個找上來
            if(queue[p].value == target && exposed[queue[p].x][queue[p].y]+1 <= N){
                exposed[queue[p].x][queue[p].y]++;
                //printf("%d's next is %d\n", target, temp[queue[p].x][queue[p].y][exposed[queue[p].x][queue[p].y]]);
                queue[p].value = temp[queue[p].x][queue[p].y][exposed[queue[p].x][queue[p].y]];
                
                insert(heap, &heapsize, queue[p].value);
                break;
            }
        }
        count--;
    }
    return 0;
}