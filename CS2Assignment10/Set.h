#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;

class ListNode
{  
public:
    int element;
	ListNode *next;

	ListNode();
	ListNode(int element);	
}; 
class DuplicateException 
{	
	public:
	int duplicateIndex;
	string message; 

	DuplicateException(int i, string m)
	{
		duplicateIndex = i ;
		message = m ;
	}
}; 

class Set
{
private:
    ListNode *head;
public:

    Set();
    
    //COPY CONSTRUCTOR
    Set (const Set *obj);
    
    //OVERLOADED OPERATORS
    bool operator< (Set &obj);
    Set& operator^ (Set &obj);
    Set& operator+ (Set& obj);
    Set& operator- (Set& obj);
    void operator= (Set &obj);
    int operator [] (int index);
    
    //CLASS FUNCTIONS
    void Insert (int element);
    void Delete (int e);
    bool Find (int e);
    void Print ();
    int Size ();

    //DESTRUCTOR
    ~Set(void);

    friend void operator>> (istream &is, Set& obj);

    void Output(ostream & out) ; 
};

void operator >>  (istream &is, Set& obj);
ostream& operator<< (ostream &os, Set& obj);
#endif

