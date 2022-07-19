#include <stdio.h>
#include <pthread.h>
#include <time.h>
#define MAX 1000

int N;
int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
int curr = 0;


int main()
{
//    clock_t t = clock();

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                c[i][j] += a[i][k] * b[k][j];
    }


     printf("Executed! N= %d \n", N);
}
