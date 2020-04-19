/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* create_node(int data)
    {
        ListNode* new_node = new ListNode();
        new_node -> val = data;
        new_node -> next =NULL;
        return new_node;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *first = l1, *second = l2, *newhead = NULL, *current = newhead, *new_node;
        while(first != NULL && second != NULL)
        {
            if(first -> val <= second -> val)
            {
                new_node = create_node(first -> val);
                if(newhead == NULL)
                {
                    newhead = new_node;
                    current = new_node;
                }
                else
                {
                    current -> next = new_node;
                    current = new_node;
                }
                first = first -> next;
            }
            else
            {
                new_node = create_node(second -> val);
                if(newhead == NULL)
                {
                    newhead = new_node;
                    current = new_node;
                }
                else
                {
                    current -> next = new_node;
                    current = new_node;
                }
                second = second -> next;
            }
        }
        if(first == NULL)
        {
           if(current == NULL)
                return second; 
           else
           {
               current -> next = second;
           }
        }
        else
        {
            if(current == NULL)
                return first; 
           else
           {
               current -> next = first;
           }
        }
        
        return newhead;
        
    }
};