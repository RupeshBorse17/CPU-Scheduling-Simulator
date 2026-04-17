#include <iostream>
#include <algorithm>
using namespace std;

void fcfs(int bt[], int n) {
    int wt[n], tat[n];

    wt[0] = 0;

    // Waiting Time
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround Time
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    float avg_wt = 0, avg_tat = 0;

    cout << "\n--- FCFS Scheduling ---\n";
    cout << "Process\tBT\tWT\tTAT\n";

    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    cout << "Average Waiting Time: " << avg_wt/n << endl;
    cout << "Average Turnaround Time: " << avg_tat/n << endl;
}

void sjf(int bt[], int n) {
    int wt[n], tat[n];

    // Sort burst time (SJF)
    sort(bt, bt + n);

    wt[0] = 0;

    // Waiting Time
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround Time
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    float avg_wt = 0, avg_tat = 0;

    cout << "\n--- SJF Scheduling ---\n";
    cout << "Process\tBT\tWT\tTAT\n";

    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    cout << "Average Waiting Time: " << avg_wt/n << endl;
    cout << "Average Turnaround Time: " << avg_tat/n << endl;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], bt_copy[n];

    cout << "Enter Burst Time for each process:\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << ": ";
        cin >> bt[i];
        bt_copy[i] = bt[i]; // copy for SJF
    }

    fcfs(bt, n);
    sjf(bt_copy, n);

    return 0;
}