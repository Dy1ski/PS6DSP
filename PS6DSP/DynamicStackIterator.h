#pragma once
#include "DynamicStack.h"
template<class T>
class DynamicStackIterator
{
private:
	DynamicStack<T> fStack;
public:
	DynamicStackIterator(const DynamicStack<T>& aStack);
	const T& operator*() const; // dereference
	DynamicStackIterator& operator++(); // prefix increment
	DynamicStackIterator operator++(int); // postfix increment
	bool operator==(const DynamicStackIterator& aOtherIter) const;
	bool operator!=(const DynamicStackIterator& aOtherIter) const;
	DynamicStackIterator end() const; // new iterator (after last element)
};
template<class T>
T& DynamicStackIterator<T>::operator*() const
{
	return fStack.top();
}
template<class T>
DynamicStackIterator& DynamicStackIterator<T>::operator++()
{

}
template<class T>
DynamicStackIterator& DynamicStackIterator<T>::operator++(int)
{
	DynamicStackIterator temp = *this;
	++(*this);
	return temp;
}
template<class T>
bool DynamicStackIterator<T>::operator==(const DynamicStackIterator& aOtherIter)const
{
	return fStack.size() == aOtherIter.fStack.size();
}
bool DynamicStackIterator<T>::operator!=(const DynamicStackIterator& aOtherIter)const
{
	return !(*this == aOtherIter);
}
template<class T>
DynamicStackIterator<T>::end() const
{
	DynamicStackIterator temp = *this;
	for (int i = 0; i < fStack.size(); i++)
	{
		++temp;
	}
		return temp;
}