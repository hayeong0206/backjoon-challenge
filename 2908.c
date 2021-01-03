//상수

#include <stdio.h>

int main(){
    char num1[4]= {0};
    char num2[4]= {0};
    int i;

    scanf("%s %s", num1, num2);

    for (i = 3; i>=0; i--){
        if(num1[i]>num2[i]){
            printf("%c%c%c", num1[2],num1[1],num1[0]);
            break;
        }
        else if (num1[i]<num2[i]){
            printf("%c%c%c", num2[2],num2[1],num2[0]);
            break;
        }
    }
}