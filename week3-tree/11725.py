'''
트리의 부모 찾기

루트없는 트리가 주어짐. 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램

입력: 노드의 개수 N, 트리 상에서 연결된 두 정점이 주어짐

출력: 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력

'''

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8) #재귀 리미트

n = int(input())

# 그래프 만들기
graph = [[] for _ in range(n+1)]
for _ in range(n-1):  # 간선수는 n-1개
    x, y = map(int, input().split())  # [[1,2], [2,3] .....]
    graph[x].append(y)
    graph[y].append(x)
visited = [0] * (n+1) #방문여부 대신, 부모를 담을 변수


# dfs 함수
def dfs(v):
   # 현재 V와 연결된 다른 노드를 재귀적으로 방문
    for i in graph[v]:
        if not visited[i]:  # 방문하지 않은 노드라면
            # visited를 1이 아닌, 탐색을 시작한 값을 넣어준다 dfs는 항상 부모에서 자식으로 이동한다.
            visited[i] = v
            dfs(i)  # 해당 노드를 시작 노드로 dfs

dfs(1) #항상 1이 시작노드

# visited 출력
for i in range(2, n+1):
    print(visited[i])