'''
신기한 소수
7331 -> 왼쪽부터 1자리, 2자리, 3자리, 4자리 모두 소수

N자리 숫자중 어떤 수들이 신기한 소수인지

아이디어
단순히 n자리 수에서 신기한 소수를 하나씩 검사하는 건 효율 없을 것 같음

1. 한자리 수 중 소수인 수 찾기
2. 1에서 찾은 수를 십의자리로 하는 2자리 수 중 소수인 수 찾기
3. 2에서 찾은 2자리 수를 기준으로 3자리 수 중 소수인 수 찾기
n번까지 반복하면 ?

'''

import math


# 소수 판별 함수
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True


# 백트래킹으로 신기한 소수 생성
def find_interesting_primes(n, current, depth):
    if depth == n:
        print(current)
        return

    for digit in range(1, 10):
        next_number = current * 10 + digit
        if is_prime(next_number):
            find_interesting_primes(n, next_number, depth + 1)


# 입력 및 실행
N = int(input())
# 한 자리 신기한 소수부터 시작
for prime in [2, 3, 5, 7]:
    find_interesting_primes(N, prime, 1)