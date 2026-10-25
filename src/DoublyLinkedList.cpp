#include "DoublyLinkedList.h"
#include <algorithm>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

bool DoublyLinkedList::isEmpty() const {
    return head == nullptr;
}

int DoublyLinkedList::countNodes() const {
    int count = 0;
    Node* cur = head;
    while (cur != nullptr) {
        count++;
        cur = cur->next;
    }
    return count;
}

DoublyLinkedList::Node* DoublyLinkedList::getNodeAt(int position) const {
    if (position < 1) return nullptr;
    Node* cur = head;
    for (int i = 1; cur != nullptr && i < position; ++i) {
        cur = cur->next;
    }
    return cur;
}

void DoublyLinkedList::unlinkNode(Node* node) {
    if (node == nullptr) return;

    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }

    delete node;
}

void DoublyLinkedList::insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
    std::cout << "Inserted " << val << " at beginning successfully.\n";
}

void DoublyLinkedList::insertAtEnd(int val) {
    Node* newNode = new Node(val);
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
    std::cout << "Inserted " << val << " at end successfully.\n";
}

void DoublyLinkedList::insertAtPosition(int val, int pos) {
    int total = countNodes();
    if (pos < 1 || pos > total + 1) {
        std::cout << "Invalid position! Allowed position range: 1 to " << (total + 1) << ".\n";
        return;
    }
    if (pos == 1) {
        insertAtBeginning(val);
        return;
    }
    if (pos == total + 1) {
        insertAtEnd(val);
        return;
    }

    Node* cur = getNodeAt(pos);
    if (cur == nullptr) {
        std::cout << "Invalid position.\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = cur;
    newNode->prev = cur->prev;
    cur->prev->next = newNode;
    cur->prev = newNode;
    std::cout << "Inserted " << val << " at position " << pos << " successfully.\n";
}

void DoublyLinkedList::insertAfterNode(int targetVal, int newVal) {
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
    if (cur == tail) {
        insertAtEnd(newVal);
        return;
    }
    Node* newNode = new Node(newVal);
    newNode->next = cur->next;
    newNode->prev = cur;
    cur->next->prev = newNode;
    cur->next = newNode;
    std::cout << "Inserted " << newVal << " after node " << targetVal << " successfully.\n";
}

void DoublyLinkedList::insertBeforeNode(int targetVal, int newVal) {
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
    if (cur == head) {
        insertAtBeginning(newVal);
        return;
    }
    Node* newNode = new Node(newVal);
    newNode->next = cur;
    newNode->prev = cur->prev;
    cur->prev->next = newNode;
    cur->prev = newNode;
    std::cout << "Inserted " << newVal << " before node " << targetVal << " successfully.\n";
}

void DoublyLinkedList::deleteFromBeginning() {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot delete.\n";
        return;
    }
    int deletedVal = head->data;
    unlinkNode(head);
    std::cout << "Deleted " << deletedVal << " from beginning successfully.\n";
}

void DoublyLinkedList::deleteFromEnd() {
    if (tail == nullptr) {
        std::cout << "List is empty. Cannot delete.\n";
        return;
    }
    int deletedVal = tail->data;
    unlinkNode(tail);
    std::cout << "Deleted " << deletedVal << " from end successfully.\n";
}

void DoublyLinkedList::deleteFromPosition(int pos) {
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
    if (pos == total) {
        deleteFromEnd();
        return;
    }
    Node* target = getNodeAt(pos);
    if (target == nullptr) {
        std::cout << "Invalid position.\n";
        return;
    }
    int deletedVal = target->data;
    unlinkNode(target);
    std::cout << "Deleted " << deletedVal << " from position " << pos << " successfully.\n";
}

void DoublyLinkedList::deleteByValue(int val) {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot delete.\n";
        return;
    }
    Node* cur = head;
    while (cur != nullptr && cur->data != val) {
        cur = cur->next;
    }
    if (cur == nullptr) {
        std::cout << "Value " << val << " not found in the list.\n";
        return;
    }
    unlinkNode(cur);
    std::cout << "Deleted first occurrence of value " << val << " successfully.\n";
}

void DoublyLinkedList::search(int val) const {
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

void DoublyLinkedList::update(int oldVal, int newVal) {
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

void DoublyLinkedList::displayForward() const {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    std::cout << "NULL <- ";
    Node* cur = head;
    while (cur != nullptr) {
        std::cout << cur->data;
        if (cur->next != nullptr) {
            std::cout << " <-> ";
        }
        cur = cur->next;
    }
    std::cout << " -> NULL\n";
}

void DoublyLinkedList::displayBackward() const {
    if (tail == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    std::cout << "NULL <- ";
    Node* cur = tail;
    while (cur != nullptr) {
        std::cout << cur->data;
        if (cur->prev != nullptr) {
            std::cout << " <-> ";
        }
        cur = cur->prev;
    }
    std::cout << " -> NULL\n";
}

void DoublyLinkedList::findMaximum() const {
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

void DoublyLinkedList::findMinimum() const {
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

void DoublyLinkedList::findMiddleElement() const {
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

void DoublyLinkedList::reverse() {
    if (head == nullptr || head == tail) {
        std::cout << "List reversed successfully.\n";
        return;
    }
    Node* cur = head;
    Node* temp = nullptr;
    while (cur != nullptr) {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev; // move to next node (which is now in cur->prev)
    }
    if (temp != nullptr) {
        tail = head;
        head = temp->prev;
    }
    std::cout << "List reversed successfully.\n";
}

void DoublyLinkedList::sort() {
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

void DoublyLinkedList::removeDuplicates() {
    if (head == nullptr || head->next == nullptr) {
        std::cout << "No duplicates found.\n";
        return;
    }
    int removedCount = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        Node* runner = cur->next;
        while (runner != nullptr) {
            Node* nextNode = runner->next;
            if (runner->data == cur->data) {
                unlinkNode(runner);
                removedCount++;
            }
            runner = nextNode;
        }
    }
    std::cout << "Duplicate values removed successfully (" << removedCount << " duplicates removed).\n";
}
