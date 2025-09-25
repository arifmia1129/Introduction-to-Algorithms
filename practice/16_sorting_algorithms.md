# Question 16: Custom Sorting with Comparator

## Problem Statement
You are given n students with their names and marks. Sort them based on the following criteria:
1. Higher marks first
2. If marks are same, lexicographically smaller name first

## Input Format
- First line contains n, number of students
- Next n lines contain name and marks of each student

## Constraints
- 1 ≤ n ≤ 10⁴
- 1 ≤ length of name ≤ 20
- 0 ≤ marks ≤ 100

## Output Format
Print students in sorted order (name and marks)

## Sample Input 0
```
5
Alice 85
Bob 90
Charlie 85
David 90
Eve 95
```

## Sample Output 0
```
Eve 95
Bob 90
David 90
Alice 85
Charlie 85
```

## Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int marks;
    
    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }
};

bool cmp(Student a, Student b) {
    if(a.marks == b.marks) {
        return a.name < b.name;
    }
    return a.marks > b.marks;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<Student> students;
    
    for(int i = 0; i < n; i++) {
        string name; int marks;
        cin >> name >> marks;
        
        students.push_back(Student(name, marks));
    }
    
    sort(students.begin(), students.end(), cmp);
    
    for(int i = 0; i < n; i++) {
        cout << students[i].name << " " << students[i].marks << "\n";
    }
    
    return 0;
}
```

## Alternative Solution using Pair

```cpp
#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<pair<int, string>> students;
    
    for(int i = 0; i < n; i++) {
        string name; int marks;
        cin >> name >> marks;
        
        students.push_back({-marks, name});
    }
    
    sort(students.begin(), students.end());
    
    for(int i = 0; i < n; i++) {
        cout << students[i].second << " " << -students[i].first << "\n";
    }
    
    return 0;
}
```

## Time Complexity: O(n log n)
## Space Complexity: O(n)

## Approach
We create a custom comparator function that first compares marks in descending order, then names in ascending order for tie-breaking. Alternative approach uses pairs with negative marks to leverage default pair sorting.