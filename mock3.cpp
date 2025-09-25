#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll prefix(ll pos) {
    ll k = (pos + 1) / 2;
    if(pos % 2 == 1) return k * k;
    else return k * (k + 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q; cin >> n >> q;


    while(q--) {
        ll l, r; cin >> l >> r;

        ll ans = prefix(r) - prefix(l - 1);

        cout << ans << "\n";
    }
    
    return 0;
}