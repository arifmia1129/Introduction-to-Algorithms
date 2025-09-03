#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;

    while(t--) {
    int evenCnt = 0, oddCnt = 0;


    int n; cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) 
        cin >> v[i];

    bool flag = 0;

    for(int i = 0; i < n; i++) {

        if(v[i] % 2 == flag) {
            evenCnt++;
            flag = !flag;
        }
    }

    flag = 1;

    for(int i = 0; i < n; i++) {

        if(v[i] % 2 == flag) {
            oddCnt++;
            flag = !flag;
        }
    }

    cout << max(evenCnt, oddCnt) << endl;
}
    return 0;
}