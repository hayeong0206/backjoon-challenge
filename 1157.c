//단어 공부

#include <stdio.h>
#include <string.h>

int main(){
    char arr[1000000];
    int len, ar[27] = {0}, i, j,k;
    int max=0, maxindex=-1;

    scanf("%s",arr);
    len= strlen(arr);

    for(i=0; i<len; i++){
        if (arr[i] < 'a'){
            j = arr[i] -'A';
            ar[j]++;
        }
        else{
            j = arr[i] - 'a';
            ar[j]++;
        }
    }

    for (k=0; k<26; k++){
        if(ar[k]>max){
            max = ar[k];
            maxindex = k;
        }
    }

    ar[maxindex]++;

    for (i=0; i<26; i++){
        if(ar[i] == max){
            printf("?");
            maxindex = -1;
            break;
        }
    }

    if(maxindex != -1){
        printf("%c", maxindex +'A');
    }

    return 0;
}