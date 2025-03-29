'''
풍선 터뜨리기

알고리즘 분류 - 덱
'''

import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

d = deque()
for i in range(N):
    d.append(i)

for i in range(N):
    out = d.popleft()
    print(out+1, end=' ')
    if len(d) == 0:
        break
    rotation = arr[out]
    if rotation < 0:
        for j in range(abs(rotation)):
            x = d.pop()
            d.appendleft(x)
    elif rotation > 0:
        for j in range(abs(rotation)-1):
            x = d.popleft()
            d.append(x)