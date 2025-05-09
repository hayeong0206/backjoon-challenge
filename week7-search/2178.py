'''
미로 탐색

1: 이동할 수 있는 칸 / 0: 이동할 수 없는 칸
(1,1) -> (N,M) 이동할 때 지나야 하는 최소 칸 수

아이디어 1
DFS
한칸 이동할 때마다 방문 기록과 노드 하나씩 추가
더이상 진행이 불가능하면 부모 노드로 이동
최종 (n,m)칸에 도달했을 때 depth 출력
-> 시간 초과로 실패. 모든 경우의 수를 다 검색해야 하기 때문에 비효율적임

아이디어 2
BFS (너비 우선 탐색)
1. 큐 -> 시작 지점 탐색 시작
2. 이동 가능한 네방향 확인
3. 이동 가능할 경우 이동하고 거리 + 1을 해당 칸에 저장
4. 처음으로 N-1, M-1에 도달했을 때 저장된 값 출력
'''
'''
import sys
sys.setrecursionlimit(10000)

# 입력 받기
N, M = map(int, input().split())
maze = [list(map(int, input().strip())) for _ in range(N)]

# 방향: 상하좌우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 최소 경로 저장 변수
min_path = N * M  # 최대 경로 수로 초기화

# 방문 기록
visited = [[False] * M for _ in range(N)]

def dfs(x, y, depth):
    global min_path

    # 도착지에 도달한 경우
    if x == N - 1 and y == M - 1:
        min_path = min(min_path, depth)
        return

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < N and 0 <= ny < M:
            if maze[nx][ny] == 1 and not visited[nx][ny]:
                visited[nx][ny] = True
                dfs(nx, ny, depth + 1)
                visited[nx][ny] = False  # 백트래킹

# 시작 지점 방문 표시 후 DFS 시작
visited[0][0] = True
dfs(0, 0, 1)

print(min_path)

'''

from collections import deque

# 1. 입력 받기
N, M = map(int, input().split())
maze = [list(map(int, input().strip())) for _ in range(N)]

# 2. 방향 벡터 정의 (상, 하, 좌, 우)
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 3. BFS 함수 정의
def bfs(x, y):
    queue = deque()
    queue.append((x, y))  # 시작점 추가

    while queue:
        x, y = queue.popleft()

        # 4방향 모두 탐색
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 범위 벗어나는 경우 건너뛰기
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue

            # 벽(0)이거나 이미 방문한 칸은 무시
            if maze[nx][ny] == 0:
                continue

            # 이동 가능한 새 칸이면 현재 거리 + 1 갱신 후 큐에 추가
            if maze[nx][ny] == 1:
                maze[nx][ny] = maze[x][y] + 1
                queue.append((nx, ny))

    return maze[N-1][M-1]

# 4. BFS 실행 후 결과 출력
print(bfs(0, 0))

