# Question 2: Find the MIN

## Problem Statement
You are given an empty array initially. You will be given queries to perform on this array. You will be given 2 types of queries to perform.

1 X - add X to the array.
2 - If the array is empty print empty otherwise print the value which is minimum then erase all the occurrences of that value.

It is guaranteed that at least one type 2 query will be present in all the test case.

Note: The input file is too large. Must use fast I/O and don't use endl. Use "\n" instead of endl.

Fast I/O: Add these 2 lines at the first of main function -
```cpp
ios::sync_with_stdio(false);
cin.tie(NULL);
```

## Input Format
- The first line contains a single positive integer Q.
- The next Q lines will contains the queries.

## Constraints
- 1 ≤ Q ≤ 3 × 10⁶
- 1 ≤ X ≤ 10⁹

## Output Format
If the query type is 2 print the desired output as written in the problem statement. Don't forget to print a newline after each test case.

## Sample Input 0
```
12
1 16
1 11
1 15
2
1 10
2
2
1 18
2
1 13
2
2
```

## Sample Output 0
```
11
10
15
16
13
18
```

## Sample Input 1
```
17
1 10
1 16
1 10
2
1 8
1 18
2
2
1 17
2
1 17
1 9
1 9
2
2
2
2
```

## Sample Output 1
```
10
8
16
17
9
17
18
empty
```

## Solution

```cpp
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
```

## Time Complexity: O(Q log n)
## Space Complexity: O(n)

## Approach
We use a set data structure which automatically keeps elements sorted and handles duplicates. For type 1 queries, we insert the element. For type 2 queries, we get the minimum element (first element in set), print it, and erase all occurrences of it.