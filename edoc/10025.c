// 게으른 백곰
// 입력 - N과 K 
// 출력 - K만큼 떨어진 거리 내에 있는 얼음들의 합(최댓값)

#include <stdio.h>

int main(){
    int n,k,i, sum, ans;
    int amount,xi, ice[1000001] = {0};

    scanf("%d %d", &n,&k);
    for(i=0; i<n; i++){
        scanf("%d %d",&amount, &xi);
        ice[xi] = amount;
    }

    k = k*2 +1;
    for(i = 0; i<=1000000; i++){
        if(i>= k) sum -= ice[i-k];
        sum += ice[i];
        ans = sum > ans? sum:ans;
    }
    printf("%d\n",ans);
    return 0;
}