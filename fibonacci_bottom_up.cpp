#include<bits/stdc++.h>
using namespace std;

int main () {
    long long int n; cin >> n;

    long long int tet[n + 1];

    tet[0] = 0;
    tet[1] = 1;
    tet[2] = 1;
    tet[3] = 2;

    for(long long int i = 4; i <= n; i++) {
        tet[i] = tet[i - 1] + tet[i - 2] + tet[i - 3] + tet[i - 4];
    }

    cout << tet[n] << endl;

    return 0;
}