//n과 m (2)
//1에서 추가된 조건 -> 오름차순 이어야 한다. 

#include <stdio.h>

int N,M;
int ans[10];
int check[10];

int function(int num){
    int i;
    if (num==M){
        
        for (i=0; i<M; i++) {
            printf("%d ",ans[i]);
        }
        printf("\n");
        return num;
    }

    for (i=(num ? ans[num-1]+1 : 1); i<=N; i++){
        if(check[i]) continue;
        check[i] = 1;
        ans[num] = i;
        function(num+1);
        check[i] = 0;
    }
}
    

int main(){
    scanf("%d %d",&N, &M);
    function(0);
}