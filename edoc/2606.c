// 바이러스 
// 그래프 알고리즘 
// 연결되어 있는 컴퓨터는 웜 바이러스에 걸리지만 연결되어 있지 않으면 걸리지 않음
// 입력 - 컴퓨터의 수
// 입력 - 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수 
// 입력 - 연결되어있는 컴퓨터의 번호 쌍이 주어짐
// 출력 - 1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수 

#include <stdio.h>
int check[110] ={-1};
// 배열 원소들의 값을 0으로 초기화 해서 틀렸었음
int virus = 0;
int arr[110][110] = {-1};
//크기 101일 때 틀림 왜지?
int m;

int dfs(int x){
    int nxt;
    if(check[x]== 0){    
        check[x] = 1;
        virus++;
        for(int i = 0; i < m; i++){
            nxt=arr[x][i];
            dfs(nxt);
        }
    }
    return virus;
}

int main(){
    int n,i, s, t;

    scanf("%d",&n);
    for(i=1; i<=n; i++){
        check[i] = 0;
    }
    scanf("%d",&m);
    for(i=0; i<m; i++){
        scanf("%d %d",&s, &t);
        arr[s][i] = t;
        arr[t][i] = s;
    }

    printf("%d",dfs(1)-1);
    return 0;
}