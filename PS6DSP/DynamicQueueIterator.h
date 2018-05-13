#pragma once
#include "DynamicQueue.h"
template<class T>
class DynamicQueueIterator
{
private:
	DynamicQueue<T> fQueue;
public:
	DynamicQueueIterator(const DynamicQueue<T>& aQueue);
	const T& operator*(); // dereference
	DynamicQueueIterator& operator++(); // prefix increment
	DynamicQueueIterator operator++(int); // postfix increment
	bool operator==(const DynamicQueueIterator& aOtherIter) const;
	bool operator!=(const DynamicQueueIterator& aOtherIter) const;
	DynamicQueueIterator end() const; // new iterator (after last element)
};
template<class T>
const T& DynamicQueueIterator<T>::operator*()
{
	return fQueue.top();
}
template<class T>
DynamicQueueIterator& DynamicQueueIterator<T>::operator++()
{
	fQueue.dequeue;
	return *this;
}
template<class T>
DynamicQueueIterator DynamicQueueIterator<T>::operator++(int)
{
	DynamicQueueIterator temp = *this;
	++(*this);
	return temp;
}
bool DynamicQueueIterator<T>::operator==(const DynamicQueueIterator& aOtherIter) const
{
	return fQueue.size() == aOtherIter.fQueue.size();
}
bool DynamicQueueIterator<T>::operator!=(const DynamicQueueIterator& aOtherIter) const
{
	return!(*this == aOtherIter);
}