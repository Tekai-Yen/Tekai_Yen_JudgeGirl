#include<stdio.h>

int g(int x){
    if(x<=2)return x*x-1;
    else return 2;
}

int h(int y){
    if(y<2)return -1;
    else return 2+h(y-1)-h(y-2);
}

int f(int x){
    if(x>h(x)) return f(x-1)-h(x);
    else if(x<h(x)) return f(g(x))-g(x);
    else return 1;
}


int main()
{
    int temp;
    scanf("%d", &temp);
    printf("%d", f(temp));
    return 0;
}