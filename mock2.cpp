#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q; cin >> q;

    set<ll> st;

    while(q--) {
        int type; cin >> type;

        if(type == 1) {
            ll val; cin >> val;
            st.insert(val);
        }else{
            if(st.empty()) {
                cout << "empty\n";
            }else{
                ll top = *st.begin();

                cout << top << "\n";

                st.erase(top);
            }
        }
    }
    
    return 0;
}