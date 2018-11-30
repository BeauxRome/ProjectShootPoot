#pragma once
#include "Bullet.h"
#include "Node.h"

////THIS IS A PLACEHOLDER FOR POSSIBLE CHANGES TO THE LINKLIST CODE

template <class T>
class linkedListIterator
{
private:
	Node<T>*current;
public:
	linkedListIterator()
	{
		current = nullptr;
	}
	linkedListIterator(Node<T>*node)
	{
		current = node;
	}
	T operator*()
	{
		return current->mData;
	}
	linkedListIterator<T> operator ++()
	{
		current = current->mNext;
		return *this;
	}
	bool operator == (const linkedListIterator<T>& rhs) const
	{
		return this->current->mData == rhs.current->mData;
	}
	bool operator != (const linkedListIterator<T>& rhs) const
	{
		return this->current->mData != rhs.current->mData;
	}
};