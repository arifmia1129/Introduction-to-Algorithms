#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        int ar[n + 1];

        for(int i = 0; i < n; i++)
            cin >> ar[i];

        sort(ar, ar + n);

        int mn = ar[0];
        int mx = ar[n - 1];

        int i = 0, j = n - 1, cnt1 = 0, cnt2 = 0;

        if(mx % 2 == mn % 2) {
            cout << 0 << endl;
        }else {
            while(ar[i] % 2 != mx % 2){
                i++;
                cnt1++;
            }

            while(ar[j] % 2 != mn % 2) {
                j--;
                cnt2++;
            }

            cout << min(cnt1, cnt2) << endl;
        }

    }

    return 0;
}