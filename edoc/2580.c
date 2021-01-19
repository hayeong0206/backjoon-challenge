//스도쿠
//알고리즘 유형 - 백트래킹
//스도쿠판 각 줄에 쓰여있는 숫자가 한 칸씩 띄어서 차례로 주어짐.
//빈칸의 경우에는 0이 주어짐
//스도쿠 판을 규칙대로 채울 수 없는 경우의 입력은 주어지지 않음.
//출력 - 모든 빈칸이 채워진 스도쿠 판의 최종 모습을 아홉 줄에 걸쳐 한 줄에 9개씩 한 칸씩 띄워서 출력
//스도쿠 판을 채우는 방법이 여럿인 경우는 그 중 하나만을 출력

//확인해야하는 것 
//1. 가로/세로 선에 1~9 입력
//2. 3*3 칸에 1~9 모두 입력 

#include <stdio.h>
#include <stdlib.h>

#define N 9



//완성된 스도쿠를 출력하는 함수
void print(int arr[N][N]){
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

//완성된 함수가 스도쿠 조건을 만족하는 지 확인하는 함수 
int check(int arr[N][N],int row, int col,int num){
    int i,j;
    //각 행과 열에 같은 수가 있는 지 확인
    for(i=0; i<9; i++){
        if(arr[row][i] == num || arr[i][col] == num) return 0;
    }

    int rrow =row - (row%3);
    int rcol =col - (col%3);
    //3*3칸 안에 같은 수가 있는 지 확인 
    for (i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(arr[i+rrow][j+rcol] == num) return 0;
        }
    }
    return 1;
}

// 스도쿠를 만드는 함수 
int solve(int arr[N][N], int row, int col){

    //row 8, col 9결국 9*9의 스도쿠를 모두 검사했다면 종료한다. 
    if(row == 8 && col == 9) return 1;

    //9번째 열까지 모두 검사 했다면 행을 1더하고 0번째 열로 돌아간다. 
    if(col==9){
        row++;
        col = 0;
    }

    //만약 요소가 0보다 크다면 그 다음 열을 검사한다. 
    if(arr[row][col]>0) 
        return solve(arr,row,col+1);

    //들어갈 수를 정해주기 위해 num을 1~9로 루프문을 돌린다. 
    for(int num=1; num<= 9; num++){
        //check에서 1이 나왔다면 그 해당 요소를 그 해당 num으로 바꾼다. 
        if(check(arr,row,col,num) == 1){
            arr[row][col] = num;
            //다음 열의 가능성을 검사한다. 
            if(solve(arr,row,col+1)==1) return 1;
        }
        arr[row][col]=0;
    }
    return 0;
}

int main(){
    int sudoku[N][N];
    int i,j;
    for (i=0; i<9; i++){
        for (j=0; j<9; j++){
            scanf("%d",&sudoku[i][j]);
        }
    }// 스도쿠의 숫자를 입력 받음.
    if(solve(sudoku,0,0) == 1) print(sudoku);
    return 0;
}