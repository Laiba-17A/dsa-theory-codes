#include <iostream>

// Define the Node structure for a singly linked list
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};

// Function to merge two linked lists
Node* mergeLinkedLists(Node* list1, Node* list2) {
    // Create a dummy node to simplify the code
    Node* temp = new Node(0);
    Node* current = temp;

    // Traverse both linked lists and append nodes to the new list
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // If there are remaining nodes in list1 or list2, append them
    if (list1 != NULL) {
        current->next = list1;
    }
    if (list2 != NULL) {
        current->next = list2;
    }

    // The merged list starts from the node after the temp node
    Node* mergedList = temp->next;
    delete temp; // Free the temp node

    return mergedList;
}

// Function to print a linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create two linked lists
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    // Merge the linked lists
    Node* mergedList = mergeLinkedLists(list1, list2);

    // Print the merged list
    std::cout << "Merged Linked List: ";
    printLinkedList(mergedList);

    return 0;
}

