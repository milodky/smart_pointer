#include "SmartPointer.h"
#include <iostream>
using namespace std;

int main()
{
//	int *p = new int;
	SmtPtr<int> iPtr(new int);
//	SmtPtr<int> iPtr();
	*iPtr = 0;
	(*iPtr)++;
	cout << "iPtr value is " << *iPtr << endl;
	cout << "Ref Count is " << iPtr.GetRefCount() << endl;
	SmtPtr<int> iPtr2(iPtr);
	cout << "Ref Count is " << iPtr2.GetRefCount() << endl;
	(*iPtr2)++;
	cout << "iPtr2 value is " << *iPtr2 << endl;
	cout << iPtr.GetRefCount() << endl;
	return 0;
}
