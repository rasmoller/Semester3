#pragma once
#include "../i3doa-list/linkedlist.h"
#include "../i3doa-list/vectorlist.h"
#include "Queue.h"

template<typename T>
class ListQueue : public Queue<T>
{
public:
	void push(const T& elm)
	{
		/* YOUR CODE HERE */
		list.headInsert(elm);
	}

	void pop()
	{
		/* YOUR CODE HERE */
		list.tailRemove();
	}

	T front()
	{
		T dataValue = 0;
		/* YOUR CODE HERE */

		dataValue = list.getTail();
		return dataValue;
	}

	bool isEmpty()
	{
		bool isItEmpty = true;
		/* YOUR CODE HERE */
		isItEmpty = !list.length();
		//isItEmpty = (list.length() != 0 ? true : false);
		return isItEmpty;
	}

private:
	//VectorList<T> list;
	LinkedList<T> list;
};