#include <iostream>
using namespace std;

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
// Function to insert a new node after a specific position
void insertAfterPosition(int position, int newData) {
    if (position < 1) {
        cout << "Invalid position. Position should be a positive integer." << endl;
        return;
    }

    struct Node* newNode = new Node;
    newNode->data = newData;

    if (position == 1 || head == NULL) {
        // If position is 1 or the list is empty, make the new node the head
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* current = head;
        int currentPosition = 1;

        // Traverse the list to find the node at the specified position
        for(currentPosition=1;currentPosition <=position;currentPosition++ )
        if(current->next != NULL) {
            current = current->next;
       
        }

        // Update pointers to insert the new node after the specified position
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display the elements of the linked list
void display() {
    struct Node* current = head;
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}


void insert_beg(int new_data) {
   struct Node* new_node = new Node;
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
}

int main() {
    //struct Node* myList = NULL; // Initialize an empty linked list

    // Insert a node after position 3
    insert_beg(4);
    insert_beg(2);
      cout << "Linked list beforeinsertions:" << endl;
    display();
   // insertAfterPosition(3, 42); // Insert after position 3
    
    //insertAfterPosition(4, 80); 

    cout << "Linked list after insertions:" << endl;
    insertAfterPosition(1, 20); 
    insertAfterPosition(4, 20); 
    display();

    return 0;
}

