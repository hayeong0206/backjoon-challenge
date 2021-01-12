//캠핑
//사용할 수 있는 일수, 연속하는 일 수, 휴가 일수 
//구해야 하는 것: 사용 할 수 있는 최대 일 수 

//예제: 5 8 20 -> 14
//이해-> 20일을 8일로 나누면 총 8,8,4가 나옴. 결국 8일중 5일 두번, 4일 -> 14일

//예제2: 5 8 17 ->11
//이해: 17일을 8일로 나누면 8,8,1 => 11일 쓸 수 있음

//문제 풀이 방식
//휴가 일 수를 연속하는 일 수로 나눈다 -> 그 몫 * 사용가능 일 수 -1
//나머지가 사용 가능 일 수 보다 작다면 +나머지
//나머지가 사용 가능 일 수 보다 크다면 +사용가능 일 수

#include <stdio.h>

int main(){
    int l,p,v;
    int i=0, result=0;

    while(1){
        result = 0;
        scanf("%d %d %d", &l, &p, &v);

        if(l==0 && p==0 && v==0) break;

        i++;
        
        //1번 풀이 구하기
        result += v/p *l;

       
        //2번 풀이 구하기
        if( (v%p) < l){
            result += v%p;
        }
        else{
            result +=l;
        }

        printf("Case %d: %d\n",i,result);
    }
}