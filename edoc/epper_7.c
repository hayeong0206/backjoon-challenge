//연속된 구간으로 분할

#include <stdio.h>
#include <string.h>

void solve(char arr[]){
    int i,j, key,s=0;
    char ans[1001];
    //char temp = " ";

    for(i=0; i<strlen(arr)+1; i++){
        if(arr[i] != arr[i+1] && arr[i] != arr[i-1]){
            ans[s++] = arr[i];
        }
        else if (arr[i] == arr[i+1] && arr[i] == arr[i-1]) {
            if( i==0 || i==strlen(arr)+1){
                ans[s++] = 0;
            }
            continue;
        }
    }
    for(i=0; i<s; i++){
        printf("%c", ans[i]);
    }

    //원하는 배열만큼 담기 위해선 어떻게 해야할까..........
    //이게 한계 ㅠㅠ 
}

int main(){
    char arr[1001];
    int i;

    scanf("%s",arr);

    solve(arr);
    
}