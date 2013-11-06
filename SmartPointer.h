#ifndef SMARTPOINTER_H_
#define SMARTPOINTER_H_
#include <cstddef>
#include <iostream>
template<class T>
class SmtPtr {
public:
	SmtPtr(T *P = NULL): mPointer(P) {
		RefCount = new int;
		*RefCount = 1;
	}
	SmtPtr(const SmtPtr&);
	SmtPtr& operator=(SmtPtr&);
	~SmtPtr(void);
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
SmtPtr<T>::SmtPtr(const SmtPtr<T> &smPointer)
{
	mPointer = smPointer.mPointer;
	RefCount = smPointer.RefCount;
	(*RefCount)++;
}
template<class T>
SmtPtr<T>::~SmtPtr()
{
	DecrementRef();
}
template<class T>
SmtPtr<T>& SmtPtr<T>::operator=(SmtPtr<T>& smPointer)
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
void SmtPtr<T>::DecrementRef()
{
	(*RefCount)--;
	if (*RefCount == 0) {
		delete RefCount;
		delete mPointer;
	}
}

#endif
