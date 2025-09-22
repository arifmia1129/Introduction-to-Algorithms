#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main () {
    int n, q; cin >> n >> q;

    vector<ll> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

   while(q--) {
    int searchVal; cin >> searchVal;
    bool isFound = false;

    int leftIdx = 0;
    int rightIdx = n - 1;

    while(leftIdx <= rightIdx) {
        int midIdx = (leftIdx + rightIdx)/2;

        int midVal = v[midIdx];

        if(midVal == searchVal) {
            isFound = true;
            break;
        }else{
            if(midVal > searchVal) {
                rightIdx = midIdx - 1;
            }else{
                leftIdx = midIdx + 1;
            }
        }

        
    }
        if(isFound) 
                cout << "found" << endl;
        else
            cout << "not found" << endl;
   }

    return 0;
}