#include<stdio.h>

int main()
{
    int N, data[10];
    scanf("%d", &N);
    for(int p=0; p<N; p++)
        scanf("%d", &data[p]);
    for(int p=N-1; p>=0; p--)// sort
        for(int q=0; q<p; q++)
            if(data[q] > data[q+1]){
                int temp = data[q];
                data[q] = data[q+1];
                data[q+1] = temp;
            }
    
    return 0;
}