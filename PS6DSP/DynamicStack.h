#pragma once
#include "List.h"
#include <stdexcept>
template<class T>
class DynamicStack
{
private:
	List<T> fElements;
public:
	bool isEmpty() const;
	int size() const;
	void push(const T& aItem);
	void pop();
	const T& top() const;
};

template<class T>
bool DynamicStack<T>::isEmpty()const
{
	fElements.isEmpty();
}
template<class T>
int DynamicStack<T>::size() const
{
	fElements.size();
}
template<class T>
void DynamicStack<T>::push(const T& aItem)
{
	fElements.push_front(aItem);
}
template<class T>
void DynamicStack<T>::pop()
{
	fElements.remove(fElements[0]);
}
template<class T>
const T& DynamicStack<T>::top() const
{
	return(fElements[0]);
}