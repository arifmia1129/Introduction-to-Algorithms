#include<bits/stdc++.h>
using namespace std;
int val[1005];
int weight[1005];

int knapsack(int i, int maxWeight) {
    if(i < 0 || maxWeight <= 0)
        return 0;

    if(weight[i] <= maxWeight) {
        int op1 = knapsack(i - 1, maxWeight - weight[i]) + val[i];
        int op2 = knapsack(i - 1, maxWeight);

        return max(op1, op2);
    }else{
        return knapsack(i - 1, maxWeight);
    }
}

int main () {
    int n; cin >> n;

    for(int i = 0; i < n; i++)
        cin >> val[i];

    for(int i = 0; i < n; i++)
        cin >> weight[i];

    int maxWeight; cin >> maxWeight;

    cout << knapsack(n - 1, maxWeight);

    return 0;
}