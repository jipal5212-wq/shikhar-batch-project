#include "SinglyLinkedList.h"
#include <algorithm>

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

void SinglyLinkedList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool SinglyLinkedList::isEmpty() const {
    return head == nullptr;
}

int SinglyLinkedList::countNodes() const {
    int count = 0;
    Node* cur = head;
    while (cur != nullptr) {
        count++;
        cur = cur->next;
    }
    return count;
}

SinglyLinkedList::Node* SinglyLinkedList::getNodeAt(int position) const {
    if (position < 1) return nullptr;
    Node* cur = head;
    for (int i = 1; cur != nullptr && i < position; ++i) {
        cur = cur->next;
    }
    return cur;
}

void SinglyLinkedList::insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    std::cout << "Inserted " << val << " at beginning successfully.\n";
}

void SinglyLinkedList::insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
    std::cout << "Inserted " << val << " at end successfully.\n";
}

void SinglyLinkedList::insertAtPosition(int val, int pos) {
    int total = countNodes();
    if (pos < 1 || pos > total + 1) {
        std::cout << "Invalid position! Allowed position range: 1 to " << (total + 1) << ".\n";
        return;
    }
    if (pos == 1) {
        insertAtBeginning(val);
        return;
    }
    Node* prev = getNodeAt(pos - 1);
    if (prev == nullptr) {
        std::cout << "Invalid position.\n";
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = prev->next;
    prev->next = newNode;
    std::cout << "Inserted " << val << " at position " << pos << " successfully.\n";
}

void SinglyLinkedList::insertAfterNode(int targetVal, int newVal) {
    if (head == nullptr) {
        std::cout << "List is empty. Target node not found.\n";
        return;
    }
    Node* cur = head;
    while (cur != nullptr && cur->data != targetVal) {
        cur = cur->next;
    }
    if (cur == nullptr) {
        std::cout << "Target value " << targetVal << " not found in the list.\n";
        return;
    }
    Node* newNode = new Node(newVal);
    newNode->next = cur->next;
    cur->next = newNode;
    std::cout << "Inserted " << newVal << " after node " << targetVal << " successfully.\n";
}

void SinglyLinkedList::insertBeforeNode(int targetVal, int newVal) {
    if (head == nullptr) {
        std::cout << "List is empty. Target node not found.\n";
        return;
    }
    if (head->data == targetVal) {
        insertAtBeginning(newVal);
        return;
    }
    Node* prev = head;
    while (prev->next != nullptr && prev->next->data != targetVal) {
        prev = prev->next;
    }
    if (prev->next == nullptr) {
        std::cout << "Target value " << targetVal << " not found in the list.\n";
        return;
    }
    Node* newNode = new Node(newVal);
    newNode->next = prev->next;
    prev->next = newNode;
    std::cout << "Inserted " << newVal << " before node " << targetVal << " successfully.\n";
}

void SinglyLinkedList::deleteFromBeginning() {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot delete.\n";
        return;
    }
    Node* temp = head;
    int deletedVal = temp->data;
    head = head->next;
    delete temp;
    std::cout << "Deleted " << deletedVal << " from beginning successfully.\n";
}

void SinglyLinkedList::deleteFromEnd() {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot delete.\n";
        return;
    }
    if (head->next == nullptr) {
        int deletedVal = head->data;
        delete head;
        head = nullptr;
        std::cout << "Deleted " << deletedVal << " from end successfully.\n";
        return;
    }
    Node* cur = head;
    while (cur->next->next != nullptr) {
        cur = cur->next;
    }
    int deletedVal = cur->next->data;
    delete cur->next;
    cur->next = nullptr;
    std::cout << "Deleted " << deletedVal << " from end successfully.\n";
}

void SinglyLinkedList::deleteFromPosition(int pos) {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot delete.\n";
        return;
    }
    int total = countNodes();
    if (pos < 1 || pos > total) {
        std::cout << "Invalid position! Allowed range: 1 to " << total << ".\n";
        return;
    }
    if (pos == 1) {
        deleteFromBeginning();
        return;
    }
    Node* prev = getNodeAt(pos - 1);
    if (prev == nullptr || prev->next == nullptr) {
        std::cout << "Invalid position.\n";
        return;
    }
    Node* target = prev->next;
    int deletedVal = target->data;
    prev->next = target->next;
    delete target;
    std::cout << "Deleted " << deletedVal << " from position " << pos << " successfully.\n";
}

