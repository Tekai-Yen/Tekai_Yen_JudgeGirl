#include<stdio.h>
#include<math.h>

int cal(int temp[200][200], int n, int x, int y){
    int ans = temp[x][y];
    for(int p=1 ; p<=n-1 ; p++){
        ans += temp[x+p][y-p];
        ans += temp[x+p][y+p];
    }
    x += (2*n-2);
    ans += temp[x][y];
    for(int p=1 ; p<=n-2 ; p++){
        ans += temp[x-p][y-p];
        ans += temp[x-p][y+p];
    }
    return ans;
}

int main()
{
    int h, w, k, temp[200][200] = {0}, maxlength = 0, haha;
    scanf("%d%d%d", &h, &w, &k);
    for(int p=0 ; p<h ; p++)
        for(int q=0 ; q<w ; q++)
            scanf("%d", &temp[p][q]);
    //haha = h<w ? h : w;
    //maxlength = (haha%2 == 0)? haha/2 : (haha+1)/2;
    haha = -1;

    int l = k;
    //for(int l=1 ; l<=maxlength ; l++){
        for(int p=0 ; 2*l-2+p<=h-1 ; p++){
            for(int q=l-1 ; q+l-1<=w-1 ; q++){
                //printf("x = %d\ny = %d\n\n", p, q);
                if(cal(temp, l, p, q) > haha)
                    haha = cal(temp, l, p, q);
            }
        }
    //}
    printf("%d", haha);
    return 0;
}