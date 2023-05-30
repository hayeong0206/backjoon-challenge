//적어도 대부분의 배수
//브루트포스 알고리즘

#include <stdio.h>

int main(){
    int num[6]= {0};
    int i,j, ans=0, n = 0;

    for(i=0; i<5; i++){
        scanf("%d", &num[i]);
    }

    for(i=1; i<10000000; i++){
        ans = 0;
        for(j=0; j<5; j++){
            if(i % num[j] == 0){
                ans++;
            }
        }
        if(ans >= 3) {
            n = i;
            break;
        }
    }

    printf("%d", n);

}