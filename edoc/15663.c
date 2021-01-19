//N과 M (9)
//N개의 자연수와 자연수 M이 주어졌을 때 N개의 자연수 중에서 M개를 고른 수열
//1<=M<=N<=8, 둘째줄에 N개의 수가 주어짐. 
//입력으로 주어지는 수는 10,000보다 작거나 같은 자연수.

#include <stdio.h>
#include <stdlib.h>

int N,M,i;
int arr[9]={0};
int check[9] = {0};
int ans[9][9] = {0};

void solve(int num){
    printf("%d",num);
    if (num >= M){
        printf("----num == M-----\n");
        for (i=0; i<M; i++) {
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }

    for(i=0; i<N; i++){
        if(check[i] == 1) continue; //같은 수를 중복하여 이용할 수 없게함
        check[i]= 1;
        arr[num]=arr[i];
        printf("arr[%d]: %d\n",num,arr[num]);
        solve(num+1);
        check[i]= 0;
    }
}

int compare(const void* a, const void* b){
    if(*(int*)a>*(int*)b) return 1;
    else if(*(int*)a<*(int*)b) return -1;
    else return  0;
}

int main(){

    scanf("%d %d",&N, &M);

    for (int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    } //N개의 수 입력

    qsort(arr,N,sizeof(int),compare);

    printf("qsort 정렬후 \n");
    for(i=0; i<N;i++){
        printf("arr[%d]: %d \n",i, arr[i]);
    }
    printf("\n");

    solve(0);

    printf("재귀함수 돌린 후 배열 안에 들어간 값.\n");
    for(i=0; i<N;i++){
        printf("arr[%d]: %d \n",i, arr[i]);
    }

}