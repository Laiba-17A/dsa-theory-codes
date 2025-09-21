#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node * next;
		
		Node(): data(0),next(NULL)
		{
			
		}
		
		Node(int d)
		{
			data=d;
			next=NULL;
		}
};

class SinglyLL
{
	public:
		Node * Head;
		
		SinglyLL(int d)
		{
			Head = new Node(d);
		}
		
		void insertatend(int d)
		{
			Node * current = Head;
			Node * newnode = new Node(d);
			
			while (current->next!=NULL)
			{
				current = current->next;
			}
			current->next=newnode;
		}
		
		void print()
		{
			Node *print = Head;
			
			while (print!=NULL)
			{
				cout<<print->data;
				print=print->next;
			}
		}
		
		void reversingnode()
		{
			Node* current=Head;
			Node* prev=NULL;
			Node* nextnode=NULL;
			
			while(current!=NULL)
			{
				nextnode = current -> next; 
				current -> next = prev;
				prev = current;
				current = nextnode;
			}
			Head=prev;

		}
		
};

int main()
{
	SinglyLL s(4);
	s.insertatend(1);
	s.insertatend(5);
	s.insertatend(7);
	s.insertatend(2);
	s.print();
	cout<<endl;
	s.reversingnode();
	s.print();
}
