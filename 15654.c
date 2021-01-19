//n과 m (5)
//달라진 점 - 자연수 m 이 주어졌을 때 그 안에서 수열을 구함 

#include <stdio.h>
#include <stdlib.h>

int N,M;
int arr[8];
int ans[10];
int check[10];

int compare(const void* a, const void* b){
    if(*(int*)a>*(int*)b) return 1;
    else if(*(int*)a<*(int*)b) return -1;
    else return  0;
}

int function(int num,int arr[8]){
    int i;
    if (num==M){
        
        for (i=0; i<M; i++) {
            printf("%d ",ans[i]);
        }
        printf("\n");
        return num;
    }

    for (i=0; i<N; i++){
        if(check[i]) continue;
        check[i] = 1;
        ans[num] = arr[i];
        function(num+1,arr);
        check[i] = 0;
    }
}
    

int main(){
    scanf("%d %d",&N, &M);
    for (int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,N,sizeof(int),compare);
    function(0,arr);
}