//저울
//입력 - 첫줄: 물건의 개수 N, 둘째 줄: 미리 측정된 물건 쌍의 개수 M
//다음 M개의 줄에 미리 측정된 비교 결과가 한 줄에 하나씩 (앞의 물건 > 뒤의 물건)

//출력 - N개의 줄에 결과 출력 - i번째 줄에는 물건 i와 비교 결과를 알 수 없는 물건의 개수 

#include <stdio.h>

int arr[110][110];
int n,m;

int main(){
    int i,j,k;
    int s,v, result;

    scanf("%d %d",&n,&m );

    for(i=0; i<m; i++){
        scanf("%d %d",&s,&v);
        arr[s][v] = 1; //큰 것 확인
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            for(k=1; k<=n; k++){
                if(arr[j][i] == 1 && arr[i][k] == 1){
                    arr[j][k]=1; //비교 가능한 수들을 1로 바꾸어서 연결해준다.
                }
            }
        }
    }

    for(i=1; i<=n; i++){
        result=0;
        for(j=1; j<=n; j++){
            if(arr[i][j]==0 && arr[j][i]==0){
                result++; //비교가능하지 않은 수의 개수를 세준다.
            }
        }
        printf("%d\n",result);
    }
}