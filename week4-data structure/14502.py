'''
14502. 연구소

크기가 N*M인 연구소, 1*1 크기의 정사각형으로 나뉨
연구소는 빈칸, 벽으로 이뤄져 있으며, 벽은 칸 하나를 가득 차지함
바이러스는 상화좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있음
새로 세울 수 있는 벽의 개수는 3개, 꼭 3개를 모두 세워야 함
벽 3개를 세운 뒤, 바이러스가 퍼질 수 없는 구역을 안전 영역이라고 함.

연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램

- 벽을 세울 수 있는 모든 경우의 수를 탐색해야 하므로 -> 백트래킹
- 바이러스가 퍼지는 과정 -> bfs (미로 탐색과 유사)
'''

from collections import deque
import copy
n,m = map(int, input().split())
graph = []
dx = [0, 0, 1, -1]
dy = [-1, 1, 0, 0]

def bfs():
    queue = deque()
    tmp_graph = copy.deepcopy(graph)

    for i in range(n):
        for j in range(m):
            if tmp_graph[i][j] == 2:
                queue.append((i, j))

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if tmp_graph[nx][ny] == 0:
                tmp_graph[nx][ny] = 2
                queue.append((nx, ny))

    global ans
    cnt = 0

    for i in range(n):
        cnt += tmp_graph[i].count(0)

    ans = max(ans,cnt)

def makewall(cnt):
    if cnt == 3:
        bfs() # 벽 3개를 세우면, 바이러스 퍼트린 후, 안전구역 찾기
        return

    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0: # 빈공간일 경우
                graph[i][j] = 1 # 벽 세우기
                makewall(cnt+1) # 다음 벽 세우기
                graph[i][j] = 0 # 벽 허물기 (백트래킹)

for i in range(n):
    graph.append(list(map(int, input().split())))
ans = 0
makewall(0)
print(ans)