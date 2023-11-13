#include "posneg.h"
void posneg(int a[5][5], int temp[2]){
    for(int p=0; p<5; p++)
        for(int q=0; q<5; q++){
            if(a[p][q] > 0) temp[1]++;
            else if(a[p][q] < 0) temp[0]++;
        }
}