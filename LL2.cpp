//insert node at the end

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int new_data) {
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = NULL; // Initialize the "next" pointer to NULL

    if (head == NULL) {
        // If the list is empty, make the new node the head
        head = new_node;
    } else {
        // Otherwise, traverse the list to find the current last node
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Update the "next" pointer of the last node to point to the new node
        current->next = new_node;
    }
}

void display() {
    struct Node* ptr;
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main() {
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(9);
    cout << "The linked list is: ";
    display();
    return 0;
}

