#pragma once
#include <iostream>
template <typename T>
class Node
{
public:
	T data;
	Node* next;
	Node()
	{
		this->next = nullptr;
	}

	Node(T val)
	{
		this->data = val;
		this->next = nullptr;
	}
};

