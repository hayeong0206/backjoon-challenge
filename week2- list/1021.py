'''
주어진 3개의 연산을 활용해 n개의 원소 중 입력된 m개의 원소를 삭제하는 최소 연산 횟수

덱 이용 (양쪽으로 삽입 삭제 가능)
'''

from collections import deque
import sys

input = sys.stdin.readline

n, m = map(int, input().split())
idxs = list(map(int, input().split()))
dq = deque([i for i in range(1, n + 1)])

count = 0
for idx in idxs:
    while True:
        if dq[0] == idx:
            dq.popleft()
            break

        else:
            if dq.index(idx) < len(dq)/2:
                while dq[0] != idx:
                    dq.append(dq.popleft())
                    count += 1
            else:
                while dq[0] != idx:
                    dq.appendleft(dq.pop())
                    count += 1
print(count)