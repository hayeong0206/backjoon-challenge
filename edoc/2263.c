// 트리의 순회
// n개의 정점을 갖는 이진트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨짐
// 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램 
// 입력 - 첫째 줄에 n, 인오더를 나타내는 n개의 자연수, 다음 줄에는 같은 식으로 포스트 오더
// 출력 - 프리오더 출력 

// inorder - 중위순회, preorder -전위순회, postorder - 후위 순회

#include <stdio.h>

int n, in[100001] = {0}, post[100001] = {0};

void solve(int in_l, int in_r, int post_l, int post_r){
    int i;
    if(post_l <= post_r){
        int parent = post[post_r];
        printf("%d ",parent);
        for(i=in_l; in[i]!=parent; i++);
        int l_num = i - in_l;
        int r_num = in_r - i;
        solve(in_l, in_l + l_num - 1, post_l, post_l + l_num -1);
        solve(in_r - r_num +1, in_r, post_r-r_num, post_r-1);
    }
}

int main(){
    int i;

    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&in[i]);
    }
    for(i=0; i<n; i++){
        scanf("%d",&post[i]);
    }
    solve(0,n-1,0,n-1);

}

