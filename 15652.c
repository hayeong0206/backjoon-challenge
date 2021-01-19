//n과 m (4)
//추가된점- 같은 수 여러번 고르기 가능
//      -고른 수열은 비내림차순이어야 한다. 


#include <stdio.h>

int N,M;
int ans[10];
int check[10];

int function(int num){
    int i;
    if (num==M){

        for (i=0; i<M-1; i++){
            if(ans[i]>ans[i+1]) return 0;
        }
        
        for (i=0; i<M; i++) {
            printf("%d ",ans[i]);
        }
        printf("\n");

        
        return num;
    }

    

    for (i=1; i<=N; i++){
        ans[num] = i;
        function(num+1);
    }
}
    

int main(){
    scanf("%d %d",&N, &M);
    function(0);
}