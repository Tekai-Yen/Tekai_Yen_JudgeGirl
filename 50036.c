#include<stdio.h>

int tekai(int data[], int k, int n, int m, int count){
    
}

int main()
{
    int k, n, m, data[20];
    scanf("%d%d%d", &k, &n, &m);
    for(int p=0; p<n; p++)
        scanf("%d", &data[p]);
    for(int p=n-2; p>=0; p--)
        for(int q=0; q<=p; q++)
            if(data[q] > data[q+1]){
                int temp = data[q+1];
                data[q+1] = data[q];
                data[q] = temp;
            }
    printf("%d", tekai());
    return 0;
}