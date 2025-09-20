#include<bits/stdc++.h>
using namespace std;

int main () {
    int n, q; cin >> n >> q;

    vector<int> v(n);

    for(int i = 0; i < n; i++) 
        cin >> v[i];

    sort(v.begin(), v.end());

    while(q--){
        int searchVal; cin >> searchVal;

        int l = 0;
        int r = n - 1;

        bool found = false;

        while(l <= r) {
            int midIdx = (l + r) / 2;
            int midVal = v[midIdx];

            if(midVal == searchVal) {
                found = true;
                break;
            }
            else if(midVal > searchVal) {
                r = midIdx - 1;
            }else {
                l = midIdx + 1;
            }
        }

        if(found)
            cout << "found" << endl;
        else 
            cout << "not found" << endl;
    }

    return 0;
}