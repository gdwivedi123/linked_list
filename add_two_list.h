#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
};

Node* newhead = NULL;
int carry = 0;

void addition(Node* l1, Node* l2)
{
    if(l1 != NULL && l2 != NULL)
    {
        addition(l1 -> next, l2 -> next);
        Node* new_node = new Node();
        new_node -> data = (carry + l1 -> data + l2 -> data) % 10;
        carry = (carry + l1 -> data + l2 -> data) / 10;
        new_node -> next = newhead;
        newhead = new_node;
    }
}

void add_node(Node*& head, int data)
{
    Node* new_node = new Node();
    new_node -> data = data;
    new_node -> next = head;
    head = new_node;
}

void print_list(Node* head)
{
    while(head != NULL)
    {
        cout << head -> data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

int main() {
	// your code goes here
	Node* l1 = NULL, *l2 = NULL;
	add_node(l1, 5);
	add_node(l1, 2);
	add_node(l1, 5);
	add_node(l2, 8);
	add_node(l2, 6);
	add_node(l2, 7);
	cout << "First list : ";
	print_list(l1);
	cout << "Second list : ";
	print_list(l2);
	addition(l1, l2);
	if(carry != 0)
	{
	    add_node(newhead, carry);
	}
	cout << " New list after addition is : ";
	print_list(newhead);
	return 0;
}
