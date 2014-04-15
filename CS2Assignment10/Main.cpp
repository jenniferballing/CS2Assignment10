#include "Set.h"
#include <iostream>
#include <string>

using namespace std;

int main ()
{
    Set one;
    Set two;
    Set three;
    Set four;
    Set five;
    Set six;
    Set seven;

    one.Insert(1);
    one.Insert(2);
    one.Insert(3);
    one.Insert(4);

    two.Insert(1);
    two.Insert(2);
    
    three.Insert(1);
    three.Insert(2);
    three.Insert(3);
    three.Insert(6);

    Set newSet = three^two;
    newSet.Print();

    four.Insert(1);
    four.Insert(2);
    four.Insert(3);
    four.Insert(4);
    four.Insert(5);

    five.Insert(1);
    five.Insert(2);
    five.Insert(3);

    six.Insert(1);
    six.Insert(16);
    six.Insert(3);
    six.Insert(4);

    
    Set set = six+four;
    set.Print();

    cout<<(two<one)<<endl;
    cout<<(three<one)<<endl;
    cout<<(four<one)<<endl;
    cout<<(five<one)<<endl;
    cout<<(six<one)<<endl;


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