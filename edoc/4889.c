//안정적인 문자열 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//C에서 스택 구현 
#define MAX 2002
int n;
int top; //맨 위 원소를 나타내기 위한 변수
char stack[MAX];

int isEmpty(){ //스택이 공백상태인지 검사하는 함수
    if(top<0) return 1; //top이 0보다 작으면 true 반환
    else return 0; //아니라면 false 반환
}

int isFull(int n){ //스택이 포화 상태인지 검사하는 함수 
    if(top>=n-1) return 1; //top이 n-1보다 크다면 true 반환 (포화상태)
    else return 0; // 아니라면 false 반환
}

void push(char value){ //스택에 원소를 삽입하는 함수
    if(isFull(n) == 1); //포화상태라면 넘어가기
    else stack[++top] = value; //아니라면 해당공간에 top을 1 증가시켜 value 삽입
}
char pop(){ //스택에 원소를 제거하는 함수
    if(isEmpty()==1); //비어있는 상태라면 넘어가기
    else return stack[top--]; //아니라면 top을 1을 감소시킨 원소를 반환 
}

int main(){
    int i, result, t=1;
    char arr[MAX];
    char c, c1,c2;


    while(1){
        result = 0;
        scanf("%s", arr);
        if(arr[0] == '-') break;
        n = (int)strlen(arr);

        for (i = 0; i < n; i++){
            c = arr[i];
            if(c == '}' && !isEmpty() && stack[top] == '{') {
                pop();
            }
            else push(c);
        }
        while(!isEmpty()){
            c1 = stack[top];
            pop();
            c2 = stack[top];
            pop();
            if(c1 == c2) result++;
            else result += 2;
        }
        printf("%d. %d\n", t, result);
        t++;
    }
    return 0;
}