void SinglyLinkedList::deleteByValue(int val) {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot delete.\n";
        return;
    }
    if (head->data == val) {
        deleteFromBeginning();
        return;
    }
    Node* cur = head;
    while (cur->next != nullptr && cur->next->data != val) {
        cur = cur->next;
    }
    if (cur->next == nullptr) {
        std::cout << "Value " << val << " not found in the list.\n";
        return;
    }
    Node* target = cur->next;
    cur->next = target->next;
    delete target;
    std::cout << "Deleted first occurrence of value " << val << " successfully.\n";
}

void SinglyLinkedList::search(int val) const {
    if (head == nullptr) {
        std::cout << "List is empty. Value not found.\n";
        return;
    }
    Node* cur = head;
    int pos = 1;
    while (cur != nullptr) {
        if (cur->data == val) {
            std::cout << "Value " << val << " found at 1-based position " << pos << ".\n";
            return;
        }
        cur = cur->next;
        pos++;
    }
    std::cout << "Value " << val << " not found in the list.\n";
}

void SinglyLinkedList::update(int oldVal, int newVal) {
    if (head == nullptr) {
        std::cout << "List is empty. Value not found.\n";
        return;
    }
    Node* cur = head;
    while (cur != nullptr) {
        if (cur->data == oldVal) {
            cur->data = newVal;
            std::cout << "Updated value " << oldVal << " to " << newVal << " successfully.\n";
            return;
        }
        cur = cur->next;
    }
    std::cout << "Value " << oldVal << " not found in the list.\n";
}

void SinglyLinkedList::display() const {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    Node* cur = head;
    while (cur != nullptr) {
        std::cout << cur->data << " -> ";
        cur = cur->next;
    }
    std::cout << "NULL\n";
}

void SinglyLinkedList::findMaximum() const {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    int maxVal = head->data;
    Node* cur = head->next;
    while (cur != nullptr) {
        if (cur->data > maxVal) {
            maxVal = cur->data;
        }
        cur = cur->next;
    }
    std::cout << "Maximum value: " << maxVal << "\n";
}

void SinglyLinkedList::findMinimum() const {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    int minVal = head->data;
    Node* cur = head->next;
    while (cur != nullptr) {
        if (cur->data < minVal) {
            minVal = cur->data;
        }
        cur = cur->next;
    }
    std::cout << "Minimum value: " << minVal << "\n";
}

void SinglyLinkedList::findMiddleElement() const {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    std::cout << "Middle element: " << slow->data << " (for even-length lists, second middle is returned)\n";
}

void SinglyLinkedList::reverse() {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    Node* prev = nullptr;
    Node* cur = head;
    Node* nextNode = nullptr;
    while (cur != nullptr) {
        nextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
    }
    head = prev;
    std::cout << "List reversed successfully.\n";
}

void SinglyLinkedList::sort() {
    if (head == nullptr || head->next == nullptr) {
        std::cout << "List is sorted.\n";
        return;
    }
    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = head; j != nullptr && j->next != nullptr; j = j->next) {
            if (j->data > j->next->data) {
                std::swap(j->data, j->next->data);
            }
        }
    }
    std::cout << "List sorted in ascending order successfully (Bubble Sort).\n";
}

void SinglyLinkedList::removeDuplicates() {
    if (head == nullptr || head->next == nullptr) {
        std::cout << "No duplicates found.\n";
        return;
    }
    int removedCount = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        Node* runner = cur;
        while (runner->next != nullptr) {
            if (runner->next->data == cur->data) {
                Node* duplicateNode = runner->next;
                runner->next = duplicateNode->next;
                delete duplicateNode;
                removedCount++;
            } else {
                runner = runner->next;
            }
        }
    }
    std::cout << "Duplicate values removed successfully (" << removedCount << " duplicates removed).\n";
}
