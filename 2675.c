#include <stdio.h>
#include <string.h>

int main(){
    char arr[21]={0};
    int n,k,i,j, l,p;

    scanf("%d",&n);

    for (i=0; i<n; i++){
        scanf("%d",&k);
        scanf("%s",arr);

        l = strlen(arr);

        for(j=0; j<l; j++){
            for(p = 0; p<k; p++)
            printf("%c",arr[j]);
        }
        printf("\n");
    }
}