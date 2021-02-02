//오등 큰수 
//입력 = n, Ai
//출력 = 오등큰수

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001

int n, arr[MAX] ={0}, F[MAX] = {0} , ans[MAX]={0}, k;
int stack[MAX];

/*int *stack; //스택을 위한 배열 
int top = -1; //맨 위의 운소를 나타낼 top 변수

int isFull(int n){ //스택이 포화 상태인지 검사하는 함수 
    if(top >= n) return 1; //top 이 최대 크기와 같거나 클 경우 1 반환 (true)
    return 0; //그렇지 않은 경우 0 반환 (false)
}

int isEmpty(){ //스택이 공백상태인지 검사하는 함수
    if(top == -1) return 1; //top이 -1인경우 1 반환 (true)
    return 0; //그렇지 않을 경우 0 반환 (false)
}

void push (int data){ //스택에 원소를 삽입하는 함수
    if (!isFull(n)){ // 스택이 포화 상태가 아닐경우
        top++; //top을 1 증가
        stack[top] = data; //해당 공간에 data 삽입
    }
}

int pop(void){ // 스택에 원소를 제거하는 함수
    if(!isFull(n)){ // 배열이 비어있지 않은 경우
        int temp = stack[top]; //top 원소를 임시 변수 temp에 저장
        top--; //top 변수 1 감소
        return temp; // temp 반환
    }
}

int peek(void){ //스택의 맨 위의 원소를 반환하는 함수
    if(!isEmpty()) return stack[top]; 
    //스택이 비어있지 않은 경우 스택의 맨 위 값 반환
}*/
/*typedef struct _ArrayStack {
    int top; //스택 맨 위의 인덱스
    int data[MAX]; //스택 데이터 공간
}ArrayStack;
 
typedef ArrayStack Stack; //배열로 구현한 스택
 
 
void Init(Stack* s) { //스택 초기화 top 값을 -1로
    s->top = -1; //top 초기값은 -1
}
 
int isEmpty(Stack* s) { //스택이 비었나?
    return s->top == -1; //top이 -1일 때 스택은 비어있음
}
 
int isFull(Stack* s) {  //스택이 꽉 찼나?
    return s->top == n - 1;
}
 
void push(Stack* s, int item) { //스택의 맨 위에 데이터 삽입
    if (isFull(s));
    else {
        s->top++;
        s->data[s->top] = item;
    }
}
 
int Peek(Stack* s) { //스택 최상단의 데이터 검색, 찾은 데이터 반환
    int d;
    if (isEmpty(s)) {
        return -1;
    }
    else {
        d = s->data[s->top];
        return d;
    }
}
 
int pop(Stack* s) { //스택 최상단의 데이터 삭제, 삭제되는 데이터 반환
    int t = Peek(s);
    s->top--;
    return t;
}*/


int top = -1;

int isEmpty(){
    if(top<0) return 1;
    else return 0;
}

int isFull(int n){
    if(top>=n-1) return 1;
    else return 0;
}

void push(int value){
    if(isFull(n) == 1);
    else stack[++top] = value;
}
int pop(){
    if(isEmpty()==1);
    else return stack[top--];
}

int main(){
    int i;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    //F(Ai) 찾기
    for(i=0; i<n; i++){
        F[arr[i]]++;
    }

    //오등큰수 찾기
    /*for(i=n-1; i>=0; i--){
        //현재 숫자의 등장 횟수보다 작은 것들은 최소 힙에서 제거한다. 
        while(top<=arr[i]) pop();
        if(top > 1e9) ans[i] = -1;
        else ans[i] = top;
        push(arr[i]);
    }*/

    for(i = n-1; i>=0; i--){
        if(isEmpty()){
            push(arr[i]);
            ans[i] = -1;
        }
        else if(F[arr[i]] < F[stack[top]]){
            ans[i] = stack[top];
            push(arr[i]);
        }
        else{
            while (!isEmpty() && F[arr[i]] >= F[stack[top]]){
                pop();
            }
            if(isEmpty()){
                ans[i] = -1;
                push(arr[i]);
            }
            else{
                ans[i] = stack[top];
                push(arr[i]);
            }
        }
    }

    for(i=0; i<n; i++){
        printf("%d ",ans[i]);
    }

}