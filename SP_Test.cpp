#include "SmartPointer.h"
#include <iostream>
using namespace std;
struct people {
	int height;
	people(int h = 170) : height(h){}
	virtual void output(){cout << "height is " << height << endl;}
};
struct student : public people
{
	int weight;
	student(int h = 170, int w = 173) : people(h), weight(w){}
	virtual void output();
};
void student::output()
{
	cout << "height is " << height << ", weight is " << weight << endl;
}
int main()
{
	SmartPointer<people> TomPtr(new people(173));
	SmartPointer<people> StuPtr(new student);

	TomPtr->output();

	StuPtr->output();

/*
	SmartPointer<int> iPtr(new int);
	*iPtr = 0;
	(*iPtr)++;
	cout << "iPtr value is " << *iPtr << endl;
	cout << "Ref Count is " << iPtr.GetRefCount() << endl;
	SmartPointer<int> iPtr2(iPtr);
	cout << "Ref Count is " << iPtr2.GetRefCount() << endl;
	(*iPtr2)++;
	SmartPointer<int> iPtr3;
	iPtr3 = (iPtr2);
	(*iPtr3)++;
	cout << "iPtr2 value is " << *iPtr2 << endl;
	cout << iPtr.GetRefCount() << endl;
	return 0;
*/
}
