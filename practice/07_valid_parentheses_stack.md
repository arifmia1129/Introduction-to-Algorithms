# Question 7: Valid Parentheses

## Problem Statement
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

## Input Format
- First line contains integer t, number of test cases
- Next t lines contain strings s

## Constraints
- 1 ≤ t ≤ 10⁴
- 1 ≤ length of s ≤ 10⁴
- s consists of parentheses only

## Output Format
For each test case, print "YES" if valid, "NO" otherwise

## Sample Input 0
```
4
()
()[]{}
(]
([)]
```

## Sample Output 0
```
YES
YES
NO
NO
```

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    
    for(char c : s) {
        if(c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if(st.empty()) return false;
            
            char top = st.top();
            st.pop();
            
            if((c == ')' && top != '(') || 
               (c == ']' && top != '[') || 
               (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    return st.empty();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    
    while(t--) {
        string s; cin >> s;
        
        if(isValid(s)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
```

## Time Complexity: O(n)
## Space Complexity: O(n)

## Approach
We use a stack to keep track of opening brackets. When we encounter a closing bracket, we check if it matches the most recent opening bracket. If the stack is empty at the end, all brackets were properly matched.