#include "SmartPointer.h"
#include <iostream>
using namespace std;

int main()
{
//	int *p = new int;
	SmtPtr<int> iPtr(new int);
//	SmtPtr<int> iPtr();
//	*iPtr = 0;
//	(*iPtr)++;
//	cout << *iPtr << endl;
//	SmtPtr<int> iPtr2(iPtr);

//	cout << *iPtr2 << endl;
	cout << iPtr.GetRefCount() << endl;
	return 0;
}
