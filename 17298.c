//오큰수 
//오등큰수와 비슷 -> 오등큰수보다 간단. 

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001

int n, arr[MAX] ={0}, ans[MAX]={0}, k;


//C에서 스택 구현 
int top = -1; //맨 위 원소를 나타내기 위한 변수
int stack[MAX];

int isEmpty(){ //스택이 공백상태인지 검사하는 함수
    if(top<0) return 1; //top이 0보다 작으면 true 반환
    else return 0; //아니라면 false 반환
}

int isFull(int n){ //스택이 포화 상태인지 검사하는 함수 
    if(top>=n-1) return 1; //top이 n-1보다 크다면 true 반환 (포화상태)
    else return 0; // 아니라면 false 반환
}

void push(int value){ //스택에 원소를 삽입하는 함수
    if(isFull(n) == 1); //포화상태라면 넘어가기
    else stack[++top] = value; //아니라면 해당공간에 top을 1 증가시켜 value 삽입
}
int pop(){ //스택에 원소를 제거하는 함수
    if(isEmpty()==1); //비어있는 상태라면 넘어가기
    else return stack[top--]; //아니라면 top을 1을 감소시킨 원소를 반환 
}

int main(){
    int i;
    scanf("%d",&n);

    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    //오등큰수 찾기
    for(i = n-1; i>=0; i--){ //마지막 수부터 검사
        if(isEmpty()){ //비어있다면 
            push(arr[i]); //arr[i]의 원소를 집어넣는다
            ans[i] = -1; //오른쪽에 더 큰 수가 없으므로 ans[i] = -1을 넣어준다.
        }
        else if(arr[i] < stack[top]){ // top에 있는 수가 더 크다면
            ans[i] = stack[top]; //ans[i]에 그 수를 넣어준다.
            push(arr[i]); //arr[i]를 스택에 넣어준다.
        }
        else{
            while (!isEmpty() && arr[i] >= stack[top]){//비어있지 않고,stack[top]의 수가 arr[i]의 수보다 작다면 
                pop(); //더 큰 수가 나올 때까지 삭제해준다. 이런식으로 n-1 부터 0번째 수까지 탐색           
            }
            if(isEmpty()){ //비어져있다면
                ans[i] = -1; //ans[i] = -1을 넣어준다.
                push(arr[i]); //arr[i]의 값을 넣어준다.
            }
            else{ //포화상태라면
                ans[i] = stack[top]; //ans[i]에 그 수를 넣어준다.
                push(arr[i]); //arr[i]의 값을 넣어준다.
            }
        }
    }

    for(i=0; i<n; i++){
        printf("%d ",ans[i]);
    }

}