'''
로또: 1~49 중 6개의 숫자 선택

입력: k : 고르는 수 (6 < k < 13), S: k개의 수를 가진 집합 
구할 수 있는 "모든" 수열의 개수
=> 백트래킹 
'''

def dfs(lotto, s, index, cnt):
    if cnt == 6: # 로또의 수는 6개까지만 가질 수 있으므로 6이 되면 결과 출력
        print(*lotto)
        return

    for i in range(index, len(s)):
        lotto.append(s[i])  #arr 리스트에 s[i]값 넣기 
        dfs(lotto, s, i+1, cnt + 1) 
        lotto.pop() # 마지막 요소를 지우고 그 뒤에 값넣기

while True:
    lst = list(map(int, input().split()))
    k = lst[0]
    s = lst[1:]
    if k == 0:
        break
    lotto = [] 
    dfs(lotto, s, 0, 0)
    print() # 빈칸 안만들어서 틀림 ㅎㅎ.. 