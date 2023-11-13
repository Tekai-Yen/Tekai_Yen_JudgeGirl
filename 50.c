#include<stdio.h>
#include<stdlib.h>
#define int long long

typedef struct Square{
    int up;
    int down;
    int left;
    int right;
}square;

int min(int a, int b){
    return a<b?a:b;
}

int cal(square a){
    return (a.right - a.left) * (a.up - a.down);
}

square target(square a, square b)
{
    square temp;
    if((a.right < b.left || a.left > b.right) || (a.up < b.down || a.down > b.up)){//兩個維度至少一邊的線段沒有交集
        temp.up = temp.down = temp.left = temp.right = 0;
        return temp;
    }

    if(a.left >= b.left && a.right <= b.right){//a is totally included by b (horizontally)
        temp.right = a.right;
        temp.left = a.left;
    }
    else if(a.left <= b.left && a.right >= b.right){//b is totally included by a (horizontally)
        temp.right = b.right;
        temp.left = b.left;
    }
    else if(a.left <= b.left && a.right >= b.left && a.right <= b.right){
        temp.left = b.left;
        temp.right = a.right;
    }
    else if(a.right >= b.right && a.left >= b.left && a.left <= b.right){
        temp.left = a.left;
        temp.right = b.right;
    }
    
    if(a.down >= b.down && a.up <= b.up){//a is totally included by b (vertically)
        temp.up = a.up;
        temp.down = a.down;
    }
    else if(a.down <= b.down && a.up >= b.up){//b is totally included by a (vertically)
        temp.up = b.up;
        temp.down = b.down;
    }
    else if(a.down <= b.down && a.up >= b.down && a.up <= b.up){
        temp.down = b.down;
        temp.up = a.up;
    }
    else if(a.up >= b.up && a.down >= b.down && a.down <= b.up){
        temp.down = a.down;
        temp.up = b.up;
    }

    if(a.right == b.right) temp.right = a.right;
    if(a.left == b.left) temp.left = a.left;
    if(a.up == b.up) temp.up = a.up;
    if(a.down == b.down) temp.down = a.down;

    return temp;
}

signed main()
{
    int ans = 0;
    square a[3];
    for(int p=0; p<3; p++){//計算A+B+C
        scanf("%lld%lld%lld%lld", &a[p].left, &a[p].down, &a[p].right, &a[p].up);
        ans += (a[p].right - a[p].left) * (a[p].up - a[p].down);
        //printf("ans += %d\n", (a[p].right - a[p].left) * (a[p].up - a[p].down));
    }

    //printf("\n\n");

    int count = 0;
    for(int p=0 ; p<3 ; p++){//扣掉AB、BC、CA
        ans -= cal(target(a[p], a[(p+1)%3]));

        //printf("ans -= %d\n", cal(target(a[p], a[(p+1)%3])));
    }
    //printf("\n\n");

    ans += cal(target(a[2], target(a[0], a[1])));
   // printf("ans += %d\n\n", cal(target(a[2], target(a[0], a[1]))));


    printf("%lld\n", ans);
    return 0;
}