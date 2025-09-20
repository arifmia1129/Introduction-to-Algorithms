#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main () {
    int n, q; cin >> n >> q;

    vector<ll> v(n + 1);
    vector<ll> sum(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> v[i];

        if(i > 1) {
            sum[i] = sum[i - 1] + v[i];
        }else {
            sum[i] = v[i];
        }
    }

    while(q--) {
        int l, r; cin >> l >> r;

        ll total;

        if(l == 1) {
            total = sum[r];
        }else{
            total = sum[r] - sum[l - 1];
        }

        cout << total << endl;
    }

    return 0;
}