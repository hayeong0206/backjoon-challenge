'''
트리 순회

이진 트리를 입력받아 전위, 중위, 후위 순회한 결과를 출력하는 프로그램

입력: 이진 트리 노드의 개수 N, 노드, 왼쪽 자식노드, 오른쪽 자식 노드가 주어짐.
자식노드가 없는 경우에는 . 으로 표현

'''

n = int(input())
inputs = []
for _ in range(n):
    inputs.append(input().split())


class Node():
    def __init__(self, item, left, right):
        self.item = item
        self.left = left
        self.right = right


def preorder(node):
    print(node.item, end='')
    if node.left != '.':
        preorder(tree[node.left])
    if node.right != '.':
        preorder(tree[node.right])


def inorder(node):
    if node.left != '.':
        inorder(tree[node.left])
    print(node.item, end='')
    if node.right != '.':
        inorder(tree[node.right])


def postorder(node):
    if node.left != '.':
        postorder(tree[node.left])
    if node.right != '.':
        postorder(tree[node.right])
    print(node.item, end='')


tree = {}
for item, left, right in inputs:
    tree[item] = Node(item, left, right)
preorder(tree['A'])
print()
inorder(tree['A'])
print()
postorder(tree['A'])