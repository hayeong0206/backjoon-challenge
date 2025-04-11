'''
14225. 부분수열의 합

수열 S가 주어졌을 때, 수열 S의 부분 수열의ㅣ 합으로 나올 수 없는 가장 작은 자연수의 값 구ㅜ하기

입력 : 수열의 크기 N/ 수열 S

출력: 부분 수열의 합으로 나올 수 없는 가장 작은 자연수 출력

--> S 오름차순으로 정렬. 모든 조합의 합(combinations 이용) 구한 후 없는 가장 작은 자연수 찾아내어 출력
'''

from itertools import combinations

N = int(input())
S = list(map(int, input().split()))

sums = []
#모든 조합 구하기
for i in range(1, N+1):
    for combination in combinations(S, i):
        sums.append(sum(combination))

sums = list(set(sums)) #조합 리스트에 추가
sums.sort() # 조합 정렬

ans = len(sums) + 1
#작은 수부터 차례대로 결과 조회
for i in range(len(sums)):
    if sums[i] != i + 1:
        ans = i + 1
        break

print(ans)



