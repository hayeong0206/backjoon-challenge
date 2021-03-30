//완전수면 yes 아니면 no

#include <stdio.h>

void solve(int arr[], int n){
    int i,j;
    int num=0;

    for(i=1; i<=n; i++){
        num = 0;
        for(j=1; j<arr[i]; j++){
            if(arr[i] % j == 0) num += j;
        }
        arr[i] -= num; 
    }
    
    for(i=1; i<=n; i++){
        if(arr[i]==0) printf("YES");
        else printf("NO");
    }
}

int main(){
    int arr[51] = {0};
    int n, i;
    scanf("%d",&n);
    
    for(i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }

    solve(arr, n);

    
}