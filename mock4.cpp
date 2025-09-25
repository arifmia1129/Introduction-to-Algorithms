#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        string s;
        cin >> n >> s;

        int totalOperation = 0;

        while(!s.empty()) {
            string newString = "";
            int i = 0;

           
            while(i < s.size()) {
                if(i + 1 < s.size())
                    newString += s[i + 1]; 
                i += 2;
            }

            s = newString;
            totalOperation++;
        }

        cout << totalOperation << "\n";
    }

    return 0;
}
