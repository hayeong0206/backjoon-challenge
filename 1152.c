//단어의 개수

#include <stdio.h>
#include <string.h>

int main(){
    char str[1000001];
    int i,len, count=0;

    gets(str);
    len= strlen(str);

    for(i=0; i<len; i++){
        if (str[i] == ' ') count++;
    }

    if (str[0] == ' ') count--;
    if (str[len-1] == ' ') count--;

    printf("%d", count+1);

}