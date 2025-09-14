#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle Node = " << slow->data << endl;
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}};
    findMiddle(head);
    return 0;
}
