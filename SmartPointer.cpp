#include "SmartPointer.h"
//template<class T>
//SmartPointer<T>::SmartPointer(T* P = NULL) : mPointer(P)
//{
//	RefCount = new size_t;
//	*RefCount = 1;
//}
template<class T>
SmartPointer<T>::SmartPointer(const SmartPointer<T> &smPointer)
{
	if (this == &smPointer)
		return;
	DecrementRef();
	mPointer = smPointer.mPointer;
	RefCount = smPointer.RefCount;
	*RefCount++;
}
template<class T>
SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer<T>& smPointer)
{
	if (this == &smPointer)
		return *this;
	DecrementRef();
	mPointer = smPointer.mPointer;
	RefCount = smPointer.RefCount;
	*RefCount++;
	return *this;
}
//template<class T>
//SmartPointer<T>::~SmartPointer()
//{
//	DecrementRef();
//}
template<class T>
T* SmartPointer<T>::operator->()
{
	return mPointer;
}

template<class T>
void SmartPointer<T>::DecrementRef()
{
	*RefCount--;
	if (*RefCount == 0) {
		delete RefCount;
		delete mPointer;
	}
}
