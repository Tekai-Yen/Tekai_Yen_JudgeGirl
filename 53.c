#include<stdio.h>
#include<stdbool.h>

void compute(int data[], int N, int count, int order[], bool used[]){
    if(count == N){
        for(int p=0; p<N; p++){
            printf("%d", order[p]);
            if(p != N-1) printf(" ");
        }
        printf("\n");
        return;
    }
    for(int p=0; p<N; p++){
        if(used[p]) continue;
        order[count] = data[p];
        used[p] = true;
        compute(data, N, count+1, order, used);
        used[p] = false;
    }
    
    

}

int main()
{
    int N, data[10], order[10];
    bool used[10] = {0};
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
    compute(data, N, 0, order, used);
    return 0;
}