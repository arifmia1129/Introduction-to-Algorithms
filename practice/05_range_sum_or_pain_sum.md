# Question 5: Range Sum or Pain Sum - Solution

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll prefix(ll pos) {
    ll k = (pos + 1) / 2;
    if(pos % 2 == 1) return k * k;
    else return k * (k + 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q; cin >> n >> q;

    while(q--) {
        ll l, r; cin >> l >> r;

        ll ans = prefix(r) - prefix(l - 1);

        cout << ans << "\n";
    }
    
    return 0;
}
```

## Time Complexity: O(q)
## Space Complexity: O(1)

## Approach
The sequence has a pattern where each number from 1 to n/2 appears exactly twice: [1,1,2,2,3,3,4,4,5,5].

To solve range sum queries efficiently, we use prefix sums. The key insight is to find a mathematical formula for the prefix sum.

For position `pos`, we can calculate the prefix sum using:
- k = (pos + 1) / 2
- If pos is odd: prefix sum = k²
- If pos is even: prefix sum = k × (k + 1)

For a range query from L to R, the answer is prefix(R) - prefix(L-1).

## Explanation
- Position 1: sum = 1 (k=1, odd: 1² = 1)
- Position 2: sum = 2 (k=1, even: 1×2 = 2)  
- Position 3: sum = 4 (k=2, odd: 2² = 4)
- Position 4: sum = 6 (k=2, even: 2×3 = 6)

This pattern continues, allowing O(1) calculation of prefix sums.