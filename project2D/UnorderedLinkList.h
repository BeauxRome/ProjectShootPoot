#pragma once
#include "LinkedList.h"


////THIS IS A PLACEHOLDER FOR POSSIBLE CHANGES TO THE LINKLIST CODE

template <class T>
class UnorderedLinkedList : public LinkedListType<T>
{
public:
	bool search(const T& searchVal)const
	{
		Node<T>*currPlace = this->first;

		if (currPlace->mData == searchVal)
		{
			return true;
		}
		else if (currPlace->mNext == nullptr)
		{
			return false;
		}
		else
		{
			currPlace = currPlace->mNext;
		}
	}


	void insertFirst(const T& newVal)
	{
		Node<T>*newNode = new Node<T>{ newVal };
		newNode->mNext = this->first;
		this->first = newNode;
	}


	void insertLast(const T&newVal)
	{
		Node<T>*newNode = new Node<T>{ newVal };
		if (this->isEmptyList() == true)
		{
			this->first = newNode;
		}
		this->last = newNode;
		this->last->mNext = nullptr;
	}


	void deleteNode(const T& target)
	{
		Node<T>*currCheck = new Node<T>;
		currCheck = this->first;
		while (currCheck->mNext->mData != target && currCheck->mNext != nullptr)
		{
			currCheck = currCheck->mNext;
		}
		if (currCheck->mNext->mData == target)
		{
			Node<T>* holdUp = new Node<T>;
			holdUp = currCheck->mNext;
			currCheck->mNext = holdUp->mNext;
			delete &holdUp;
		}
	}
};