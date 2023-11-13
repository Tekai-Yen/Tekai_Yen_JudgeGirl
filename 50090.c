#include <stdio.h>
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512

void count(int **ptr[])
{
    int len = 0, answersheet[520][2] = {0}, answernum = 0;
    while(ptr[len] != NULL) len++;
    for(int p=0; p<len; p++){
        int queue[520], queuenum = 0;
        if(*ptr[p] == NULL) continue;
        int quantity = 1;
        for(int q=p+1; q<len; q++){
            if(*ptr[q] == *ptr[p]){
               quantity++;
               queue[queuenum] = q;
               queuenum++;
            }
        }
        answersheet[answernum][0] = **ptr[p];
        answersheet[answernum][1] = quantity;
        //printf("p=%d   answersheet=%d   **ptr[p]=%d   quautity=%d\n", p, answernum, **ptr[p], quantity);
        answernum++;
        for(int h=0; h<queuenum; h++){
            *ptr[queue[h]] = NULL;
        }
        /*for(int h=len-1; h>=p; h--){
            if(*ptr[h] == *ptr[p])
                *ptr[h] = NULL;
        }*/
        *ptr[p] = NULL;
    }
    for(int p=answernum-2; p>=0; p--){
        for(int q=0; q<=p; q++){
            if((answersheet[q][1] > answersheet[q+1][1]) || (answersheet[q][1] == answersheet[q+1][1] && answersheet[q][0] > answersheet[q+1][0])){
                int temp = answersheet[q][0];
                answersheet[q][0] = answersheet[q+1][0];
                answersheet[q+1][0] = temp;
                temp = answersheet[q][1];
                answersheet[q][1] = answersheet[q+1][1];
                answersheet[q+1][1] = temp;
            }
        }
    }
    for(int p=0; p<answernum; p++){
        printf("%d %d", answersheet[p][0], answersheet[p][1]);
        if(p != answernum-1) printf("\n");
    }
}

 
int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
    

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    for(int p=0; p<a; p++){
        int temp;
        scanf("%d", &temp);
        ptrArray[p] = &intPtr[temp];
    }
    ptrArray[a] = NULL;
    for(int p=0; p<b; p++){
        int temp;
        scanf("%d", &temp);
        intPtr[p] = &intVar[temp];
    }
    for(int p=0; p<c; p++){
        int temp;
        scanf("%d", &intVar[p]);
    }

  count(ptrArray);
 
  return 0;
}