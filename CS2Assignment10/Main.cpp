#include "Set.h"
#include <iostream>

using namespace std;

int main ()
{
    Set one;
    one.Insert(8);
    one.Insert(82);

    cout<<one.Size();

    system("pause");
    return 0;
}