#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int n, t;

    cin >> n;

    vector<long long int> v;

    for(long long int i = 0; i < n; i++) {
        long long int x; cin >> x;

        v.push_back(x);
    }

    cin >> t;

    long long int idx = -1;


    for(long long int i = 0; i < n; i++) {
        if(v[i] == t){
            idx = i;
            break;
        }
    }

    cout << idx;
    

    return 0;
}