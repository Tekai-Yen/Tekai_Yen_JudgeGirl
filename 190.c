#include <stdio.h>

int evaluate_f(int *iptr[], int n, int *index){
    *index = -1;
    int max = -99999;
    for(int p=0; p<n; p++){
        if(*iptr[p]*4 - *(iptr[p]+1)*6 > max && p>*index){
            max = *iptr[p]*4 - *(iptr[p]+1)*6;
            *index = p;
        }
    }
    return max;
}
 
int main(){
  int a[] = { 9, 7 };
  int b[] = { 3, 2 };
  int c[] = { 3, 2 };
  int d[] = { 9, 7 };
  int *iptr[] = { a, b, c, d };
  int max, index;
  max = evaluate_f(iptr, 4, &index);
  printf("%d %d\n", max, index);
}