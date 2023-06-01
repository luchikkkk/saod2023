#pragma once
#include <iostream>
#include "Node.h"
#include "ListIterator.h"
template <typename T>
class Listt
{
private:
	size_t count = 0;
	Node<T>* fst;
	Node<T>* lst;
public:
	Listt()
	{
		fst = new Node<T>();
		lst = new Node<T>();
		fst->next = lst;
	}
		
	bool is_empty() {
		return count == 0;
	}

	void PushFront(T val)
	{
		Node<T> *p = new Node<T>(val);
		if (is_empty())
		{
			p->next = lst;
			fst->next = p;
			count++;
			return;
		}
		p->next = fst->next;
		fst->next = p;
		count++;
		return;
	}

	void PushBack(T val) {
		Node<T> *p = new Node<T>(val);
		Node<T>* p2 = fst;
		if (is_empty()) {
			p->next = lst;
			fst->next = p;
			count++;
			return;
		}
		while (p2->next != lst) p2 = p2->next;
		p->next = lst;
		p2->next = p;
		count++;
	}

	void PopFront() {
		if (is_empty()) return;
		Node<T> *p = fst->next;
		fst->next = p->next;
		count--;
		delete p;
	}

	void PopBack() {
		if (is_empty()) return;
		if (count == 1) {
			PopFront();
			return;
		}
		Node<T> *p = fst;
		for (int i = 0; i < count - 1; i++) { p = p->next; }
		Node<T>* p2 = p->next;
		p->next = lst;
		count--;
		delete p2;
	}

	void Insert(int index, T val)
	{
		if (count == 0 || index > count - 1)
		{
			PushBack(val);
		}
		else
		{
			if (index <= 0)
				PushFront(val);
			else
			{
				Node<T>* p = new Node<T>(val);
				Node<T>* p2 = fst->next;
				for (int i = 0; i < index - 1; i++)
				{
					p2 = p2->next;
				}
				p->next = p2->next;
				p2->next = p;
				count++;
			}
			
		}
	}

	void remove_at(int index)
	{
		if (count != 0 && index <= count - 1)
		{
			if (index == 0)
				PopFront();
			else if (index == count - 1)
				PopBack();
			else
			{
				Node<T>* p = fst;
				for (int i = 0; i < index; i++)
				{
					p = p->next;
				}
				Node<T>* p2 = p->next;
				Node<T>* p3 = p2->next;
				p->next = p3;
				count--;
			}
		}
	}

	void Clear()  
	{
		if (count != 0)
		{
			while (count != 0)
			{
				PopBack();
				count--;
			}
		}
	}

	T front() const
	{
		if (count != 0)
		{
			return fst->next->data;
		}
	}

	T back() const
	{
		Node<T>* p = fst;
		while (p->next != lst)
		{
			p = p->next;
		}
		return p->data;
	}

	size_t size() const
	{
		return count;
	}

	T& operator[] (const size_t index)
	{
		Node<T>* p = fst->next;
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}
		return p->data;
	}

	T const& operator[] (const size_t index) const
	{
		Node<T>* p = fst->next;
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}
		return p->data;
	}

	void Show()
	{
		if (count == 0)
		{
			std::cout << "Empty";
		}
		else
		{
			Node<T>* p = fst->next;
			while (p != lst)
			{
				std::cout << p->data;	
				p = p->next;
			}
		}
		std::cout << std::endl;
		
	}

	Iterator<T> begin() const
	{
		return Iterator<T>(fst->next);
	}

	Iterator<T> end() const
	{
		return Iterator<T>(lst);
	}
};

