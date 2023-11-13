#include<stdio.h>

int main()
{
    int odd[1000], even[1000], n, oddnum = 0, evennum = 0;
    scanf("%d", &n);
    while(n--){
        int temp;
        scanf("%d", &temp);
        if(temp % 2 == 0){
            even[evennum] = temp;
            evennum++;
        }
        else{
            odd[oddnum] = temp;
            oddnum++;
        }
    }
    for(int p=0 ; p<oddnum ; p++){
        printf("%d", odd[p]);
        if(p != oddnum-1)printf(" ");
    }
    printf("\n");
    for(int p=0 ; p<evennum ; p++){
        printf("%d", even[p]);
        if(p != evennum-1)printf(" ");
    }
    return 0;
}