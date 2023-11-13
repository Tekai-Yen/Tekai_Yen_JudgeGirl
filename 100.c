#include <stdio.h>
#include <assert.h>
 
void snake(const int *ptr_array[100][100], int m){
    int *temp[10000], count = 0;
    for(int p=0; p<m; p++)
        for(int q=0; q<m; q++)
            temp[p*m+q] = ptr_array[p][q];
    for(int p=m*m-1; p>0; p--)
        for(int q=0; q<p; q++)
            if(*temp[q] > *temp[q+1]){
                int *haha = temp[q];
                temp[q] = temp[q+1];
                temp[q+1] = haha;
            }
    for(int p=0; p<m; p++){
        if(p%2 == 0){
            for(int q=0; q<m; q++){
                ptr_array[p][q] = temp[count];
                count++;
            }
        }
        else{
            for(int q=m-1; q>=0; q--){
                ptr_array[p][q] = temp[count];
                count++;
            }
        }
    }
}
 
int main()
{
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;
 
  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }
 
  snake(ptr_array, m);
 
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }
 
  return 0;
}