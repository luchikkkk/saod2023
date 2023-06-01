#pragma once
#include <iostream>
#include "Node.h"
template <typename T>
class Iterator
{
private:
	Node<T>* current;
public:
	Iterator(Node<T>* node) : current(node){}
	
	T& operator*() const {
		return current->data;
	}
	
	Iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	/*ListIterator& operator+=(ListIterator const& other)
	{
		Node<T>* last = current;
		while (last->next != nullptr) {
			last = last->next;
		}
		last->next = other.current;
		return *this;
	}*/

	bool operator != (const Iterator& other) const
	{
		return current != other.current;
	}
};	

