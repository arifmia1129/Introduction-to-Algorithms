# Question 4: String Vanisher - Solution

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        int n; string s;
        cin >> n >> s;

        int totalOperation = 0;

        while(!s.empty()) {
            string newString = "";
            int i = 0;

            // Skip every alternate character (remove non-adjacent ones)
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
```

## Time Complexity: O(n²)
## Space Complexity: O(n)

## Approach
In each operation, we need to select a subsequence where no two characters are adjacent. The optimal strategy is to select every alternate character starting from position 0, 2, 4, etc. This ensures we remove the maximum number of characters in each operation. We repeat this process until the string becomes empty.

The key insight is that in each operation, we can remove roughly half of the remaining characters. So the number of operations is approximately log₂(n).