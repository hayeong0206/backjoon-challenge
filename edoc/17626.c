//Four Squares 

#include <stdio.h>
#include <math.h>


int dp[50005] = {0};
int min(int a, int b){
    return a<b ? a : b;
}

int solve(int a){
    int i,j;
    
    for(i= 1; i<= a; i++){
        if(sqrt(i) * sqrt(i) == i){ //제곱근 함수 = sqrt()
            dp[i] =1;
        } //제곱수의 값을 모두 1로 초기화 

        dp[i] = dp[1] + dp[i-1];
        for (j=2; j*j<=i; j++){
            dp[i]=min(dp[i], 1+ dp[i-j*j]);
        }
        //dp[98]을 구한다고 할 때 dp[1] + dp[97], dp[4] + dp[94] ... 중 가장 작은 값 구하기
    }

    return dp[a];
}

int main(){
    int n;

    scanf("%d", &n);
    printf("%d", solve(n));
}