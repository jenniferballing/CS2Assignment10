#include "Set.h"
#include <iostream>
#include <string>

using namespace std;

int main ()
{
    cout<<"Test of copy constructor, Insert Function and Print Function: \nset one {2,4,6,8} copied to two, and printed. "<<endl<<endl;
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

    //Test find
    cout<<"Test of Find function: find 2 in set one {2,4,6,8}: \n(should say it is found): "<<endl<<endl;
    one.Find(2);
    cout<<endl;

    //Test delete
    cout<<"Test of Delete function: delete 2 from set one {2,4,6,8}, then print new set one: "<<endl<<endl;
    one.Delete(2);
    one.Print();

    //Test size
    cout<<"Test of Size function: set one {4,6,8}. \n(should be 3): "<<endl<<endl;
    cout<< one.Size()<<endl;

    //Test proper subset
    cout<<"Test of proper subset \'<\': \nset three{1,3}, set four {1, 2, 3, 4, 5}. \n(Returned bool should be 1):"<<endl<<endl;
    Set three, four;
    bool propSubTest;
    three.Insert(1);
    three.Insert(3);

    four.Insert(1);
    four.Insert(2);
    four.Insert(3);
    four.Insert(4);
    four.Insert(5);

    propSubTest = three<four;
    cout<<propSubTest<<endl<<endl;

    //Test intersection
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

    //Test union
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

    //Test difference
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

    //Test brackets
    cout<<"Test of overloaded brackets \'[ ]\': \nset nine{1, 4, 5, 8, 9}, index 2. \n(Returned int should be 5: "<<endl<<endl;
    cout<<nine[2]<<endl<<endl;

    //Test assignment
    cout<<"Test of overloaded \'=\': \nset twelve = set eleven{1, 6, 8}: \nPrint twelve: "<<endl;
    Set eleven, twelve;

    eleven.Insert(1);
    eleven.Insert(6);
    eleven.Insert(8);

    twelve = eleven;
    twelve.Print();

    //Test in/out
    cout<<"Test of overloaded out chevrons\'<<\': \nset nine{1, 4, 5, 8, 9}: "<<endl<<endl;
    cout<<nine<<endl<<endl;

    cout<<"Test of overloaded in chevrons\'>>\': \nset nine{1, 4, 5, 8, 9}: "<<endl<<endl;
    cin>>nine;
    cout<<endl;
    nine.Print();



    
   

    //Test of error check
    cout<<"Test of try-catch block: insert 8 into set one {4,6,8}"<<endl;
    try
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
	    }

    system("pause");
    return 0;
}