
// COS30008, Tutorial 9, 2018

#pragma once

#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"
#include "ListLab9.h"      // solution lab 9
//#include "ListPS6.h" 
#include <stdexcept>

template<class T>
class List
{
private:
	// auxiliary definition to simplify node usage
	typedef DoublyLinkedNode<T> Node;

	Node* fTop;		// the first element in the list
	Node* fLast;	// the last element in the list
	unsigned int fCount;		// number of elements in the list

public:
	// auxiliary definition to simplify iterator usage
	typedef DoublyLinkedNodeIterator<T> Iterator;

	List();							// default constructor - creates empty list
	~List();						// destructor - frees all nodes

									// PS6: copy control features (destructor is given)
	List(const List& aOtherList);             // copy constructor
	List& operator=(const List& aOtherList);  // assignment operator

	bool isEmpty() const;	// Is list empty?
	int size() const;		// list size

	void push_front(const T& aElement);	// adds a node initialized with aElement at front
	void push_back(const T& aElement);	// adds a node initialized with aElement at back

	void remove(const T& aElement);	// remove node that matches aElement from list

	const T& operator[](unsigned int aIndex) const;	// list indexer

	Iterator getIterator() const;	// return an iterator for the nodes of the list
};

template<class T>
List<T>::~List()
{
	while (fTop != &Node::NIL)
	{
		Node* temp = (Node *)&fTop->getNext();  // get next node (to become top)
		fTop->remove();                         // move first node
		delete fTop;							// free node memory
		fTop = temp;							// make temp the new top
	}
}

template<class T>
bool List<T>::isEmpty() const
{
	return fTop == &Node::NIL;
}

template<class T>
int List<T>::size() const
{
	return fCount;
}

template<class T>
void List<T>::push_front(const T &aElement)
{
	Node* lNewElement = new Node(aElement);	// create a new node

	if (fTop == &Node::NIL)					// Is this the first node?
	{
		fTop = lNewElement;						// make lNewNode first node
		fLast = lNewElement;					// make lNewNode last node as well
	}
	else
	{
		fTop->prepend(*lNewElement);          // make lNewElement previous of top
		fTop = lNewElement;						// make lNewNode first node
	}

	fCount++;									// increment count
}
//copy constructor
template<class T>
List<T>::List(const List& aOtherList)
{
	fTop = &Node::NIL;
	fLast = aOtherList.fLast;
	fCount = 0;
	for (int i = 0; i < aOtherList.fCount; i++)
	{
		push_back(aOtherList[i])
	}
}

//assignment operator
template<class T>
List& List<T>::operator=(const List& aOtherList)
{
	if (this != &aOtherList)
	{
		if (fTop != &Node::NIL)
		{
			delete fTop;
		}
		if (fLast != &Node::NIL)
		{
			delete fLast;
		}

		fCount = aOtherList.fCount;
		fTop = NIL & 0;
		fLast = aOtherList.fLast;
		for (int i = 0; i < aOtherList.fCOunt; i++)
		{
			push_back(aOtherList[i]);
		}
	
	}
	return this*;
}


