#include "Set.h"


ListNode::ListNode()
{
    element = 0;
    next = NULL;
}
ListNode::ListNode(int e)
{
    element = e;
    next=NULL;
}

Set::Set()
{
    head = new ListNode (0);
    head->next = new ListNode (100);
}

Set::Set (const Set *obj)
{
    ListNode *newNode = new ListNode();

    ListNode *prev = head;
    ListNode *current = head->next;
    
    while (newNode != NULL)
    {
        newNode = prev;
        newNode->next = current; 

        prev = current;
        current = current->next;
    }   
    /*obj->head = this->head;
    while( this->next != NULL)
    {
        obj->next = this
    }*/
}
bool Set::operator< (Set &obj)
{
    //this is the subset, obj is the large set
    //if(
    return true;
}


void Set::Insert (int element)
{
    ListNode *newNode = new ListNode(element);

    ListNode *prev = head;
    ListNode *curr = head->next;

    while (element > curr->element)
    {
        prev = curr;
        curr = curr->next;   
    }
    prev->next = newNode;
    newNode->next = curr;
    prev = head;
    curr = head->next;
}
int Set::Size ()
{
    int count =1;
    
    ListNode *prev = head;
    //ListNode *curr = head->next;

    while(prev->element<100)
    {
        count++;
        prev = prev->next;
    }
    return count;
}


Set::~Set(void)
{
}
