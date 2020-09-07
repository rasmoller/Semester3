#pragma once
#include <stdexcept>
#include"List.h"


template<typename T>
class LinkedList : public List<T>
{
public:
	LinkedList() 
	: head(nullptr), size(0)
	{
	}


	~LinkedList()
	{
		clear();
	}

	void insert(const T& data, unsigned int index)
	{
		/* YOUR CODE HERE */
		if (index <= length() && index > 0) 
		{
			Node* temp = head;
			for (size_t i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}
			temp->next = new Node(data, temp->next);
			++size;
		}
		else if (index > length()) 
		{
			throw(std::out_of_range("Out Of Range"));
		}
		else
		{
			headInsert(data);
		}
	}

	void remove(const unsigned int index)
	{
		/* YOUR CODE HERE */
		Node* temp = head;
		Node* toDel;
		if (index > 0 && index < length()) 
		{
			for (size_t i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}
			toDel = temp->next;
			temp->next = toDel->next;
			delete toDel;
		}
		else if (index >= length()) 
		{
			throw(std::out_of_range("Out Of Range"));
		}
		else
		{
			head = temp->next;
			delete temp;
		}
		--size;
	}

	unsigned int length() const
	{
		int len = 0;
		/* YOUR CODE HERE */
		Node* temp = head;
		while (temp != nullptr) 
		{
			temp = temp->next;
			len++;
		}
		return len;
	}

	T& at(unsigned int index)
	{
		/* YOUR CODE HERE (and remove the line below!) */
		Node* temp = head;
		for (size_t i = 0; i < index; i++)
		{
			temp = temp->next;
			if (temp == nullptr)
			{
				throw(std::out_of_range("OOR"));
			}
		}
		return temp->data; // Just to make the file compile!
	}

	void headInsert(const T& data)
	{
		Node* newNode = new Node(data, nullptr);
		newNode->data = data;
		newNode->next = head;
		head = newNode;

		// Or simply: 
		// head = new Node(data, head);

		++size;
	}

	void headRemove()
	{
		/* YOUR CODE HERE */
		Node* temp = head;
		head = head->next;
		delete temp;
		--size;
	}

	void clear()
	{
		/* YOUR CODE HERE */
		while (head != nullptr)
		{
			headRemove();
		}
	}


private:

	class Node
	{
	public:
		// Node Constructor
		// If d not given, use template type and create instance of type
		// If n not given, set n = nullptr
		Node(const T& d = T(), Node* n = nullptr) : data(d), next(n) {}

		// Public attributes
		T data;
		Node* next;
	};

	// Precondition: index < size
	// Postcondition: Pointer to Node @ index returned 
	Node* get(unsigned int index) const
	{
		Node* cursor = head;

		/* YOUR CODE HERE */

		return cursor;
	}


	Node* head;
	unsigned int size;
};
