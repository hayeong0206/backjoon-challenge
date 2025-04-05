'''

트리의 지름

트리에서 임의의 두 점 사이의 거리 중 가장 긴 것
- 트리의 지름을 구하는 프로그램

입력: 트리의 정점 개수 V, V개 줄에 걸쳐 간선의 정보가 주어짐
정점 번호, 정점번호, 정점까지의 거리
각 줄의 마지막에는 -1이 입력으로 주어짐

출력: 트리의 지름 출력

=> 경로찾기 (DFS/ BFS)로 해결 가능
'''

import sys
from collections import deque

V = int(sys.stdin.readline())
tree = {}

for _ in range(V):
    line = list(map(int, sys.stdin.readline().split()))
    now = line[0]
    tree[now] = []
    for i in range(len(line) // 2 - 1):
        tree[now].append([line[2 * i + 1], line[2 * i + 2]])


def DFS(n):
    visit = [-1] * (V + 1)
    que = deque([n])
    visit[n] = 0
    long_node, long_dis = 0, 0

    while que:
        now = que.pop()
        for next, dis in tree[now]:
            if visit[next] == -1:
                visit[next] = visit[now] + dis
                que.append(next)
                if long_dis < visit[next]:
                    long_node = next
                    long_dis = visit[next]

    return long_node, long_dis


node, dis = DFS(1)
node, dis = DFS(node)
print(dis)