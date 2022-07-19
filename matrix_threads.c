#include <stdio.h>
#include <pthread.h>
#include <time.h>
#define MAX 1000

int N;
int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
int curr = 0;

void *thr(void *p)
{
    int i = curr++;

    for (int j = 0; j < MAX; j++)
        for (int k = 0; k < MAX; k++)
            c[i][j] += a[i][k] * b[k][j];
}

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

    pthread_t kid[N];

    for (int i = 0; i < N; i++)
    {
        int* p;
        pthread_create(&kid[i], NULL, thr, (void*)(p));
    }

    for (int i = 0; i < N; i++)
    {
        pthread_join(kid[i], NULL);
    }

//    for (int i = 0; i < N; i++)
//    {
//        for (int j = 0; j < N; j++)
//            printf("%d ", c[i][j]);
//        printf("\n");
//    }

//    t = clock() - t;
        printf("Executed with threads: %d \n", N);
//    printf("Time for execution: %f\n", ((double)t) / CLOCKS_PER_SEC);
}

