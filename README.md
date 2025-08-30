# Linked List in Data Structures

## 📌 What is a Linked List?
A **Linked List** is a linear data structure where elements (called **nodes**) are stored in memory dynamically and linked using pointers.  
Each node contains:
- **Data**: The value to store.
- **Pointer (next)**: A reference to the next node in the list.

Unlike arrays, linked lists do not store elements in **contiguous memory**, making them flexible for dynamic memory allocation.

---

## ✅ Why use Linked List?
- **Dynamic size**: Unlike arrays, you can increase or decrease size at runtime.
- **Efficient insertion/deletion**: O(1) for inserting at the head/tail (compared to O(n) in arrays).
- **No need for contiguous memory allocation**.

---

## 🔍 Types of Linked Lists
1. **Singly Linked List**  
   Each node points to the next node.
   ```
   [data|next] -> [data|next] -> NULL
   ```

2. **Doubly Linked List**  
   Each node points to the next **and previous** node.
   ```
   NULL <- [prev|data|next] <-> [prev|data|next] -> NULL
   ```

3. **Circular Linked List**  
   The last node points back to the head.
   ```
   [data|next] -> [data|next] -> [data|next] -+
        ^--------------------------------------+
   ```

---

## 🖥 Example: Singly Linked List in C++
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    printList(head);
    return 0;
}
```

---

## 🔍 Slow and Fast Pointer Approach
**Also called Floyd’s Cycle Detection Algorithm**  
Used to:
- Find the Middle of a Linked List
- Detect Cycle in a Linked List
- Find the Starting Node of Cycle
- Check if Linked List is a Palindrome
- Remove Nth Node from End
- Find Intersection Point of Two Linked Lists


### ✅ Algorithm for Finding Middle Node:
```cpp
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;          // moves 1 step
        fast = fast->next->next;    // moves 2 steps
    }
    return slow; // middle node
}
```

### ✅ Detect Cycle in Linked List:
```cpp
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

---

## 🔄 Reverse a Linked List (Three Pointer Approach)
We use three pointers: **prev**, **curr**, and **next**.

### ✅ Algorithm:
```cpp
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse the link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }
    return prev; // new head
}
```

---

## ⚡ Complexity Analysis:
- **Insertion at head**: O(1)
- **Insertion at tail**: O(n) (unless we maintain tail pointer)
- **Deletion**: O(1) if node pointer is given
- **Search**: O(n)
- **Reverse**: O(n)
- **Cycle detection**: O(n)

---

## 📌 Summary:
- Linked List is a **dynamic, pointer-based** linear data structure.
- Useful for efficient insertions/deletions.
- **Slow & Fast Pointer** approach is key for problems like finding middle or cycle detection.
- **Three Pointer** approach is used for reversing.

---

### ✅ Example Problems:
- Find Middle of Linked List
- Detect Cycle in Linked List
- Reverse Linked List
- Merge Two Sorted Lists
- Remove Nth Node from End
- Add Two Number
- Check Palindrome Number
- Delete Given Node
- Delete Middle Node
- Intersection of Given Linked List
- Odd Even Linked List
- Sort Linked List
- Starting Loop of Cycle
