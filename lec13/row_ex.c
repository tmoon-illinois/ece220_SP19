#include <stdio.h>

#define N 3
#define M 5
int matrix_change(int matrix[N][M], int x, int y);
int matrix_transpose(int des_matrix[M][N], int src_matrix[N][M]);
void print_matrix(int *matrix, int size_row, int size_col);
//void print_matrix(int matrix[N][M], int size_row, int size_col);
int main()
{
    int matrix[N][M];

    int i,j;
    for(i=0 ; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            matrix[i][j] = M*i + j;
        }
    }

    print_matrix(&matrix[0][0], N,M);

    int x = 0, y=1;
    int des_matrix[M][N];
    //matrix_change(matrix, x,y);
    matrix_transpose(des_matrix, matrix);
    //printf("After exchange\n");
    printf("After transpose\n");
    print_matrix(&des_matrix[0][0], M,N);

}

int matrix_change(int matrix[N][M], int x, int y)
{
    if( x>N-1 || y>M-1 || x<0 || y<0)
        return -1;

    int j;
    int temp;
    for(j=0;j<M;j++)
    {
        temp = matrix[x][j];
        matrix[x][j]= matrix[y][j];
        matrix[y][j] = temp;
    }
    return 0;

}
void print_matrix(int *matrix, int size_row, int size_col)
{
    int i,j;
    for(i=0 ; i<size_row; i++)
    {
        for(j=0; j<size_col; j++)
        {
            printf("%4d ", matrix[i*size_col + j]);
        }
        printf("\n");
    }
    printf("\n");

}
int matrix_transpose(int des_matrix[M][N], int src_matrix[N][M])
{
    int i,j;

    for(i=0; i<M ; i++)
    {
        for(j=0;j<N;j++)
        {
            des_matrix[i][j] = src_matrix[j][i];
        }
    }

}







