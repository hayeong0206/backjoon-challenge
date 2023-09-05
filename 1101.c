//Fly me to the Alpha Centauri
#include <stdio.h>

int main(){
    int T, len, dist, min;
    unsigned long x, y, close = 1;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%ld %ld", &x, &y);
        close=1;

        //x부터 y까지 거리 계산
        len = y-x;

        if(len==1 || len == 2){
            printf("%d\n",len);
        }
        else{
            //len 보다 작은 제곱수 찾기
            while(close){
                if(len <= (close+1)*(close+1)){
                    break;
                } 
                else close++;
                
            }
            //해당 제곱수 만큼의 이동거리 = dist
            dist = close * 2 - 1;
            min = len - close*close;
            if(min > close) dist += 2;
            else dist +=1;
            printf("%d\n", dist);
        }
    }
    
}
