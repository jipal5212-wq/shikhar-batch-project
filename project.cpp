/**
 * Linked List Management System
 * Complete implementation of Singly Linked List and Doubly Linked List
 * Menu-driven console application in C++
 */

#include <iostream>
#include <limits>
#include <string>
#include <algorithm>

// ==========================================
// 1. SINGLY LINKED LIST
// ==========================================
class SinglyLinkedList {
public:
    struct Node {
        int data;
        Node* next;
        explicit Node(int val) : data(val), next(nullptr) {}
    };

private:
    Node* head;

    Node* getNodeAt(int position) const {
        if (position < 1) return nullptr;
        Node* cur = head;
        for (int i = 1; cur != nullptr && i < position; ++i) {
            cur = cur->next;
        }
        return cur;
    }

public:
    SinglyLinkedList() : head(nullptr) {}

    ~SinglyLinkedList() {
        clear();
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int countNodes() const {
        int count = 0;
        Node* cur = head;
        while (cur != nullptr) {
            count++;
            cur = cur->next;
        }
        return count;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        std::cout << "Inserted " << val << " at beginning successfully.\n";
    }

    void insertAtEnd(int val) {
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

    void insertAtPosition(int val, int pos) {
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

    void insertAfterNode(int targetVal, int newVal) {
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

    void insertBeforeNode(int targetVal, int newVal) {
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

    void deleteFromBeginning() {
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

    void deleteFromEnd() {
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

    void deleteFromPosition(int pos) {
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

    void deleteByValue(int val) {
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

    void search(int val) const {
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

    void update(int oldVal, int newVal) {
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

    void display() const {
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

    void findMaximum() const {
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

    void findMinimum() const {
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

    void findMiddleElement() const {
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

    void reverse() {
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

    void sort() {
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

    void removeDuplicates() {
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
};

// ==========================================
// 2. DOUBLY LINKED LIST
// ==========================================
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

    Node* getNodeAt(int position) const {
        if (position < 1) return nullptr;
        Node* cur = head;
        for (int i = 1; cur != nullptr && i < position; ++i) {
            cur = cur->next;
        }
        return cur;
    }

    void unlinkNode(Node* node) {
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

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        clear();
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int countNodes() const {
        int count = 0;
        Node* cur = head;
        while (cur != nullptr) {
            count++;
            cur = cur->next;
        }
        return count;
    }

    void insertAtBeginning(int val) {
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

    void insertAtEnd(int val) {
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

    void insertAtPosition(int val, int pos) {
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

    void insertAfterNode(int targetVal, int newVal) {
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

    void insertBeforeNode(int targetVal, int newVal) {
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

    void deleteFromBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete.\n";
            return;
        }
        int deletedVal = head->data;
        unlinkNode(head);
        std::cout << "Deleted " << deletedVal << " from beginning successfully.\n";
    }

    void deleteFromEnd() {
        if (tail == nullptr) {
            std::cout << "List is empty. Cannot delete.\n";
            return;
        }
        int deletedVal = tail->data;
        unlinkNode(tail);
        std::cout << "Deleted " << deletedVal << " from end successfully.\n";
    }

    void deleteFromPosition(int pos) {
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

    void deleteByValue(int val) {
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

    void search(int val) const {
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

    void update(int oldVal, int newVal) {
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

    void displayForward() const {
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

    void displayBackward() const {
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

    void findMaximum() const {
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

    void findMinimum() const {
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

    void findMiddleElement() const {
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

    void reverse() {
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
            cur = cur->prev;
        }
        if (temp != nullptr) {
            tail = head;
            head = temp->prev;
        }
        std::cout << "List reversed successfully.\n";
    }

    void sort() {
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

    void removeDuplicates() {
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
};

// ==========================================
// 3. MENU AND CONSOLE DRIVER
// ==========================================
static int getIntegerInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        }
        std::cout << "Invalid input! Please enter a valid integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

static void printSinglyMenu() {
    std::cout << "\n********** Operation on Singly Linked List **********\n\n"
              << "1. Insert at Beginning\n"
              << "2. Insert at End\n"
              << "3. Insert at Position\n"
              << "4. Insert After a Node\n"
              << "5. Insert Before a Node\n\n"
              << "6. Delete from Beginning\n"
              << "7. Delete from End\n"
              << "8. Delete from Position\n"
              << "9. Delete by Value\n\n"
              << "10. Search\n"
              << "11. Update\n"
              << "12. Display\n"
              << "13. Count Nodes\n"
              << "14. Find Maximum\n"
              << "15. Find Minimum\n"
              << "16. Find Middle Element\n"
              << "17. Reverse\n"
              << "18. Sort\n"
              << "19. Remove Duplicates\n"
              << "20. Exit\n\n";
}

static void printDoublyMenu() {
    std::cout << "\n********** Operation on Doubly Linked List **********\n\n"
              << "1. Insert at Beginning\n"
              << "2. Insert at End\n"
              << "3. Insert at Position\n"
              << "4. Insert After a Node\n"
              << "5. Insert Before a Node\n\n"
              << "6. Delete from Beginning\n"
              << "7. Delete from End\n"
              << "8. Delete from Position\n"
              << "9. Delete by Value\n\n"
              << "10. Search\n"
              << "11. Update\n"
              << "12. Display Forward\n"
              << "13. Display Backward\n"
              << "14. Count Nodes\n"
              << "15. Find Maximum\n"
              << "16. Find Minimum\n"
              << "17. Find Middle Element\n"
              << "18. Reverse\n"
              << "19. Sort\n"
              << "20. Remove Duplicates\n"
              << "21. Exit\n\n";
}

static void printMainMenu() {
    std::cout << "\n==================================================\n"
              << "            LINKED LIST MANAGEMENT SYSTEM\n"
              << "==================================================\n\n"
              << "1. Singly Linked List\n"
              << "2. Doubly Linked List\n"
              << "3. Compare Singly vs Doubly Linked List\n"
              << "4. Exit\n\n";
}

static void runSinglyLinkedList(SinglyLinkedList& list) {
    int choice;
    do {
        printSinglyMenu();
        choice = getIntegerInput("Enter the choice: ");
        int val, pos, targetVal, newVal;

        switch (choice) {
            case 1:
                val = getIntegerInput("Enter value to insert: ");
                list.insertAtBeginning(val);
                break;
            case 2:
                val = getIntegerInput("Enter value to insert: ");
                list.insertAtEnd(val);
                break;
            case 3:
                val = getIntegerInput("Enter value to insert: ");
                pos = getIntegerInput("Enter 1-based position: ");
                list.insertAtPosition(val, pos);
                break;
            case 4:
                targetVal = getIntegerInput("Enter target node value: ");
                newVal = getIntegerInput("Enter new value to insert: ");
                list.insertAfterNode(targetVal, newVal);
                break;
            case 5:
                targetVal = getIntegerInput("Enter target node value: ");
                newVal = getIntegerInput("Enter new value to insert: ");
                list.insertBeforeNode(targetVal, newVal);
                break;
            case 6:
                list.deleteFromBeginning();
                break;
            case 7:
                list.deleteFromEnd();
                break;
            case 8:
                pos = getIntegerInput("Enter 1-based position to delete: ");
                list.deleteFromPosition(pos);
                break;
            case 9:
                val = getIntegerInput("Enter value to delete: ");
                list.deleteByValue(val);
                break;
            case 10:
                val = getIntegerInput("Enter value to search: ");
                list.search(val);
                break;
            case 11:
                val = getIntegerInput("Enter existing value to update: ");
                newVal = getIntegerInput("Enter new value: ");
                list.update(val, newVal);
                break;
            case 12:
                std::cout << "Current Singly Linked List:\n";
                list.display();
                break;
            case 13:
                std::cout << "Total nodes: " << list.countNodes() << "\n";
                break;
            case 14:
                list.findMaximum();
                break;
            case 15:
                list.findMinimum();
                break;
            case 16:
                list.findMiddleElement();
                break;
            case 17:
                list.reverse();
                break;
            case 18:
                list.sort();
                break;
            case 19:
                list.removeDuplicates();
                break;
            case 20:
                std::cout << "Returning to Main Menu...\n";
                break;
            default:
                std::cout << "Invalid choice! Please choose between 1 and 20.\n";
        }
    } while (choice != 20);
}

static void runDoublyLinkedList(DoublyLinkedList& list) {
    int choice;
    do {
        printDoublyMenu();
        choice = getIntegerInput("Enter the choice: ");
        int val, pos, targetVal, newVal;

        switch (choice) {
            case 1:
                val = getIntegerInput("Enter value to insert: ");
                list.insertAtBeginning(val);
                break;
            case 2:
                val = getIntegerInput("Enter value to insert: ");
                list.insertAtEnd(val);
                break;
            case 3:
                val = getIntegerInput("Enter value to insert: ");
                pos = getIntegerInput("Enter 1-based position: ");
                list.insertAtPosition(val, pos);
                break;
            case 4:
                targetVal = getIntegerInput("Enter target node value: ");
                newVal = getIntegerInput("Enter new value to insert: ");
                list.insertAfterNode(targetVal, newVal);
                break;
            case 5:
                targetVal = getIntegerInput("Enter target node value: ");
                newVal = getIntegerInput("Enter new value to insert: ");
                list.insertBeforeNode(targetVal, newVal);
                break;
            case 6:
                list.deleteFromBeginning();
                break;
            case 7:
                list.deleteFromEnd();
                break;
            case 8:
                pos = getIntegerInput("Enter 1-based position to delete: ");
                list.deleteFromPosition(pos);
                break;
            case 9:
                val = getIntegerInput("Enter value to delete: ");
                list.deleteByValue(val);
                break;
            case 10:
                val = getIntegerInput("Enter value to search: ");
                list.search(val);
                break;
            case 11:
                val = getIntegerInput("Enter existing value to update: ");
                newVal = getIntegerInput("Enter new value: ");
                list.update(val, newVal);
                break;
            case 12:
                std::cout << "Doubly Linked List (Forward):\n";
                list.displayForward();
                break;
            case 13:
                std::cout << "Doubly Linked List (Backward):\n";
                list.displayBackward();
                break;
            case 14:
                std::cout << "Total nodes: " << list.countNodes() << "\n";
                break;
            case 15:
                list.findMaximum();
                break;
            case 16:
                list.findMinimum();
                break;
            case 17:
                list.findMiddleElement();
                break;
            case 18:
                list.reverse();
                break;
            case 19:
                list.sort();
                break;
            case 20:
                list.removeDuplicates();
                break;
            case 21:
                std::cout << "Returning to Main Menu...\n";
                break;
            default:
                std::cout << "Invalid choice! Please choose between 1 and 21.\n";
        }
    } while (choice != 21);
}

static void compareSinglyVsDoubly() {
    std::cout << "\n========================================================================================\n"
              << "                        COMPARE SINGLY vs DOUBLY LINKED LIST\n"
              << "========================================================================================\n"
              << "Property                 | Singly Linked List            | Doubly Linked List\n"
              << "-------------------------+-------------------------------+------------------------------\n"
              << "Pointers per Node        | 1 (next)                      | 2 (prev and next)\n"
              << "Memory Consumption       | Lower memory overhead         | Higher memory overhead\n"
              << "Traversal Direction      | Forward only                  | Bidirectional (forward & back)\n"
              << "Insert at Beginning      | O(1)                          | O(1)\n"
              << "Insert at End            | O(n) without tail             | O(1) with tail / O(n) without\n"
              << "Delete from End          | O(n) (requires traversal)     | O(1) with tail reference\n"
              << "Delete Given Node Ref    | O(n) (need previous node)     | O(1) (direct relink via prev)\n"
              << "Reverse Operation        | Requires pointer reversal     | Reverse pointers or read tail\n"
              << "Implementation Overhead  | Simpler pointer logic         | More complex (two-way links)\n"
              << "Ideal Use Cases          | Stacks, Simple queues, RAM    | Navigation, History, Playlists\n"
              << "========================================================================================\n\n"
              << "Summary:\n"
              << "Choose Singly Linked List when memory conservation is critical and forward traversal suffices.\n"
              << "Choose Doubly Linked List when backward navigation and frequent arbitrary deletions are required.\n";
}

int main() {
    SinglyLinkedList singlyList;
    DoublyLinkedList doublyList;
    int mainChoice;

    do {
        printMainMenu();
        mainChoice = getIntegerInput("Enter your choice: ");

        switch (mainChoice) {
            case 1:
                runSinglyLinkedList(singlyList);
                break;
            case 2:
                runDoublyLinkedList(doublyList);
                break;
            case 3:
                compareSinglyVsDoubly();
                break;
            case 4:
                std::cout << "\nExiting Linked List Management System. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please choose an option from 1 to 4.\n";
        }
    } while (mainChoice != 4);

    return 0;
}
