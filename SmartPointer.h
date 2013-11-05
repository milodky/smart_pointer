#ifndef SMARTPOINTER_H_
#define SMARTPOINTER_H_
#include <cstddef>
#include <iostream>
template<class T>
class SmtPtr {
public:
	SmtPtr(T *P = NULL): mPointer(P) {
		std::cout << mPointer << std::endl;
		RefCount = new int[1];
		*RefCount = 1;
		std::cout << *RefCount << std::endl;
	}
	SmtPtr(const SmtPtr&);
	SmtPtr& operator=(SmtPtr&);
	~SmtPtr(void);
	T* operator->(void);
	T& operator*(void) {return *mPointer;}
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
	if (this == &smPointer)
		return;
	DecrementRef();
	mPointer = smPointer.mPointer;
	RefCount = smPointer.RefCount;
	*RefCount++;
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
	*RefCount++;
	return *this;
}
template<class T>
T* SmtPtr<T>::operator->()
{
	return mPointer;
}

template<class T>
void SmtPtr<T>::DecrementRef()
{
	*RefCount--;
	if (*RefCount == 0) {
		std::cout << RefCount << std::endl;
		delete RefCount;
		std::cout << "3" << std::endl;
		delete mPointer;
		std::cout << "4" << std::endl;
	}
}

#endif
