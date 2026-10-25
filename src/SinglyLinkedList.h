#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

class SinglyLinkedList {
public:
    struct Node {
        int data;
        Node* next;
        explicit Node(int val) : data(val), next(nullptr) {}
    };

private:
    Node* head;

    Node* getNodeAt(int position) const;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    bool isEmpty() const;
    int countNodes() const;

    // Insertion Operations
    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    void insertAtPosition(int val, int pos);
    void insertAfterNode(int targetVal, int newVal);
    void insertBeforeNode(int targetVal, int newVal);

    // Deletion Operations
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromPosition(int pos);
    void deleteByValue(int val);

    // Query & Utility Operations
    void search(int val) const;
    void update(int oldVal, int newVal);
    void display() const;
    void findMaximum() const;
    void findMinimum() const;
    void findMiddleElement() const;
    void reverse();
    void sort();
    void removeDuplicates();
    void clear();
};

#endif // SINGLY_LINKED_LIST_H
