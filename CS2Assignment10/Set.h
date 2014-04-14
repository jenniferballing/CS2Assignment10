#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;

class ListNode
{  
public:	
	ListNode() ;
	ListNode(int i) ;

	int i;
	ListNode *next;
}; 

/*class LList
{  
private:
	ListNode *head;

public:
	LList();

	void Insert (string s);	// insert a new name in order
	void Delete (string s);	// delete a name
	void Display ();		// display list in order
};*/

class Set
{
public:
    Set(void);
    
    //COPY CONSTRUCTOR
    Set (const Set *obj);
    
    //OVERLOADED OPERATORS
    bool operator< (Set &obj);
    Set& operator^ (Set &obj);
    Set& operator+ (Set& obj);
    Set& operator- (Set& obj);
    void operator<< (Set& obj);
    void operator>> (int element);
    void operator= (Set &obj);
    int operator [] (int index);
    
    //CLASS FUNCTIONS
    void Insert (int element);
    void Delete (int element);
    bool Find (int element);
    void Print ();
    int Size ();

    //DESTRUCTOR
    ~Set(void);
};
#endif

