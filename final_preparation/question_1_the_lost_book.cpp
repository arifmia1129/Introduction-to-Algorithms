#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, q; cin >> n;

    vector<ll> v(n + 1);

    for(int i = 0; i < n; i++) 
        cin >> v[i];

    cin >> q;

    ll idx = -1;

    for(int i = 0; i < n; i++){
        if(v[i] == q){
            idx = i;
            break;
        }
    }

    cout << idx;
    
    return 0;
}