'''
ABCDE

N명이 참가. A-B, B-C, C-D, D-E와 같은 친구관계 존재하는지 구하는 프로그램
같은 친구 관계가 두 번 이상 주어지는 경우는 없음

출력: 존재하면 1, 존재하지 않으면 0 출력

아이디어
단순히 A-B랑 친구인 관계가 존재하면 B가 친구 관계인 사람 조사
-> 조건을 만족하는 5명이 있는지 계속 반복하면서 확인하기

=> DFS 로 풀기, 친구관계를 graph로 표현 DFS depth가 5일 경우 조건 만족
'''
import sys
sys.setrecursionlimit(10000)

N, M = map(int, input().split())
graph = [[] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [False] * N
found = False

def dfs(v, depth):
    global found
    if depth == 5:
        found = True
        return
    visited[v] = True
    for friend in graph[v]:
        if not visited[friend]:
            dfs(friend, depth + 1)
            if found: return
    visited[v] = False

for i in range(N):
    dfs(i, 1)
    if found:
        break

print(1 if found else 0)
