#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char **a, char **b){
    char *c;
    c = *a;
    *a = *b;
    *b = c;
}
void sort (int num, char **string){
    int max = num;
    int i,j;
    for(i=0; j<max; j++){
        if(strcmp(string[i],string[j])>0){
            swap(&string[i],&string[j]);
        }
    }
}

int main(){
    char str1[210], str2[210];
    int t, n, ans;

    scanf("%d",&t);
    while(t!=0){
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            fgets(str1, n, stdin);
        }
        for(int i=0; i<n; i++){
           scanf("%s", str2); 
        }
        printf("%s", str1);    

        for(int i=0; i<n; i++){
            printf("\n");
            sort(n, &str1);
            sort(n, &str2); 
            printf("%s\n",str1);  
            printf("%s\n",str2);   }
        ans = strcmp(str1, str2);
        if (ans == 0)
        {
            printf("NOT CHEATER\n");
        }
        else
        {
            printf("CHEATER\n");
        }
        t--;
    }
}