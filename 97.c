#include<stdio.h>
#include<math.h>

int dis(int x1, int x2, int y1, int y2)
{
    return abs(x1 - y1) + abs(x2 - y2);
}

int main()
{
    int n, park[10][3] = {0}, m, parking[10] = {0} ;
    //for(int p=0 ; p<10 ; p++)parking[p] = 0;
    scanf("%d", &n);
    for(int o=0 ; o<n ; o++)
        scanf("%d%d%d", &park[o][0], &park[o][1], &park[o][2]);
    scanf("%d", &m);
    for(int o=0 ; o<m ; o++){
        int x, y, ans = 0;
        scanf("%d%d", &x, &y);
        int  current = 1000000000;
        for(int p=0 ; p<n ; p++){
            
            if(park[p][2] <= parking[p])continue;//停車場已滿

            if(dis(x, y, park[p][0], park[p][1]) < current){
                ans = p;
                //printf("%d  fuck\n", ans);
                current = dis(x, y, park[p][0], park[p][1]);
            }
            else if(dis(x, y, park[p][0], park[p][1]) == current){
                if(park[p][0] < park[ans][0]){
                    current = dis(x, y, park[p][0], park[p][1]);
                    ans = p;
                }
                else if(park[p][0] == park[ans][0] && park[p][1] < park[ans][1]){
                    current = dis(x, y, park[p][0], park[p][1]);
                    ans = p;
                }
            }
        }
        parking[ans]++;
    }
    //printf("\n\n\n\n");
    for(int p=0 ; p<n ; p++){
        printf("%d\n", parking[p]);
    }
    return 0;
}