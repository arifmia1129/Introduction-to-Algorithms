#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main () {
    int n, q; cin >> n >> q;

    vector<ll> v(n + 1);
    vector<ll> sum(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> v[i];

        if(i == 1) {
            sum[i] = v[i];
        }else{
            sum[i] = sum[i - 1] + v[i];
        }
    }

    ll ans = 0;

    while(q--) {
        int l, r; cin >> l >> r;

        if(l == 1)
            ans = sum[r];
        else{
            ans = sum[r] - sum[l - 1];
        }

        cout << ans << endl;
    }

    return 0;
}