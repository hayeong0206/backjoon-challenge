//유레카 이론 

#include <stdio.h>

int dp[45]={0};

int eureka(int a){
    for(int i=1; i<45; i++){
        for(int j=1; j<45; j++){
            for(int k=1; k<45; k++){
                if(dp[i] + dp[j] + dp[k] == a){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    int n, i,a;

    for(i=1; i<45; i++){
        dp[i] = i*(i+1)/2;
    }

    scanf("%d",&n);

    for(i=1; i<=n; i++){
        scanf("%d",&a);
        printf("%d\n",eureka(a));
    }
}