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
}
bool Set::operator< (Set &obj)
{
    //this is the subset, obj is the large set
    int counter = 1;
    ListNode *thisPrev = head;
    ListNode *objPrev = obj.head;
    int objSize = obj.Size();
    int thisSize = this->Size();
    if(objSize==thisSize) return false;
    for(int i =0; i<objSize-1; i++)
    {
        if(thisPrev->element == objPrev->element)
        {
            counter+=1;
            thisPrev=thisPrev->next;
        }
        objPrev = objPrev->next;
    }
    if(counter==this->Size()) return true;
    return false;
}
Set& Set::operator^ (Set &obj)
{
    Set newSet;
    ListNode *newNode = new ListNode();
   
    ListNode *thisPrev = head;
    ListNode *objPrev = obj.head;

    ListNode * newPrev = new ListNode();
    ListNode * newCurr = new ListNode();
    
    int objSize = obj.Size();
    int thisSize = this->Size();
    for(int i =0; i<objSize-1; i++)
    {
        if(thisPrev->element == objPrev->element)
        {
            newNode=objPrev; 

            newSet.Insert(newNode->element);
            
            thisPrev=thisPrev->next;
        }
        objPrev = objPrev->next;
    }
    Set &temp = newSet;
    return temp;
}
Set& Set::operator+ (Set &obj)
{
    Set newSet;
    //Set objTemp = obj;
    //Set thisTemp = this;

    ListNode *objPrev = obj.head;
    ListNode *thisPrev = this->head;

    //Put all of obj into set
    while(objPrev->element !=100)
    {
        newSet.Insert(objPrev->element);
        objPrev=objPrev->next;
    }

    objPrev = obj.head;
    int count =0;
    //Cycle through this
    while(thisPrev->element != 100)
    {
        //Cycle through obj
        while(objPrev->element != 100)
        {
            if(thisPrev->element == objPrev->element) count+=1;
            
            //Increase obj
            objPrev = objPrev->next;
        }

        //If there were no matches, add
        if(count == 0)
        {
            newSet.Insert(thisPrev->element);
        }
        
        //Increase this
        objPrev = obj.head;
        thisPrev= thisPrev->next;
        count=0;
    }

    Set &temp = newSet;
    return temp;
}
void Set::Insert (int element)
{
    if(element >100 || element <0)
    {
        cout<<"Please insert an integer that is between 0 and 100."<<endl;
        cout<<"The integer: "<<element<<" does not fall between 0 and 100."<<endl;
        return;
    }
    ListNode *newNode = new ListNode(element);

    ListNode *prev = head;
    ListNode *curr = head->next;

    //CHECKING FOR DUPLICATES
    while(prev->element != 100)
    {
        prev = prev->next;
        if(element == prev->element)
        {
            throw DuplicateException(element, "Duplicate Entry");
        }
    }
    prev = head; 
    
    //LOCATE POSITION OF NEW ELEMENT
    while (element > curr->element)
    {
        prev = curr;
        curr = curr->next;  
    }
    
    prev->next = newNode;
    newNode->next = curr;
}
void Set::Delete (int e)
{
    ListNode *prev = head;
    ListNode *curr = head->next;

    while(curr->element !=100)
    {
        if (curr->element == e)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr= curr->next;
    }
}
bool Set::Find (int e)
{
    ListNode *prev = head;

    while(prev->element != 100)
    {
        if(prev->element == e)
        {
            cout<<"The item is found."<<endl;
            return true;
        }
        prev = prev->next;
    }
    cout<<"Not found."<<endl;
    return false;
}
void Set::Print ()
{
    ListNode *prev = head;
    while(prev->element != 100)
    {
        cout<<prev->element<<endl;
        prev=prev->next;
    } cout<< 100<<endl;
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
