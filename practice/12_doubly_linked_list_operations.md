# Question 12: Doubly Linked List Operations

## Problem Statement
Implement a doubly linked list with the following operations:
1. Insert at head
2. Insert at tail  
3. Insert at position
4. Delete at position
5. Print forward
6. Print backward

## Input Format
- First line contains q, number of operations
- Next q lines contain operations:
  - 1 X: Insert X at head
  - 2 X: Insert X at tail
  - 3 I X: Insert X at position I (0-indexed)
  - 4 I: Delete node at position I (0-indexed)
  - 5: Print forward
  - 6: Print backward

## Constraints
- 1 ≤ q ≤ 10³
- 1 ≤ X ≤ 10³
- 0 ≤ I ≤ current list size

## Output Format
For operations 5 and 6, print the list. If list is empty, print "Empty"

## Sample Input 0
```
7
1 10
2 20
3 1 15
5
4 0
5
6
```

## Sample Output 0
```
10 15 20
15 20
20 15
```

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    int sz;
    
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        sz = 0;
    }
    
    void insert_at_head(int val) {
        sz++;
        Node* newNode = new Node(val);
        
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    
    void insert_at_tail(int val) {
        sz++;
        Node* newNode = new Node(val);
        
        if(tail == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    
    void insert_at_position(int pos, int val) {
        if(pos == 0) {
            insert_at_head(val);
            return;
        }
        
        if(pos == sz) {
            insert_at_tail(val);
            return;
        }
        
        sz++;
        Node* newNode = new Node(val);
        Node* tmp = head;
        
        for(int i = 1; i <= pos - 1; i++) {
            tmp = tmp->next;
        }
        
        newNode->next = tmp->next;
        tmp->next = newNode;
        newNode->next->prev = newNode;
        newNode->prev = tmp;
    }
    
    void delete_at_position(int pos) {
        sz--;
        
        if(pos == 0) {
            Node* deleteNode = head;
            head = head->next;
            if(head) head->prev = NULL;
            else tail = NULL;
            delete deleteNode;
            return;
        }
        
        Node* tmp = head;
        for(int i = 1; i <= pos; i++) {
            tmp = tmp->next;
        }
        
        Node* deleteNode = tmp;
        
        if(tmp->next) tmp->next->prev = tmp->prev;
        else tail = tmp->prev;
        
        if(tmp->prev) tmp->prev->next = tmp->next;
        
        delete deleteNode;
    }
    
    void print_forward() {
        if(head == NULL) {
            cout << "Empty\n";
            return;
        }
        
        Node* tmp = head;
        while(tmp != NULL) {
            cout << tmp->val;
            if(tmp->next != NULL) cout << " ";
            tmp = tmp->next;
        }
        cout << "\n";
    }
    
    void print_backward() {
        if(tail == NULL) {
            cout << "Empty\n";
            return;
        }
        
        Node* tmp = tail;
        while(tmp != NULL) {
            cout << tmp->val;
            if(tmp->prev != NULL) cout << " ";
            tmp = tmp->prev;
        }
        cout << "\n";
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    DoublyLinkedList dll;
    
    int q; cin >> q;
    
    while(q--) {
        int op; cin >> op;
        
        if(op == 1) {
            int x; cin >> x;
            dll.insert_at_head(x);
        } else if(op == 2) {
            int x; cin >> x;
            dll.insert_at_tail(x);
        } else if(op == 3) {
            int i, x; cin >> i >> x;
            dll.insert_at_position(i, x);
        } else if(op == 4) {
            int i; cin >> i;
            dll.delete_at_position(i);
        } else if(op == 5) {
            dll.print_forward();
        } else if(op == 6) {
            dll.print_backward();
        }
    }
    
    return 0;
}
```

## Time Complexity: O(n) per operation for insertion/deletion at position, O(1) for head/tail operations
## Space Complexity: O(1) per operation

## Approach
We implement a doubly linked list class with head and tail pointers. Each node has both next and previous pointers, allowing bidirectional traversal. We maintain size to handle edge cases efficiently.