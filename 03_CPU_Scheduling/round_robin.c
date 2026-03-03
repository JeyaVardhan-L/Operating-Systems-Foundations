#include <stdio.h>

int main() {
    int n, i, tq, time = 0, remain;
    int bt[20], rt[20], wt[20], tat[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for(time = 0, i = 0; remain != 0;) {
        if(rt[i] <= tq && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            remain--;
            tat[i] = time;
        }
        else if(rt[i] > 0) {
            rt[i] -= tq;
            time += tq;
        }

        if(i == n-1)
            i = 0;
        else
            i++;
    }

    printf("\nProcess\tBT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], tat[i], wt[i]);
    }

    return 0;
}