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
    ListNode *thisPrev = this->head;
    ListNode *objPrev = obj.head;

     //Cycle through this
    while(thisPrev->element != 100)
    {
        //Cycle through obj
        while(objPrev->element != 100)
        {
            //If element exists in both sets add to temp set
            if(thisPrev->element == objPrev->element) 
            {
                newSet.Insert(thisPrev->element);
            }
            
            //Increase obj
            objPrev = objPrev->next;
        }        
        //Increase this
        objPrev = obj.head;
        thisPrev= thisPrev->next;
    }
    Set &temp = newSet;
    return temp;
}
Set& Set::operator+ (Set &obj)
{
    Set newSet;
    
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
Set& Set::operator- (Set &obj)
{
    Set newSet;

    ListNode *objPrev = obj.head;
    ListNode *thisPrev = this->head;

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
        //Increase this, Set obj back to head, reset count
        objPrev = obj.head;
        thisPrev= thisPrev->next;
        count=0;
    }
    Set &temp = newSet;
    return temp;
}
void Set::Output(ostream & out)
{
    ListNode *thisNode = head;
    thisNode = thisNode->next;
    while(thisNode->element != 100)
    {
        out<<thisNode->element<< endl;
        thisNode = thisNode->next;
    }
}
ostream& operator<< (ostream & os, Set& obj)
{
    obj.Output(os);
    return os;
}
void operator>> (istream & is, Set &obj)
{
    //ListNode *newNode=obj.head;
    int num;
    cout<<"Input the new integer for the linked list: "<<endl;
    is>>num;//newNode->element;
    obj.Insert(num);//newNode->element);
}
/*void Set::operator= (Set &obj)
{

}*/
int Set::operator [] (int index)
{
    int listArr[50];
    int i=0;
    ListNode *thisPrev = this->head;
    thisPrev= thisPrev->next;
    while(thisPrev->element !=100)
    {
        listArr[i] = thisPrev->element;
        thisPrev = thisPrev->next;
        i++;
    }
    return listArr[index];
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
        if(prev->element != 0 && prev->element != 100)
        {
            cout<<prev->element<<endl;
        }     
        prev=prev->next;
    } cout<<endl;
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
