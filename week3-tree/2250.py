'''

트리의 높이와 너비

이진트리를 주어진 규칙에 따라 격자 모양 틀속에 그림
주어진 이진트리를 그릴때 너비가 가장 넓은 레벨과 그 레벨의 너비 계산

입력: 노드 개수 N, 노드 번호와 왼쪽 자삭 오른쪽 자식 노드의 번호가 순서대로 주어짐.
자식이 없는 경우 -1이 주어짐

출력 너비가 가장 넓은 레벨과 레벨의 너비를 순서대로 출력
너비가 가장 넓은 레벨이 두개 이상 있는 경우 번호가 작은 레벨 출력

'''

# 중위 순회를 통한 너비 구하기
from sys import stdin


# 하나의 노드를 클래스로 구성
class Node:
    def __init__(self, number, parent, left_node, right_node):
        self.parent = parent
        self.number = number
        self.left_node = left_node
        self.right_node = right_node


# 중위 순회
def in_order_tree(node, level):
    global position
    if node.left_node != -1:
        in_order_tree(tree[node.left_node], level + 1)  # 왼쪽 노드가 있는 경우 먼저 방문, 레벨 + 1

    position += 1  # 해당 노드의 위치 지정
    if level in result:
        result[level].append(position)  # 해당 레벨에 이미 다른 노드의 위치가 들어가 있는 경우 리스트 뒤에 추가
    else:
        result[level] = [position]  # 해당 레벨에 노드가 처음인 경우 리스트 형태로 노드 위치 추가

    if node.right_node != -1:
        in_order_tree(tree[node.right_node], level + 1)  # 오른쪽 노드가 있는 경우 방문, 레벨 + 1


n = int(stdin.readline())  # 노드의 총 개수 입력 받기
tree = dict()

# 노드 초기화 하기 (일단 부모 노드, 왼쪽 자식 노드, 오른쪽 자식 노드 모두 -1 로 지정)
for i in range(1, n + 1):
    tree[i] = Node(i, -1, -1, -1)

# 각 노드 입력 받기
for _ in range(n):
    nd, left, right = map(int, stdin.readline().split())

    # 왼쪽 자식 노드가 있는 경우
    if left != -1:
        tree[nd].left_node = left  # 해당 노드의 왼쪽 자식 노드 추가
        tree[left].parent = nd  # 왼쪽 자식 노드의 부모 노드로 해당 노드 추가

    # 오른쪽 자식 노드가 있는 경우
    if right != -1:
        tree[nd].right_node = right  # 해당 노드의 오른쪽 자식 노드 추가
        tree[right].parent = nd  # 오른쪽 자식 노드의 부모 노드로 해당 노드 추가

position = 0  # 현재 방문한 노드의 위치
result = dict()  # 레벨 별 노드의 위치를 담은 dicionary

# 부모 노드가 -1 인 노드 찾기 (해당 노드가 시작점이 됨)
root = 1
for i in range(1, len(tree) + 1):
    if tree[i].parent == -1:
        root = tree[i].number

in_order_tree(tree[root], 1)  # (시작 노드, 레벨) 전달

width = (0, 0)
for i in range(1, len(result) + 1):
    w = result[i][-1] - result[i][0] + 1
    if w > width[1]:
        width = (i, w)

print(width[0], width[1])