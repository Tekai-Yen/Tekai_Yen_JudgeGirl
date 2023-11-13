#include <stdio.h>

void shuffle(int *deck[]){
    int count = 0, l = 0, r, *temp[10000];
    while(deck[count] != NULL){
        temp[count] = deck[count];
        count++;
    }
    temp[count] = NULL;
    r = (count%2==1)? count/2+1 : count/2;
    for(int p=0; p<count; p++){
        if(p%2 == 0){
            deck[p] = temp[l];
            l++;
        }
        else{
            deck[p] = temp[r];
            r++;
        }
    }
}

void print(int *deck[]){
    int p = 0;
    while(deck[p] != NULL){
        if(!p) printf("%d", *deck[p]);
        else printf(" %d", *deck[p]);
        p++;
    }
}
 
int main()
{
  int card[10000];
  int *deck[10000];
  int index = 0;
 
  while (scanf("%d", &(card[index])) != EOF) {
    deck[index] = &(card[index]);
    index++;
  }
  deck[index] = NULL;
  shuffle(deck);
  print(deck);  
  return 0;
}