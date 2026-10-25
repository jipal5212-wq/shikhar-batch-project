#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

class DoublyLinkedList {
public:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        explicit Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };

private:
    Node* head;
    Node* tail;

    Node* getNodeAt(int position) const;
    void unlinkNode(Node* node);

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

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
    void displayForward() const;
    void displayBackward() const;
    void findMaximum() const;
    void findMinimum() const;
    void findMiddleElement() const;
    void reverse();
    void sort();
    void removeDuplicates();
    void clear();
};

#endif // DOUBLY_LINKED_LIST_H
