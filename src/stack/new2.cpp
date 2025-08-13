#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    char* data;
    Node* next;
    
    Node(const char* val) {
        data = new char[strlen(val) + 1];
        strcpy(data, val);
        next = nullptr;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void sortList(Node*& head) {
    for (Node* i = head; i != nullptr; i = i->next) 
    {
        for (Node* j = i->next; j != nullptr; j = j->next) 
        {
            if (strcmp(i->data, j->data) < 0) 
            {
                char* temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void append(Node*& head, const char* val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;  
    } else {
        Node* temp = head;
        while (temp->next != nullptr) 
        {  
            temp = temp->next;
        }
        temp->next = newNode;  
    }
}
int main() {
    Node* head = nullptr;
    append(head, "AB");
    append(head, "CD");
    append(head, "AA");

    cout << "Before sorting: ";
    printList(head);

    sortList(head);

    cout << "After sorting: ";
    printList(head);
    return 0;
}