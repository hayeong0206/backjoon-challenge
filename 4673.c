//셀프 넘버

#include <stdio.h>

int function(int n){
    int sum;

    sum = n;

    while(n>0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main(){
    int i, num;
    int arr[10001] = {0};

    for( i = 0; i<10001; i++){
        num = function(i);
        if (num < 10001){
            arr[num] = 1;
        }

        if(arr[i] == 0){
            printf("%d\n",i);
        }
    }

}