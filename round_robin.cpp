#include <bits/stdc++.h>
using namespace std;

void findtat(int bt[], int wt[], int tat[], int n)
{

    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void findwt(int bt[], int wt[], int n, int quantum)
{

    int remain[n];
    int total_time = 0;

    for (int i = 0; i < n; i++)
    {
        remain[i] = bt[i];
    }

    while (1)
    {

        bool done = true;

        for (int i = 0; i < n; i++)
        {

            if (remain[i] > 0)
            {

                done = false;

                if (remain[i] > quantum)
                {
                    total_time += quantum;
                    remain[i] -= quantum;
                }

                else
                {
                    total_time += remain[i];

                    wt[i] = total_time - bt[i];

                    remain[i] = 0;
                }
            }
        }

        if (done)
            break;
    }
}

void avg(int process[], int bt[], int wt[], int tat[], int n, int quantum)
{

    findwt(bt, wt, n, quantum);
    findtat(bt, wt, tat, n);

    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];

        cout << "Process: " << i + 1 << " Burst Time: " << bt[i]
            << " Turn Around Time: "
             << tat[i] << " Waiting Time: " << wt[i] << endl;
    }

    cout << "Average Waiting Time: " << (float)total_wt / n
         << " Average Turn Around Time: " << (float)total_tat / n;
}

int main()
{

    int process[] = {0, 1, 2, 3};

    int bt[] = {1, 5, 3, 8};

    int wt[4], tat[4];

    int quantum = 1;

    avg(process, bt, wt, tat, 4, quantum);

    return 0;
}
