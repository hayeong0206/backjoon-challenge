//음계
//1부터 차례대로 연주하면 ascending, 8부터 1까지 차례대로 연주하면 descending 
//둘 다 아니라면 mixed

//첫째 줄에 8개의 숫자 주어짐
//1부터 8까지 숫자가 한 번씩 등장한다.

#include <stdio.h>

int main(){
    int arr[8]={0};
    int i, asc=0,des=0;

    for (i=0; i<8; i++){
        scanf("%d",&arr[i]);
    }

    //차례대로 올라가는 수인지 확인한다. 
    for (i=0; i<7; i++){
        if (arr[i]<arr[i+1]){
            asc++;
        }
        else{
            des++;
        }
    }
    if(asc == 7) printf("ascending");
    else if (asc == 0) printf("descending");
    else printf("mixed");

    return 0;
}