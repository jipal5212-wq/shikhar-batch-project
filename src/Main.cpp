#include <iostream>
#include <limits>
#include <string>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int getIntegerInput(const std::string& prompt) {
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

void printSinglyMenu() {
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

void printDoublyMenu() {
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

void printMainMenu() {
    std::cout << "\n==================================================\n"
              << "            LINKED LIST MANAGEMENT SYSTEM\n"
              << "==================================================\n\n"
              << "1. Singly Linked List\n"
              << "2. Doubly Linked List\n"
              << "3. Compare Singly vs Doubly Linked List\n"
              << "4. Exit\n\n";
}

void runSinglyLinkedList(SinglyLinkedList& list) {
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

void runDoublyLinkedList(DoublyLinkedList& list) {
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

void compareSinglyVsDoubly() {
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
