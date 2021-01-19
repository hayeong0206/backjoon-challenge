//검증수

//고유 번호의 5자리 입력
// 각 수를 제곱한 수들의 합을 10으로 나눈 나머지가 검증수

#include <stdio.h>

int main(){

    int arr[5]={0};
    int ans= 0, i;

    for(i=0;i<5; i++){
        scanf("%d",&arr[i]);
    }

    for(i=0; i<5; i++){
        arr[i] *= arr[i];
        ans+=arr[i];
    }
    printf("%d",ans%10);
}