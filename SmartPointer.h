#ifndef SMARTPOINTER_H_
#define SMARTPOINTER_H_
#include <cstddef>
#include <iostream>
template<class T>
class SmartPointer {
public:
	SmartPointer(T *P = NULL): mPointer(P) {
		RefCount = new int;
		*RefCount = 1;
	}
	SmartPointer(const SmartPointer&);
	SmartPointer& operator=(SmartPointer&);
	~SmartPointer(void);
	T* operator->(void) {return mPointer;}
	const T* operator->(void) const {return mPointer;}
	T& operator*(void) {return *mPointer;}
	const T& operator*(void) const {return *mPointer;}
	int GetRefCount() {
		return *RefCount;
	}
private:
	void DecrementRef(void);
	T *mPointer;
	int *RefCount;
};

template<class T>
SmartPointer<T>::SmartPointer(const SmartPointer<T> &smPointer)
{
	mPointer = smPointer.mPointer;
	RefCount = smPointer.RefCount;
	(*RefCount)++;
}
template<class T>
SmartPointer<T>::~SmartPointer()
{
	DecrementRef();
}
template<class T>
SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer<T>& smPointer)
{
	if (this == &smPointer)
		return *this;
	DecrementRef();
	mPointer = smPointer.mPointer;
	RefCount = smPointer.RefCount;
	(*RefCount)++;
	return *this;
}

template<class T>
void SmartPointer<T>::DecrementRef()
{
	(*RefCount)--;
	if (*RefCount == 0) {
		delete RefCount;
		delete mPointer;
	}
}

#endif
