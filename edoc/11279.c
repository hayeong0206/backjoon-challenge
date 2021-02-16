//최대 힙
//입력 - 첫째 줄에 연산의 개수 n, 다음 줄에 연산에 대한 정보를 나타내는 정수 x
//출력 - 입력에서 0이 주어진 회수만큼 답을 출력.
//만약 배열이 비어있는 경우에 가장 큰 값을 출력하라고 한 경우에는 0을 출력 

#include <stdio.h>
#define MAX_SIZE 100001

int visited[MAX_SIZE];

//노드와 노드의 자리를 바꿔주는 함수
void nodeChange(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//우선순위 큐를 구조체 형태로 제작
typedef struct priorityQueue{
    int heap[MAX_SIZE]; //heap의 배열형태
    int count; //heap의 갯수 and 위치값을 나타내는 값 (=index의 값)
}priorityQueue;

//우선순위 큐 삽입 PUSH
void push(priorityQueue *root, int data){
    if(root ->count >= MAX_SIZE) return;
    //만약 priorityQueue의 노등 ㅣㅡ 갯수가 설정한 최대값보다 크다면 더이상 값을 추가할 수 없도록 함
    root -> heap[root->count] = data;
    //data 값을 heap의 맨 마지막 트리에 저장
    int now=root->count; //추가한 data의 위치값 (index)
    int parent = (root-> count -1) /2; //추가한 data의 부모값
    //새 원소를 삽입한 이후에 상향식으로 최상단 루트까지 data 값을 힙으로 구성한다.
    while(now>0 && root -> heap[now] > root->heap[parent]){
        //now>0 비교하는 값의 위치가 최상단 루트가 될때까지 반복
        nodeChange(&root->heap[now], &root->heap[parent]);
        //부모값과 현 값의 자리를 바꿔준다.
        now = parent;
        //상향식으로 다시 위 부모 노드와 비교하기 위해서 부모값은 현재가 된다.
        parent = (parent -1) / 2;
        //부모값의 위치 또한 다음 검사할 부모값의 위치를 저장한다. 
    }
    root->count++;
    //push로 값을 추가하였으니 count 또한 1 증가시킨다. 
}
//우선순위 큐의 추출 pop
int pop(priorityQueue *root){
    if(root->count <= 0) return 0;
    //추출한 대상이 더이상 없을 경우로 오류를 출력
    int res = root -> heap[0];
    //반환할 최상단 루트의 값을 res 변수에 담는다.
    root -> count--;
    //최상단 루트값이 하나 빠지므로 count 값도 같이 하나 감소시킨다.
    root ->heap[0] = root->heap[root->count];
    //최상단 루투에는 맨 마지막 노드값이 들어가도록 한다.
    //최상단 루트와 맨마지막 노드값으 ㅣ취기가 변경되었으니 하양식으로 data 값을 확인해가며 최대 힙을 구성

    int now = 0, leftChild = 1, rightChild=2;
    //now는 최상단 루트의 위치, 최상된 루트의 자식값의 왼쪽과 오른쪽
    int target = now;

    //새 원소를 추출한 이후에 하향식으로 힙을 구성
    while (leftChild<root->count){
        if(root->heap[target] < root-> heap[leftChild]) target = leftChild;
        //현재 부모값보다 왼쪽의 자식값이 더 크면 target에 자식값을 참조
        if(root->heap[target] < root->heap[rightChild] && rightChild < root->count) target = rightChild;
        //현재 부모값보다 오른쪽 자식값이 더 크고 rightChild index 값보다 현재 index 값이 더 크면 target에 자식값을 참조
        if(target == now) break; //더이상 내려가지 안항도 될 때 종료
        else{
            nodeChange(&root->heap[now],&root->heap[target]);
            now = target;
            //다음 트리 검사대상을 now에 참조, 트리를 하양식으로 내려가면서 검사를 반복
            leftChild = now * 2 +1;
            rightChild = now * 2 +2;
            //자식값 index또한 다음 index 트리로 이동시킨다.
        }
    }
    return res;
}

int main(){
    int n, input;
    priorityQueue h;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d",&input);
        if(input == 0){
            printf("print : %d\n",pop(&h));
        }
        else{
            push(&h,input);
        }
    }
}