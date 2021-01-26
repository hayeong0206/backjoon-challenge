//두 용액 
//전체 용액의 수 N(2<=N<=100000) 입력
//용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 입력 (|N|<=1000000000)
//특성값은 모두 다르고, 한가지 종류로만 주어질 수 있음.

//특성값이 0에 가장 가까운 용액을 만들어내는 두 용액의 특성값을 출력
//특성값의 오름차순으로 출력

//생각
//오름차순 정렬 
//제일 작은 값과 큰 값을 더한 값부터 하나씩 비교해본다. -> 제일 작은 수 선택
//오류 -> 부호가 다를 때 -2와 1이 있다면 -2를 고르게 됨
//해결 -> 절댓값 이용 - abs() 함수 이용

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int arr[10000001] = {0};

int sum; 
int ans = INT_MAX; //int 형의 최댓값을 입력받아 비교. 최댓값을 사용하기 위해 limits.h 이용

int compare(const void* a, const void* b){
    if(*(int*)a>*(int*)b) return 1;
    else if(*(int*)a<*(int*)b) return -1;
    else return  0;
}
//qsort를 이용하기 위한 함수

int main(){
    int N, i;
    int left, right, l, r; 

    scanf("%d",&N);

    for (i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }

    qsort(arr,N,sizeof(int),compare);
    //stdlib.h에서 제공하는 qsort 사용해 오름차순 정렬
    left =0; right = N-1;
    while (left<right){
        sum = arr[left] + arr[right];

        if(abs(sum) <ans){
            ans = abs(sum);
            l = left;
            r = right;
        }

        if(ans == 0) break;

        if(abs(sum) >= abs(arr[left]+arr[right-1])) right--;
        else if (right +1 <N && abs(sum) > abs(arr[left] + arr[right + 1])) right++;
        else left++;
    }

    printf("%d %d",arr[l], arr[r]);
}