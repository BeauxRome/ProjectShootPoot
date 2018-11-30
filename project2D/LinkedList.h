#pragma once
#include "LinkListIterator.h"
#include "Node.h"

////THIS IS A PLACEHOLDER FOR POSSIBLE CHANGES TO THE LINKLIST CODE

template <class T>
class LinkedListType
{
protected:
	int count;

	Node<T>*first;

	Node<T>*last;

public:

	const LinkedListType<T>& operator = (const LinkedListType<T>& other)
	{
		return other;
	}

	void initializeList()
	{
		first = nullptr;
		last = nullptr;

		count = 0;
	}

	bool isEmptyList() const
	{
		return (first == nullptr) ? true : false;
	}
	// checks if the list has any items within it

	////////////////PROBABLY WON'T NEED THIS SHIT

	void print() const
	{
		Node<T>*currPlace = new Node<T>;
		currPlace = first;
		while (currPlace != nullptr)
		{
			std::cout << currPlace->mData << std::endl;
			currPlace = currPlace->mNext;
		}
	}

	int length() const
	{
		return count;
	}

	void destroyList()
	{

		while (this->first != nullptr)
		{
			Node<T>*holdUp = this->first;
			this->first = holdUp->mNext;
			delete holdUp;
			count = 0;
		}
	}
	// empties the entire list

	T front() const
	{
		return first->mData;
	}
	// pulls out first value

	T back() const
	{
		return last->mData;
	}
	// pulls out last value

	virtual bool search(const T &)const = 0;

	virtual void insertFirst(const T&) = 0;

	virtual void insertLast(const T&) = 0;

	virtual void deleteNode(const T&) = 0;

	linkedListIterator <T> begin()
	{
		return linkedListIterator <T>(first);
	}
	// pulls out the first item

	linkedListIterator <T> end()
	{
		return linkedListIterator <T>(nullptr);
	}
	// pulls out last item

	LinkedListType()
	{
		initializeList();
	}

	LinkedListType(const LinkedListType<T>& original)
	{
		this->copyList(original);
	}

	~LinkedListType()
	{
		destroyList();
	}

private:

	void copyList(const LinkedListType<T>& original)
	{
		this->destroyList();

		Node<T>* pHolder = original.first;

		while (pHolder != nullptr)
		{
			this->insertLast(pHolder->mData);
			pHolder = pHolder->mNext;
		}
	}
};