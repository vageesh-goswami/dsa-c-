#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Basic implementation: insert at head.
void insertAtHead(Node*& head, int x) {
    Node* n = new Node(x);
    n->next = head;
    head = n;
}

// Sample Problem 1: Find middle node.
// Approach: Slow and fast pointers.
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Sample Problem 2: Reverse linked list.
// Approach: Iterative pointer reversal.
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    while (head) {
        Node* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

// Sample Problem 3: Detect cycle.
// Approach: Floyd's cycle detection algorithm.
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

void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

void freeList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Node* head = nullptr;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << "List: ";
    printList(head);

    Node* mid = findMiddle(head);
    cout << "Middle: " << (mid ? mid->val : -1) << "\n";

    head = reverseList(head);
    cout << "Reversed: ";
    printList(head);

    cout << "Has cycle: " << (hasCycle(head) ? "Yes" : "No") << "\n";
    freeList(head);
    return 0;
}
