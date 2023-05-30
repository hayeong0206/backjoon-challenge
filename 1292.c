//1929 쉽게 푸는 문제
//1번째 가정 -> 수열 이용: 마지막수에 해당하는 값까지 더한 값 - 첫번째 수에 해당하는 값까지 더한값
//fail... 근데 이유를 모르겟음 ㅜㅜ 
//그냥 배열에 하나씩 숫자 집어넣고 진자 계산하면 끝나느거엿음 복잡하게 생각하지 말자.. 오늘의 교훈.. 
 

#include <stdio.h>

// int main(){
//     int a, b, i, ans, ans1= 0, ans2= 0, sol[46] = {0}, solve[46] = {0};

//     scanf ("%d %d", &a, &b);
//     a--;

//     for(i=1; i<=44; i++){
//         sol[i] = sol[i-1] + i*i;
//     }
//     sol[45] = sol[44] + 45 * 10;

//     for(i=1; i<=45; i++){
//         printf("%d: %d ",i, sol[i]);
//     }

//     for(i=1; i<=44; i++){
//         solve[i] = solve[i-1] +i;
//         printf("solve[%d] = %d ", i, solve[i]);
//     }
//     solve[45] = 1000;

//     // for(i=1; i<=44; i++){
//     //     if( a-1 == solve[i]){
//     //         ans1 = sol[i];
//     //         printf("[1]i: %d -> %d ",i, ans1);
//     //     }
//     //     else if (a == 1 ){
//     //         ans1 = 0;
//     //     }
//     //     else if(( (solve[i] < a -1) && (solve[i] - a - 1) / i < 1) ){
//     //            ans1 = sol[i-1] + ((a - 1 - solve[i-1]) * (i+1));
//     //         printf("[2]i: %d -> %d ",i,  ans1); 
//     //     }
//     // }
//     // printf("\n");
//     for(i=1; i<=45; i++){
//         if( a == solve[i]){
//             ans1 = sol[i];
//             printf("[1]i: %d -> %d ",i, ans1);
//         }
//         else if ( a ==0){
//             ans1 = 0;
//         }
//         else if(( solve[i] > a && (solve[i] - a) / i < 1) ){
//             ans1 = sol[i-1] + (a - solve[i-1]) * i;
//             printf("[2]i: %d -> %d ",i,  ans1); 
//         }
//     }
//     for(i=1; i<=45; i++){
//         if( b == solve[i]){
//             ans2 = sol[i];
//             printf("[1]i: %d -> %d ",i, ans2);
//         }
//         else if(( solve[i] > b && (solve[i] - b) / i < 1) ){
//             ans2 = sol[i-1] + (b - solve[i-1]) * i;
//             printf("[2]i: %d -> %d ",i,  ans2); 
//         }
//     }
//     printf("\n");
//     printf("ans1: %d, ans2: %d ", ans1, ans2);
//     ans = ans2 - ans1;
//     printf("%d", ans);

// }

int main(){
    int a, b, i, j, cnt=0, sum[1001]={0}, ans=0;

    scanf("%d %d", &a, &b);

    for(i=1; cnt<1000; i++){
        for(j=0; j<i; j++){
            sum[cnt++] =i;
            if(cnt == 1000) break;
        }
    }

    for(i=a-1; i<=b-1; i++){
        ans += sum[i];
    }
    printf("%d",ans);
}