#include <iostream>
using namespace std;

// Define a Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail=NULL;

void insert_end(int d)
{
	struct Node *new_node= new Node;
	struct Node *ptr;
	ptr=head;
	new_node->data=d; 
	if(head==NULL)
	{
	new_node->next=head;
	head=new_node;
	tail=new_node;
	cout<<"node added"<<endl;	
	cout<<head->data<<endl;
		
	}
	else
	{
		struct Node *ptr;
		while(ptr->next!=head)
		{
			ptr=ptr->next;
			cout<<"new"<<endl;
		}
		tail->next= new_node; 
		new_node->next= head; 
		tail=new_node;
		cout<<"node added"<<endl;
		//cout<<tail<<endl;

	}
	
}
void display() {
    struct Node* temp;
    temp = head;
    cout<<temp->data;
    temp=temp->next;
    while (temp!= head) {
        cout << temp->data << " ";
        temp= temp->next;
    }
}

int main()
{
	insert_end(6);
	insert_end(5);
	insert_end(7);
	insert_end(10);
	
	cout << "The linked list is: ";
    display();
	
}
