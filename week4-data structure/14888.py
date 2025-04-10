'''
연산자 끼워넣기

n개의 수열과 n-1개의 연산자가 주어짐, 우선순위는 무시, 나눗셈은 정수나눗셈(C++14) 기준

일일히 모든 경우의 수를 계산한 후, 최대값과 최솟값을 계산. (백트래킹)
=> 총 경우의 수 = 4^10
'''
#입력하는 수의 개수
N = int(input())
#n개의 수열을 list안에 저장
lst = list(map(int, input().split()))
#연산자 개수
operators = list(map(int, input().split()))

#최대, 최소는 +- 10^9
maxval = -1e9
minval = 1e9

def dfs(n, temp) :
    global maxval, minval

    #종료 조건 
    if n == N-1:
        maxval = max(temp, maxval)
        minval = min(temp, minval)
        return

    #연산자 계산 (+)
    if operators[0] != 0 :
        operators[0] -= 1
        dfs(n+1, temp + lst[n+1])
        operators[0] += 1 #방문횟수 초기화
    
    #연산자 계산 (-)
    if operators[1] != 0 :
        operators[1] -= 1
        dfs(n+1, temp - lst[n+1])
        operators[1] += 1 #방문횟수 초기화

    #연산자 계산 (*)
    if operators[2] != 0 :
        operators[2] -= 1
        dfs(n+1, temp * lst[n+1])
        operators[2] += 1 #방문횟수 초기화


    #연산자 계산 (/)
    if operators[3] != 0 :
        operators[3] -= 1
        dfs(n+1, int(temp / lst[n+1]))
        operators[3] += 1 #방문횟수 초기화
    
dfs(0, lst[0])
print(maxval)
print(minval)