# Question 10: Binary Tree Level Order Traversal

## Problem Statement
You are given a binary tree. Print the level order traversal of the tree. If the tree is empty, print nothing.

## Input Format
- First line contains nodes in level order format where -1 represents null node
- Input ends when no more nodes to read

## Constraints
- 0 ≤ number of nodes ≤ 10⁴
- -10³ ≤ node values ≤ 10³

## Output Format
Print level order traversal, each level on a separate line

## Sample Input 0
```
1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
```

## Sample Output 0
```
1
2 3
4 5 6
7
```

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree() {
    int val; cin >> val;
    
    Node* root;
    if(val == -1) root = NULL;
    else root = new Node(val);
    
    queue<Node*> q;
    if(root) q.push(root);
    
    while(!q.empty()) {
        Node* p = q.front();
        q.pop();
        
        int l, r; cin >> l >> r;
        
        Node* myLeft;
        Node* myRight;
        
        if(l == -1) myLeft = NULL;
        else myLeft = new Node(l);
        
        if(r == -1) myRight = NULL;
        else myRight = new Node(r);
        
        p->left = myLeft;
        p->right = myRight;
        
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    
    return root;
}

void level_order(Node* root) {
    if(root == NULL) return;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        int sz = q.size();
        
        for(int i = 0; i < sz; i++) {
            Node* f = q.front();
            q.pop();
            
            cout << f->val;
            if(i < sz - 1) cout << " ";
            
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
        cout << "\n";
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = input_tree();
    level_order(root);
    
    return 0;
}
```

## Time Complexity: O(n)
## Space Complexity: O(n)

## Approach
We use BFS (Breadth-First Search) with a queue to traverse the tree level by level. We keep track of the number of nodes at each level to print them on separate lines.