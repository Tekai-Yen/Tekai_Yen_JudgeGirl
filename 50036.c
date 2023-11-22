#include<stdio.h>

int tekai(int current, int n, int data[], int m, int k, int count){
    if(current == n-1) return ((data[current] <= m && count == k-1) || count >= k)?1:0;
    if(data[current] <= m) return (count>=k)?1+tekai(current+1, n, data, m, k, count)+tekai(current+1, n, data, m-data[current], k, count+1):tekai(current+1, n, data, m, k, count)+tekai(current+1, n, data, m-data[current], k, count+1);
    return (count>=k)?1+tekai(current+1, n, data, m, k, count):tekai(current+1, n, data, m, k, count);
}

int main()
{
    int k, n, m, data[20];
    scanf("%d%d%d", &k, &n, &m);
    for(int p=0; p<n; p++)
        scanf("%d", &data[p]);
    /*for(int p=n-2; p>=0; p--)
        for(int q=0; q<=p; q++)
            if(data[q] > data[q+1]){
                int temp = data[q+1];
                data[q+1] = data[q];
                data[q] = temp;
            }*/
    printf("%d", tekai(0, n, data, m, k, 0));
    return 0;
}

/*
if(m < 0) return (m + data[current-1] >= 0 && count-1 >= k)?1:0;
    if(current == n-1 && count >= k) return 1;
    if(current == n-1) return (data[current] <= m && count >= k-1)?1:0;
    return tekai(current+1, n, data, m-data[current], k, count+1) + tekai(current+1, n, data, m, k, count);
*/