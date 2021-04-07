//알바생 강호

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    if(*(int*)a>*(int*)b) return -1;
    else if(*(int*)a<*(int*)b) return 1;
    else return  0;
}

int main(){
    int i,n;
    long ans=0;
    int arr[100001] = {0};
    scanf("%d",&n); //손님 수 입력받는다.
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    //내림차순으로 정렬

    for(i=0; i<n; i++){
        if(arr[i] - i > 0) {
            ans+= arr[i] - i; 
        }
        else break;
    }
    printf("%ld",ans);
}

//ans 를 int 로 잡아 틀렸습니다가 뜸.