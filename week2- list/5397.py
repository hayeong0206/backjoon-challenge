'''
키로거

스택/연결 리스트 알고리즘

키보드를 누른 명령을 모두 기록 -> 비밀번호를 알아내는 프로그램

백스페이스 입력시 '-'가 주어지고 앞 글자 지움
화살표 입력은 '<'와 '>'로 주어짐
커서의 위치를 움직일 수 있다면 왼쪽 / 오른쪽으로 1만큼 움직임
커서의 위치가 줄의 마지막이 아니라면, 커서 및 커서 오른쪽에 있는 모든 문자는 오른쪽으로 이동
'''

import sys
input = sys.stdin.readline

n = int(input())

for i in range(n):
    password = list(input().strip())
    left, right = [], []

    for j in password:
        if j == '<':
            if left:
                right.append(left.pop())
        elif j == '>':
            if right:
                left.append(right.pop())
        elif j == '-':
            if left:
                left.pop()
        else:
            left.append(j)

    left.extend(reversed(right))

    print(''.join(left))
    print(password)