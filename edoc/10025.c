// 게으른 백곰
// 입력 - N과 K 
// 출력 - K만큼 떨어진 거리 내에 있는 얼음들의 합(최댓값)

#include <stdio.h>

int n,k,i, sum, ans;
int amount,xi, ice[1000001] = {0};
//main함수 안에서 선언시 틀렷습니다 뜸 왜일까?

int main(){


    scanf("%d %d", &n,&k);
    for(i=0; i<n; i++){
        scanf("%d %d",&amount, &xi);
        ice[xi] = amount;
    }

    k = k*2 +1;
    // k*2+1 범위 내에서 최댓값 찾는 문제
    for(i = 0; i<=1000000; i++){
        if(i>= k) sum -= ice[i-k];
        //i가 범위를 넘어간다면 더해준 값 중에서 범위 밖에 있는 값을 빼주기
        sum += ice[i];
        //범위 안에 있는 값들 더해주기 
        ans = sum > ans? sum:ans;
        // 큰 값 정해주기
    }
    printf("%d\n",ans);
    return 0;
}