#include "SmartPointer.h"
#include <iostream>
using namespace std;
struct people {
	int height;
	people(int h = 170) : height(h){}
	void output(){cout << "height is " << height << endl;}
};
int main()
{
	SmtPtr<people> TomPtr(new people(173));

	TomPtr->output();


/*
	SmtPtr<int> iPtr(new int);
	*iPtr = 0;
	(*iPtr)++;
	cout << "iPtr value is " << *iPtr << endl;
	cout << "Ref Count is " << iPtr.GetRefCount() << endl;
	SmtPtr<int> iPtr2(iPtr);
	cout << "Ref Count is " << iPtr2.GetRefCount() << endl;
	(*iPtr2)++;
	SmtPtr<int> iPtr3;
	iPtr3 = (iPtr2);
	(*iPtr3)++;
	cout << "iPtr2 value is " << *iPtr2 << endl;
	cout << iPtr.GetRefCount() << endl;
	return 0;
*/
}
