//행렬
//0과 1로만 이루어진 행렬 A와 행렬 B
//행렬 A를 B로 바꾸는데 필요한 연산의 횟수의 쵯솟값

//만약 행렬이 3*3보다 작다면 -1 출력한다.

//정수형으로 받았을 시 m이 50이라면 10^50승이 주어지는데
//이 수는 int형으로 받을 수 없음. 

//따라서 문자형으로 받아줘야함.

#include <stdio.h>

int main(){
    int A[51][51]={0};
    int B[55][55]={0};

    int N,M,i,j,count=0,k,p;

    scanf("%d %d",&N, &M);
    for(i =0; i<N; i++){
        for(j=0; j<M; j++){
            scanf("%01d",&A[i][j]);
        }
    }
    for(i =0; i<N; i++){
        for(j=0; j<M; j++){
            scanf("%1d",&B[i][j]);
        }
    }

    /*확인용
    for(i =0; i<N; i++){
        for(j=0; j<M; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

        for(i =0; i<N; i++){
        for(j=0; j<M; j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }*/

    //3*3 행렬 모두 바꿔주어야 하므로 범위는 N-2, M-2가 되어야 한다.
    for(i=0; i<N-2; i++){
        for(j=0; j<M-2; j++){
            if(A[i][j]!=B[i][j]){
                for(k=i; k<i+3; k++){
                    for(p=j; p<j+3; p++){
                        A[k][p] = 1- A[k][p];
                    }
                }
                count++;
            }
            else continue;
        }
    }

    /*확인용
    for(i =0; i<N; i++){
        for(j=0; j<M; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    for(i =0; i<N; i++){
        for(j=0; j<M; j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }*/

    //자리를 다 바꿨을 때 둘이 같지 않다면 -1 출력 후 종료
    //이때 3*3보다 작은 행렬또한 같이 비교해서 다르다면 -1 출력 됨.
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(A[i][j]!=B[i][j]){
                printf("-1");
                return 0;
            }
        }
    }
    
    //행렬이 3*3이 되지 않을 때 두 행렬이 같다면 0 출력 후 종료
    if(N<3 || M<3){
        for(i=0; i<N; i++){
            for(j=0; j<M; j++){ //여기 N이라고 써서 틀림 ^^...
                if(A[i][j]!=B[i][j]){
                    printf("0");
                    return 0;
                }
            }
        }
    }

    printf("%d",count);
    return 0;

}



