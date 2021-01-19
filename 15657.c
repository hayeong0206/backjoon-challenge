//n과 m(8)
// 7과의 차이점 - 비내림차순이어야한다.

#include <stdio.h>
#include <stdlib.h>

int N,M;
int arr[9];
int ans[10];
int check[10];

int compare(const void* a, const void* b){
    if(*(int*)a>*(int*)b) return 1;
    else if(*(int*)a<*(int*)b) return -1;
    else return  0;
}

void function(int num,int x){
    int i;
    if (num==M){

        for (i=0; i<M-1; i++){
            if(ans[i]>ans[i+1]) return;
        }
        for (i=0; i<M; i++) {
            printf("%d ",ans[i]);
        }
        printf("\n");
        return;
    }
    for (i=x; i<N; i++){
        ans[num] = arr[i];
        function(num + 1, x);
    }
}
    

int main(){
    scanf("%d %d",&N, &M);
    for (int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,N,sizeof(int),compare);
    function(0,0);
}