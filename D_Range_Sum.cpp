#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main () {
    int tc; cin >> tc;

    while(tc--) {
        ll x, y; cin >> x >> y;

        ll l = min(x, y);
        ll r = max(x, y);

        ll leftSum = ((l - 1) * l) / 2;
        ll rightSum = (r * (r + 1)) / 2;

        cout << rightSum - leftSum << endl;
    }

    return 0;
}