#pragma once

#include "UnorderedLinkList.h"

template <class T>
struct Node
{
	T mData;
	Node<T>* mNext;
};
