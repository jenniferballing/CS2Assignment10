#include "Set.h"
#include <iostream>
#include <string>

using namespace std;

int main ()
{
    cout<<"Test of copy constructor, Insert Funtion and Print Function: \nset one {2,4,6,8} copied to two, and printed. "<<endl<<endl;
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

    cout<<"Test of proper subset \'<\': \nset three{1,3}, set four {1, 2, 3, 4, 5}. \n(Returned bool should be 1):"<<endl<<endl;
    Set three, four;
    bool propSubTest;
    three.Insert(1);
    three.Insert(3);

    four.Insert(1);
    four.Insert(2);
    four.Insert(3);
    four.Insert(4);

    propSubTest = three<four;
    cout<<propSubTest<<endl<<endl;

    cout<<"Test of intersection \'^\': \nset five{1, 3, 5, 6}, set six {3, 4, 5}. \n(Returned set should be {3, 5}):"<<endl<<endl;
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

    cout<<"Test of union \'+\': \nset seven{1, 2, 5, 6}, set eight {3, 4, 5, 15}. \n(Returned set should be {1, 2, 3, 4, 5, 6, 15}):"<<endl<<endl;

    Set seven, eight;
    seven.Insert(1);
    seven.Insert(2);
    seven.Insert(5);
    seven.Insert(6);

    eight.Insert(3);
    eight.Insert(4);
    eight.Insert(5);
    eight.Insert(15);

    Set unionTest = seven+eight;
    unionTest.Print();

    cout<<"Test of difference \'-\': \nset nine{1, 4, 5, 8, 9}, set ten {2, 3, 4, 7, 8, 9}. \n(Returned set should be {1, 5}):"<<endl<<endl;

    Set nine, ten;

    nine.Insert(1);
    nine.Insert(4);
    nine.Insert(5);
    nine.Insert(8);
    nine.Insert(9);

    ten.Insert(2);
    ten.Insert(3);
    ten.Insert(4);
    ten.Insert(7);
    ten.Insert(8);
    ten.Insert(9);

    Set diffTest = nine - ten;
    diffTest.Print();

    cout<<"Test of overloaded brackets \'[ ]\': \nset nine{1, 4, 5, 8, 9}, index 2. \n(Returned int should be 5: "<<endl<<endl;
    cout<<nine[2]<<endl<<endl;

    cout<<"Test of overloaded out chevrons\'<<\': \nset nine{1, 4, 5, 8, 9}: "<<endl<<endl;
    cout<<nine<<endl<<endl;

    cout<<"Test of overloaded in chevrons\'>>\': \nset nine{1, 4, 5, 8, 9}: "<<endl<<endl;
    Set twenty;
    cin>>twenty;
    cin>>nine;
    cout<<endl;
    nine.Print();
    nine.Print();
    
    
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