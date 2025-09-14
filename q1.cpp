#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    // Insertion at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    // Insertion at end
    void insertAtEnd(int val) {
        Node* newNode = new Node{val, NULL};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // Insert before or after a value
    void insertBefore(int target, int val) {
        if (!head) return;
        if (head->data == target) { insertAtBeginning(val); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != target) temp = temp->next;
        if (temp->next) {
            Node* newNode = new Node{val, temp->next};
            temp->next = newNode;
        }
    }
    void insertAfter(int target, int val) {
        Node* temp = head;
        while (temp && temp->data != target) temp = temp->next;
        if (temp) {
            Node* newNode = new Node{val, temp->next};
            temp->next = newNode;
        }
    }

    // Delete from beginning
    void deleteBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from end
    void deleteEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = NULL; return; }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    // Delete specific value
    void deleteValue(int val) {
        if (!head) return;
        if (head->data == val) { deleteBeginning(); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != val) temp = temp->next;
        if (temp->next) {
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
    }

    // Search node
    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next; pos++;
        }
        cout << "Not found\n";
    }

    // Display list
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, val, target;
    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert before a value\n";
        cout << "4. Insert after a value\n5. Delete from beginning\n6. Delete from end\n";
        cout << "7. Delete specific node\n8. Search a node\n9. Display list\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; list.insertAtBeginning(val); break;
        case 2: cout << "Enter value: "; cin >> val; list.insertAtEnd(val); break;
        case 3: cout << "Enter target and new value: "; cin >> target >> val; list.insertBefore(target, val); break;
        case 4: cout << "Enter target and new value: "; cin >> target >> val; list.insertAfter(target, val); break;
        case 5: list.deleteBeginning(); break;
        case 6: list.deleteEnd(); break;
        case 7: cout << "Enter value to delete: "; cin >> val; list.deleteValue(val); break;
        case 8: cout << "Enter value to search: "; cin >> val; list.search(val); break;
        case 9: list.display(); break;
        case 10: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 10);
    return 0;
}
