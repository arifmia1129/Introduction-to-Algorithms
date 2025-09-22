#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        int i = 0; string ans;

        char v[5] = {'a', 'e', 'i', 'o', 'u'};

        while(n--){
            ans += v[i];
            i++;

            if(i == 5)
                i = 0;
        }

        sort(ans.begin(), ans.end());

        cout << ans << endl;
    }

    return 0;
}