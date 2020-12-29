//숫자의 갯수

#include <stdio.h>
#include <string.h>

int main()
{
    int arr[10];
    int a, b, c;
    char result[10] = {0};
    int i, j;
    int br[10] = {0};

    int len= strlen(result);

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    result[0] = a * b * c;

    printf("%s\n", result[0]);

    for(i=0; i<len; i++){
        arr[i] = result[0] % 10;
        result[0] = result[0] / 10;

    }

    for (i = 0; i < 10; i++)
        {
             for(j=0; j<9; j++){
                if (arr[i] == j)
                br[j]++;
            }
           
        }

    /*if (100000000 <= result < 1000000000)
    {
        for (i = 0; i < 10; i++)
        {
            arr[i] = result % 10;
            result = result / 10;
        }
        for (i = 0; i < 10; i++)
        {
             for(j=0; j<9; j++){
                if (arr[i] == j)
                br[j]++;
            }
           
        }
    }

    if (10000000 <= result < 100000000)
    {
        for (i = 0; i < 9; i++)
        {
            arr[i] = result % 10;
            result = result / 10;
        }
        for (i = 0; i < 9; i++)
        {
            for(j=0; j<9; j++){
                if (arr[i] == j)
                br[j]++;
            }
            
        }
    }

    if (1000000 <= result < 10000000)
    {
        for (i = 0; i < 8; i++)
        {
            arr[i] = result % 10;
            result = result / 10;
            printf("%d", arr[i]);
            printf("\n");
        }
        for (i = 0; i < 8; i++)
        {
             for(j=0; j<9; j++){
                if (arr[i] == j)
                br[j]++;
            }
            
        }
        
    }*/
    
    for(i=0; i<10; i++){
        printf("%d\n", br[i]);
    }

}