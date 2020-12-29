//숫자의 갯수

#include <stdio.h>
#include <string.h>

int main()
{
    int arr[10] ={0};
    int a, b, c,d=0, result = 0;
    int i, j;
    int br[10] = {0};

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    result = a * b * c;

        for (i = 0; i < 10; i++)
        {
            arr[i] = result % 10;
            result = result / 10;

            if(result<1) break;
            d++; //d값 초기화 안해줬었음 ㅡㅡ 
            
        }
            
        for (i = 0; i <= d; i++) //i <d라고 해서 틀림
        {
             for(j=0; j<=9; j++){ //j<9라고 써서 틀렸음
                if (arr[i] == j)
                br[j]++;
            }
           
        }

    for(i=0; i<10; i++){
        printf("%d\n", br[i]);
    }

}