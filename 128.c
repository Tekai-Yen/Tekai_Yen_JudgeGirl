#include "intersection.h"


void intersection(int map[100][100], int result[4]){
    for(int p=0; p<4; p++)
        result[p] = 0;
    for(int p=0 ; p<100 ; p++){
        for(int q=0 ; q<100 ; q++){
            if(!map[p][q])continue;
            int count = 0, x=p, y=q;
            
            if(x+1 < 100 && map[x+1][y])count++;
            if(y+1 < 100 && map[x][y+1])count++;
            if(x-1 >= 0 && map[x-1][y])count++;
            if(y-1 >= 0 && map[x][y-1])count++;

            switch(count){
                case 0:
                    break;
                case 1:
                    result[3]++;
                    break;
                case 2:
                    if(!(x+1 < 100 && x-1 >= 0 && map[x+1][y] == map[x-1][y]) && !(y+1 < 100 && y-1 >= 0 && map[x][y+1] == map[x][y-1]))
                        result[2]++;
                    break;
                case 3:
                    result[1]++;
                    break;
                case 4:
                    result[0]++;
                    break;
            }
        }
    }
}