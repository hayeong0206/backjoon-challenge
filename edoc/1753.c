//최단 경로
//방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단경로를 구하는 프로그램
//모든 간선의 가중치는 10 이하의 자연수
//입력 - 첫째줄에 정점의 개수 V, 간선의 개수 E, 둘째줄에 시작 정점의 번호K
//셋째 줄에 E개의 줄에 걸쳐 각 간선을 나타내는 (u,v,w) 순서대로 주어짐
//출력 - 첫째 줄부터 V개의 줄에 걸쳐 i번째 줄에 i번 정점으로의 최단 경로의 경로값
//시작점 자신은 0으로 출력하고, 경로가 존재하지 않은 경우에는 INF 출력 

#include <stdio.h>

//우선순위 큐 구현

#define MAX_SIZE 20001


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
    if(root->count <= 0) return -99999;
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

int daijkstra(){
    int now_nod = start
}

int main(){
    int V,E,K;
    int i;
    int u,v,w;
    priorityQueue root;
    root.count = 0;

    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    for(i=0; i<E; i++){
        scanf("%d %d %d", &u, &v, &w);

        NODE* tmp = arr_alloc()l
        tmp -> name = v;
        tmp -> val = w; 

        if(map[u]){
            tmp ->next = map[u];
            map[u] = tmp;
        }
        else map[u] = tmp;

    }

    for(i=0; i<n; i++){
        visited[i] = 999999;
    }

    push(K,0);

    while(ptr>0){
        
    }

    for(int i=0; i<2; i++){
        int data = pop(&root);
        printf("%d ",data);
    } 
}