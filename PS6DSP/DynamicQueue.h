#pragma once
#include "List.h"
#include <stdexcept>
template<class T>
class DynamicQueue
{
private:
	List<T> fElements;
public:
	bool isEmpty() const;
	int size() const;
	void enqueue(const T& aElement);
	void dequeue();
	const T& top() const;
};
template<class T>
bool DynamicQueue<T>::isEmpty() const
{
	return fElements.isEmpty();
}
template<class T>
int DynamicQueue<T>::size()const
{
	return fElement.size();
}

template<class T>
void DynamicQueue<T>::enqueue(const T& aElement)
{
	fElement.push_back(aElement);
}
template<class T>
void DynamicQueue<T>::dequeue()
{
	if (isEmpty())
		throw std::overflow_error("Queue Empty!");
	fElements.remove(fElements[0]);
}
template<class T>
void DynamicQueue<T>::top()const
{
	if (isEmpty())
	{
		throw std::underflow_error("Queue Empty!")
	}
	return fElements[0];
}