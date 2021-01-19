//n과 m(11)
//9+ 같은 수를 여러번 골라도 됨

#include <stdio.h>
#include <stdlib.h>

int N,M;
int arr[8];
int ans[10];
int check[10];

//qsort 를 사용하기 위한 compare함수 선언 
int compare(const void* a, const void* b){
    if(*(int*)a>*(int*)b) return 1;
    else if(*(int*)a<*(int*)b) return -1;
    else return  0;
}
 
int function(int num,int arr[8]){
    int i;
    //m개를 선택했다면 출력한다. 
    if (num==M){
        for (i=0; i<M; i++) {
            printf("%d ",ans[i]);
        }
        printf("\n");
        return num;
    }
    //prev_num이라는 변수를 변수를 저장해 직전에 골랐던 수를 저장해 줌.
    int prev_num=-1;

    for (i=0; i<N; i++){
        //직전에 골랐던 수이거나 이미 고른 수라면 넘어감.
        if(prev_num==arr[i]) continue;
        ans[num] = arr[i]; //ans 배열에 넣어줌 
        prev_num = arr[i]; // 직전에 고른 수를 저장해준다.
        function(num+1,arr); //다음 수를 고른다.
    }
}
    

int main(){
    scanf("%d %d",&N, &M);
    for (int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }
    
    //사전순으로 출력하기 위해 오름차순 정렬
    qsort(arr,N,sizeof(int),compare);
    function(0,arr);
}