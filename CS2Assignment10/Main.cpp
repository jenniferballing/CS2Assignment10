#include "Set.h"
#include <iostream>
#include <string>

using namespace std;

int main ()
{
    cout<<"Test of copy constructor, Insert Funtion and Print Function: \nset one {2,4,6,8} copied to two, and printed. "<<endl;
    Set cpyConTest, one;
    //Test of Insert
    one.Insert(2);
    one.Insert(4);
    one.Insert(6);
    one.Insert(8);
    //Test of Copy Constructor
    Set two(one);
    //Test of print
    two.Print();

    cout<<"Test of proper subset \'<\': set three{1,3}, set four {1, 2, 3, 4, 5}. (Returned bool should be 1):"<<endl;
    Set three, four;
    bool propSubTest;
    three.Insert(1);
    three.Insert(3);

    four.Insert(1);
    four.Insert(2);
    four.Insert(3);
    four.Insert(4);

    propSubTest = three<four;
    cout<<endl<<propSubTest<<endl;

    cout<<"Test of intersection \'^\': set five{1, 3, 5, 6}, set six {3, 4, 5}. (Returned set should be {3, 5}):"<<endl;
    Set five, six;
    
    five.Insert(1);
    five.Insert(3);
    five.Insert(5);
    five.Insert(6);

    six.Insert(3);
    six.Insert(4);
    six.Insert(5);

    Set interTest = five ^ six;
    interTest.Print();
    
    
    
    /*
    Set nSet = five-six;
    nSet.Print();

    cout<<(two<one)<<endl;
    cout<<(three<one)<<endl;
    cout<<(four<one)<<endl;
    cout<<(five<one)<<endl;
    cout<<(six<one)<<endl;*/


    /*one.Insert(105);
    one.Insert(8);
    one.Insert(56);
  
    cout<<one.Size()<<endl;

    one.Insert(33);

    cout<<one.Size()<<endl;

    one.Delete(33);

    cout<<one.Size()<<endl;

    cout<<one.Find(8)<<endl;

    one.Insert(99);
    one.Print();
    Set two(one);
    two.Print();*/


    /*try
    {
        while (1)
        {
            one.Insert(8);
	    }
    }catch (DuplicateException ex)
	    {	
		    cout << "Error Report --------------------------------------" << endl ;
            cout << "Attempt to add integer "<< ex.duplicateIndex <<" has failed."<<endl;
		    cout << "exception nature: " << ex.message << endl ;
	    }*/

    system("pause");
    return 0;
}