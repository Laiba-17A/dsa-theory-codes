#include <iostream>

class Node {
public:
    int item;
    Node* next_node;

    Node(int val) : item(val), next_node(NULL) {}
};

class SLList {
private:
    Node* head;

public:
    SLList() : head(NULL) {}

    void add(int item) {
        Node* new_node = new Node(item);
        new_node->next_node = head;
        head = new_node;
    }

    int secondLast() {
        if (head == NULL || head->next_node == NULL) {
            std::cerr << "List is empty or has only one element." << std::endl;
            return -1; // Return a sentinel value indicating an error or no valid result
        }

        Node* current = head;
        Node* next_node = head->next_node;

        while (next_node->next_node != NULL) {
            current = next_node;
            next_node = next_node->next_node;
        }

        return current->item;
    }

    // Destructor to free memory
    ~SLList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next_node;
            delete temp;
        }
    }
};

int main() {
    SLList sll;
    sll.add(1);
    sll.add(2);
    sll.add(3);
    sll.add(4);
    sll.add(5);


    int result = sll.secondLast();
    if (result != -1) {
        std::cout << "The second-last element is: " << result << std::endl;
    }

    return 0;
}

