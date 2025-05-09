'''
기타 레슨

N개의 블루레이 녹화 -> i번과 j번 강의를 같은 블루레이에 녹화할 경우 그 사이 모든 강의도 녹화해야함
M개의 블루레이에 모든 기타 강의 동영상 녹화, 크기는 최소, 블루레이는 모두 같은 크기

분 단위(자연수)가 주어짐 -> 가능한 블루레이 크기 중 최소를 구하는 프로그램

아이디어
최소값: 가장 긴 강의 1개의 길이
최대값: 모든 강의를 하나의 블루레이에 넣는 경우
이 사이에서 값 구하기 ~
-> 주어진 블루레이 크기로 강의들을 왼쪽 순서부터 담음
-> 용량 초과시 새 블루레이 사용
-> 총 사용한 블루레이 수가 M보다 작거나 가능하면 가능 !

'''


def count_blurays(lectures, capacity):
    count = 1
    total = 0
    for l in lectures:
        if total + l > capacity:
            count += 1
            total = l
        else:
            total += l
    return count


def binary_search(lectures, M):
    left = max(lectures)
    right = sum(lectures)
    answer = right

    while left <= right:
        mid = (left + right) // 2
        required = count_blurays(lectures, mid)

        if required <= M:
            answer = mid
            right = mid - 1
        else:
            left = mid + 1
    return answer


# 입력
N, M = map(int, input().split())
lectures = list(map(int, input().split()))

# 출력
print(binary_search(lectures, M))