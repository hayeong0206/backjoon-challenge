//평범한 배낭
//물품의 수N과 준서가 버틸 수 있는 무게 K가 주어짐
//두 번째 줄부터 N개의 줄에 거쳐 각 물건의 무게W와 해당 물건의 가치 V가 주어짐

#include <stdio.h>

int  W[101]={-1}, V[101]={-1};
int dp[100001]= {0};
// dp[101]로 했을 때 런타임 에러 

int max(int a, int b){
    return (a>b) ? a : b;
}

int solve(int num, int weight){
    int i,j;

    for(i=1; i<=num; i++){
        for(j=weight; j>0; j--){
            if(W[i]<=j){ //용량보다 무게가 작으면 
                dp[j]= max(dp[j], dp[j-W[i]]+V[i]);
                //물건을 넣었을 때와 넣지 않았을 때 중 더 큰 값으로 초기화
            }
            printf("dp[%d] : %d\n",j,dp[j]);
        }
    }
    //첫번째 물건부터 N번째 물건까지 배낭용량과 비교해 넣을 수 있다면 넣어보고 
    //넣었을 때와, 넣지 않았을 때 중 큰 값으로 초기화 한다.
    return dp[weight];
}

int main(){
    int N, K, i;
    int ans=0;

    scanf("%d %d",&N, &K);
    for(i=1; i<=N; i++){
        scanf("%d %d", &W[i], &V[i]);
    }

    ans = solve(N,K);

    printf("%d",ans);
}