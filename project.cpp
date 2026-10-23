#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;
class SinglyLinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int x) : data(x), next(nullptr) {}
    };
    Node* head = nullptr;
public:
    ~SinglyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insertBeginning(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
        cout << "Inserted successfully.\n";
    }

    void insertEnd(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
        cout << "Inserted successfully.\n";
    }

    void insertPosition(int x, int pos) {
        if (pos < 1) {
            cout << "Invalid position.\n";
            return;
        }
        if (pos == 1) {
            insertBeginning(x);
            return;
        }
        Node* cur = head;
        for (int i = 1; cur && i < pos - 1; i++)
            cur = cur->next;

        if (!cur) {
            cout << "Invalid position.\n";
            return;
        }

        Node* n = new Node(x);
        n->next = cur->next;
        cur->next = n;
        cout << "Inserted successfully.\n";
    }

    void insertAfter(int target, int x) {
        Node* cur = head;
        while (cur && cur->data != target)
            cur = cur->next;

        if (!cur) {
            cout << "Value not found.\n";
            return;
        }

        Node* n = new Node(x);
        n->next = cur->next;
        cur->next = n;
    }

    void insertBefore(int target, int x) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == target) {
            insertBeginning(x);
            return;
        }

        Node* cur = head;
        while (cur->next && cur->next->data != target)
            cur = cur->next;

        if (!cur->next) {
            cout << "Value not found.\n";
            return;
        }

        Node* n = new Node(x);
        n->next = cur->next;
        cur->next = n;
    }

    void deleteBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* cur = head;
        while (cur->next->next)
            cur = cur->next;

        delete cur->next;
        cur->next = nullptr;
    }

    void deletePosition(int pos) {
        if (pos < 1 || !head) {
            cout << "Invalid position.\n";
            return;
        }
        if (pos == 1) {
            deleteBeginning();
            return;
        }

        Node* cur = head;
        for (int i = 1; cur && i < pos - 1; i++)
            cur = cur->next;

        if (!cur || !cur->next) {
            cout << "Invalid position.\n";
            return;
        }

        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }

    void deleteValue(int x) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == x) {
            deleteBeginning();
            return;
        }

        Node* cur = head;
        while (cur->next && cur->next->data != x)
            cur = cur->next;

        if (!cur->next) {
            cout << "Value not found.\n";
            return;
        }

        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }

    void search(int x) {
        Node* cur = head;
        int pos = 1;

        while (cur) {
            if (cur->data == x) {
                cout << "Found at position " << pos << '\n';
                return;
            }
            cur = cur->next;
            pos++;
        }
        cout << "Value not found.\n";
    }

    void update(int oldValue, int newValue) {
        Node* cur = head;
        while (cur && cur->data != oldValue)
            cur = cur->next;

        if (!cur) {
            cout << "Value not found.\n";
            return;
        }
        cur->data = newValue;
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* cur = head;
        while (cur) {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }

    int count() {
        int c = 0;
        for (Node* cur = head; cur; cur = cur->next)
            c++;
        return c;
    }

    void minMax(bool maximum) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        int ans = head->data;
        for (Node* cur = head->next; cur; cur = cur->next)
            ans = maximum ? max(ans, cur->data)
                          : min(ans, cur->data);

        cout << (maximum ? "Maximum: " : "Minimum: ")
             << ans << '\n';
    }

    void middle() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle: " << slow->data << '\n';
    }

    void reverse() {
        Node *prev = nullptr, *cur = head;

        while (cur) {
            Node* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        head = prev;
    }

    void sortList() {
        for (Node* i = head; i; i = i->next) {
            for (Node* j = head; j && j->next; j = j->next) {
                if (j->data > j->next->data)
                    swap(j->data, j->next->data);
            }
        }
    }

    void removeDuplicates() {
        for (Node* cur = head; cur; cur = cur->next) {
            Node* runner = cur;
            while (runner->next) {
                if (runner->next->data == cur->data) {
                    Node* temp = runner->next;
                    runner->next = temp->next;
                    delete temp;
                } else {
                    runner = runner->next;
                }
            }
        }
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, val2, pos;

    do {
        cout << "\n========================================\n";
        cout << "   SINGLY LINKED LIST OPERATIONS MENU   \n";
        cout << "========================================\n";
        cout << " 1.  Insert at Beginning\n";
        cout << " 2.  Insert at End\n";
        cout << " 3.  Insert at Position\n";
        cout << " 4.  Insert After a Value\n";
        cout << " 5.  Insert Before a Value\n";
        cout << " 6.  Delete from Beginning\n";
        cout << " 7.  Delete from End\n";
        cout << " 8.  Delete at Position\n";
        cout << " 9.  Delete by Value\n";
        cout << " 10. Search a Value\n";
        cout << " 11. Update a Value\n";
        cout << " 12. Display List\n";
        cout << " 13. Count Nodes\n";
        cout << " 14. Find Minimum\n";
        cout << " 15. Find Maximum\n";
        cout << " 16. Find Middle Element\n";
        cout << " 17. Reverse the List\n";
        cout << " 18. Sort the List\n";
        cout << " 19. Remove Duplicates\n";
        cout << " 0.  Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertEnd(val);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                list.insertPosition(val, pos);
                break;
            case 4:
                cout << "Enter target value and new value: ";
                cin >> val >> val2;
                list.insertAfter(val, val2);
                break;
            case 5:
                cout << "Enter target value and new value: ";
                cin >> val >> val2;
                list.insertBefore(val, val2);
                break;
            case 6:
                list.deleteBeginning();
                break;
            case 7:
                list.deleteEnd();
                break;
            case 8:
                cout << "Enter position: ";
                cin >> pos;
                list.deletePosition(pos);
                break;
            case 9:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deleteValue(val);
                break;
            case 10:
                cout << "Enter value to search: ";
                cin >> val;
                list.search(val);
                break;
            case 11:
                cout << "Enter old value and new value: ";
                cin >> val >> val2;
                list.update(val, val2);
                break;
            case 12:
                list.display();
                break;
            case 13:
                cout << "Total nodes: " << list.count() << '\n';
                break;
            case 14:
                list.minMax(false);
                break;
            case 15:
                list.minMax(true);
                break;
            case 16:
                list.middle();
                break;
            case 17:
                list.reverse();
                cout << "List reversed.\n";
                break;
            case 18:
                list.sortList();
                cout << "List sorted.\n";
                break;
            case 19:
                list.removeDuplicates();
                cout << "Duplicates removed.\n";
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}