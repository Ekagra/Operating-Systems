#include <bits/stdc++.h>
using namespace std;

void findtat(int bt[], int wt[], int tat[], int n)
{

    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void findwt(int at[], int bt[], int wt[], int n)
{

    int total_bt[n];
    total_bt[0] = 0;
    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        total_bt[i] = total_bt[i - 1] + bt[i - 1];

        wt[i] = total_bt[i] - at[i]; //at bcs it wanted to come at at[i] not 0

        // if (wt[i] < 0 ) wt[i] = 0;
    }
}

void avg(int process[], int bt[], int wt[], int tat[], int at[], int n)
{

    findwt(at, bt, wt, n);
    findtat(bt, wt, tat, n);

    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        int ct = tat[i] + at[i];

        cout << "Process: " << i + 1 << " Burst Time: " << bt[i]
             << " Arrival Time: " << at[i] << " Completion Time: "
             << ct << " Turn Around Time: "
             << tat[i] << " Waiting Time: " << wt[i] << endl;
    }

    cout << "Average Waiting Time: " << (float)total_wt / n
         << " Average Turn Around Time: " << (float)total_tat / n;
}

int main()
{

    int process[] = {0, 1, 2, 3};

    int bt[] = {1, 5, 3, 8};

    int at[] = {0, 1, 1, 4};

    int wt[4], tat[4];

    avg(process, bt, wt, tat, at, 4);

    return 0;
}