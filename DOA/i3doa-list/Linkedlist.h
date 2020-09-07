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
			
			if (temp->next == nullptr)
			{
				temp->next = new Node(data, temp->next, temp);
				tail = temp->next;
			}
			else
			{
				Node* newNode = new Node(data, temp->next, temp);
				temp->next->previous = newNode;
				temp->next = newNode;
			}
			++size;
		}
		else if (index > length()) 
		{
			throw(std::out_of_range("Out Of Range - Insert"));
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
			throw(std::out_of_range("Out Of Range - remove"));
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
		return size;
	}

	T& at(unsigned int index)
	{
		/* YOUR CODE HERE */
		Node* temp = head;
		for (size_t i = 0; i < index; i++)
		{
			if (temp == nullptr)
			{
				throw(std::out_of_range("OOR at"));
			}
			temp = temp->next;
		}
		return temp->data;
	}

	void headInsert(const T& data)
	{
		Node* newNode = new Node(data, nullptr, nullptr);
		newNode->data = data;
		newNode->next = head;
		head = newNode;
		if (newNode->next == nullptr) 
		{
			tail = newNode;
		}
		else
		{
			newNode->next->previous = newNode;
		}

		// Or simply: 
		// head = new Node(data, head);

		++size;
	}

	void headRemove()
	{
		/* YOUR CODE HERE */
		Node* temp = head;
		if (temp != tail)
		{
			head->next->previous = nullptr;
		}
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
	
	void tailInsert(const T& data)
	{
		tail->next = new Node(data, nullptr, tail);
		tail = tail->next;
		++size;
	}

	void tailRemove()
	{
		if (tail == nullptr)
		{
			throw(std::out_of_range("OOR TR"));
		}
		Node* temp = tail;
		if (temp == head) {
			head = nullptr;
			tail = nullptr;
			delete temp;
		}
		else
		{
			temp->previous->next = nullptr;
			tail = temp->previous;
			delete temp;
		}
		--size;
	}

	T& getHead() 
	{
		if (head != nullptr)
		{
			return head->data;
		}
		else
		{
			throw(std::out_of_range("No head!"));
		}
	}

	T& getTail()
	{
		if (tail != nullptr)
		{
			return tail->data;
		}
		else
		{
			throw(std::out_of_range("No Tail!"));
		}
	}
private:

	class Node
	{
	public:
		// Node Constructor
		// If d not given, use template type and create instance of type
		// If n not given, set n = nullptr
		Node(const T& d = T(), Node* n = nullptr, Node* p = nullptr) : data(d), next(n), previous(p) {}

		// Public attributes
		T data;
		Node* next;
		Node* previous;
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
	Node* tail;
	unsigned int size;
};
