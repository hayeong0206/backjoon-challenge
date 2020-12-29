//ox퀴즈
//OX퀴즈의 결과가 주어졌을 때, 점수를 구하는 프로그램을 작성하시오.


#include <stdio.h>
#include <string.h>

int main(){
    char ar[81];
    int n, i, j;
    int sum, temp;

    scanf("%d",&n);
    for (i = 0; i<n; i++){
        scanf("%s",ar); 
        sum = 0; temp = 0;
        for(j=0; j<strlen(ar); j++){
            if(ar[j] == 'O'){
                
                temp++;
                sum +=temp;
                
            }
            else{
                temp=0;
            }
        }
        printf("%d\n",sum);
    }
    
}
