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

    void insert(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    int countAndDelete(int key) {
        int count = 0;
        while (head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                count++;
            } else {
                curr = curr->next;
            }
        }
        return count;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int arr[] = {1,2,1,2,1,3,1};
    for (int i = 6; i >= 0; i--) list.insert(arr[i]); 

    cout << "Original List: "; list.display();
    int key = 1;
    int cnt = list.countAndDelete(key);
    cout << "Occurrences of " << key << " = " << cnt << endl;
    cout << "Modified List: "; list.display();
    return 0;
}
