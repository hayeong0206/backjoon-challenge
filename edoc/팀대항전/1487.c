// 물건 팔기 
// 세준이의 물건을 구매할 의향이 있는 사람의 수 
// 각 사람이 지붏랄 최대 금액과 배송비 
// 출력 - 최대 이익을 만들어주는 가격 (여러개라면 가장 낮은 가격)
// 이익을 남길 수 없다면 0 출력 

#include <stdio.h>
int min(int a, int b){
    return a < b ? a : b;
}

int main(){
    int n, price[1001][2] = {0};
    int i,j, ans = 0, max= 0, cost=1000000; 

    scanf("%d", &n);

    for (i=0; i<n; i++){
        for(j=0; j<2; j++){
           scanf("%d", &price[i][j]); 
        }  
    }

    for(i=0; i<n; i++){
        ans = 0;
        for(j=0; j<n; j++){
            if(price[j][0]>=price[i][0] && price[i][0] - price[j][1] > 0) {
                ans += price[i][0] - price[j][1];
                printf("%d = %d\n",price[j][0],ans);
            }
        }
        if(max == ans){
            cost = min(cost, price[i][0]);
        }
        else if(max < ans){
            max = ans;
            cost = price[i][0];
        }
        if( cost == 1000000){
            cost = 0;
        }
    }
    printf("%d",cost);
}