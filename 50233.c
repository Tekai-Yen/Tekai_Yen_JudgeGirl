#include<stdio.h>
#include<assert.h>

/*void print(int data[], int size)
{
    for(int p=1 ; p<=size ; p++)
        printf("%d ", data[p]);
    printf("size: %d\n\n", size);
}*/

int GetLargest(int data[], int i, int *heapsize)//比較i點和他的左右子節點
{
    int lindex = 2 * i, rindex = 2 * i + 1, largest;
    if(lindex <= *heapsize && data[lindex] > data[i])
        largest = lindex;
    else   
        largest = i;
    if(rindex <= *heapsize && data[rindex] > data[largest])
        largest = rindex;
    return largest;
}

void MaxHeapify(int data[], int i, int *heapsize)
{
    int largest = GetLargest(data, i, heapsize);
    while(largest != i){//不斷將該點往下比較，直到放到對的位置
        int temp = data[i];
        data[i] = data[largest];
        data[largest] = temp;
        i = largest;
        largest = GetLargest(data, i, heapsize);
    }
}

void BuildMaxHeap(int data[], int *heapsize)
{
    for(int p=*heapsize/2 ; p>=1 ; p--)
        MaxHeapify(data, p, heapsize);
}

int HeapExtractMax(int data[], int *heapsize)
{
    assert(*heapsize > 0);
    int max = data[1];
    data[1] = data[*heapsize];//將最尾端的節點放到最上面，再進行下沉
    (*heapsize)--;
    MaxHeapify(data, 1, heapsize);
    return max;
}

void MaxHeapInsert(int data[], int *heapsize, int key)
{
    *heapsize += 1;
    int i = *heapsize;
    data[i] = key;
    while(i>1 && data[i] > data[i/2]){
        int temp = data[i];
        data[i] = data[i/2];
        data[i/2] = temp;
        i /= 2;
    }
}

int main()
{
    int data[200001] = {}, heapsize = 0, n, m, answersheet[200010] = {0}, anscounter = 0;
    scanf("%d", &n);
    heapsize = n;
    for(int p=1 ; p<=n ; p++)
        scanf("%d", &data[p]);
    BuildMaxHeap(data, &heapsize);
    for(int p=1 ; p<=heapsize ; p++){
        printf("%d", data[p]);
        if(p != heapsize)
            printf(" ");
    }
    scanf("%d", &m);
    while(m--){
        int operation;
        scanf("%d", &operation);
        if(operation == -1){
            answersheet[anscounter] = HeapExtractMax(data, &heapsize);
            anscounter++;
            //printf("pop %d\n", answersheet[anscounter-1]);
        }
        else{
            MaxHeapInsert(data, &heapsize, operation);
            //printf("insert %d\n", MaxHeapInsert(data, &heapsize, operation));
        }

        //print(data, heapsize);
    }
    
    printf("\n");
    for(int p=0 ; p<anscounter ; p++){
        printf("%d", answersheet[p]);
        if(p != anscounter-1)
            printf(" ");
    }
    
    return 0;
}