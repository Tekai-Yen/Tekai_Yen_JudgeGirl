#include<stdio.h>
#include<math.h>

int main()
{
    int w, a, b, c, d, e, ans = 0;
    scanf("%d%d%d%d%d%d", &w, &a, &b, &c, &d, &e);
    if(b != 0){
        ans = pow(w, 2) + pow((a+2*d+b+2*e+c+2), 2);
    }
    else{
        if(e > d)ans = pow(w, 2) + pow((a+c+2+2*e), 2);
        if(d > e)ans = pow(w, 2) + pow((a+c+2+2*d), 2);
        if(d == e)ans = pow(w, 2) + pow((a+c+2+2*e), 2);
    }
    printf("%d", ans);
    return 0;
}