//나머지

#include <stdio.h>
#define NUM 42

int main(){
    int arr[10] = {0};
    int br[10] = {0};
    int count;
    int i,j, sum=0; 

    for (i = 0; i<10; i++){
        scanf("%d",&arr[i]);
    }

    for (i = 0; i< 10; i++){
        br[i] = arr[i] % NUM;
    }

    for(i = 0; i<42; i++){
        for(j=0; j<10; j++){
             if(br[j]==i) {
                 sum++;
                 break; //j값이 i값과 같아지면 다음 i값으로 넘어간다.
             }
        }
    }
    printf("%d",sum);
}