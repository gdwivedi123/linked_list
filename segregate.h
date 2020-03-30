#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

void insert(node*& head, node*& tail, int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node -> data = data;
    new_node -> next = NULL;
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail -> next = new_node;
        tail = new_node;
    }
}

void segregate(node*& head)
{
    node* front = head, *rear = head, *temp;
    int val, curr_val, next_val;
    while(front != NULL)
    {
        if(front -> data % 2 == 0)
        {
            if(rear != front)
            {
                temp = rear;
                val = front -> data;
                curr_val = rear -> data;
                while(temp != front)
                {
                    next_val = temp -> data;
                    temp -> data = curr_val;
                    curr_val = next_val;
                    temp = temp -> next;
                }
                temp -> data = curr_val;
                rear -> data = val;
            }
            rear = rear -> next;
        }
        front = front -> next;
    }
}

void print_list(node*& head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
	//code
	int t, n, i, data, k, j, val;
	cin >> t;
	while(t--)
	{
	    node* head = NULL, *tail = NULL;
	    cin >> n;
	    for(i = 0; i < n; i++)
	    {
	        cin >> data;
	        insert(head, tail, data);
	    }
	    segregate(head);
	    print_list(head);
	}
	return 0;
}