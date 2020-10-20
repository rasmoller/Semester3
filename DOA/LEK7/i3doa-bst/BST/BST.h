#pragma once

template<typename T>
class BST
{
public:
	template<typename T>
	class Node
	{
	public:
		Node(const T& _data = T(), Node<T>* l = nullptr, Node<T>* r = nullptr, Node<T>* p = nullptr)
			: data(_data), left(l), right(r), parent(p)
		{}

		T data;
		Node<T>* parent;
		Node<T>* left;
		Node<T>* right;
	};
private:
	Node<T>* root;

	// Recursive function to find Node with data = data
	Node<T>* findNode(Node<T>* itsRoot, const T& data)
	{
		if (itsRoot == nullptr)
		{
			return nullptr;
		}
		if (itsRoot->data == data)
		{
			return itsRoot;
		}
		else if (itsRoot->data > data)
		{
			return findNode(itsRoot->left, data);
		}
		else if (itsRoot->data < data)
		{
			return findNode(itsRoot->right, data);
		}
	}

	// Recursive function to insert node with data
	Node<T>* insertNode(Node<T>* itsRoot, const T& data)
	{
		// Hvad hvis root er nullptr ???
		if (itsRoot == nullptr)
		{
			root = new Node<T>(data, nullptr, nullptr, nullptr);
			return itsRoot;
		}
		if(itsRoot->data >= data)
		{
			if (itsRoot->left == nullptr)
			{
				itsRoot->left = new Node<T>(data, nullptr, nullptr, itsRoot);
				return itsRoot->left;
			} 
			else
			{
				return insertNode(itsRoot->left,data);
			}
		}
		else if (itsRoot->data < data)
		{
			if (itsRoot->right == nullptr)
			{
				itsRoot->right = new Node<T>(data, nullptr, nullptr, itsRoot);
				return itsRoot->right;
			} 
			else
			{
				return insertNode(itsRoot->right, data);
			}
		}
		
		return nullptr;
	}

	// Recursive function to find right-most node
	Node<T>* findRightmostChild(Node<T>* itsRoot) {
		if(itsRoot == nullptr)
		{
			return nullptr;
		}
		if(itsRoot->right != nullptr)
		{
			findRightmostChild(itsRoot->right);
		}
		return itsRoot;
	}

	// Recursive function to find left-most node
	Node<T>* findLeftmostChild(Node<T>* itsRoot) {
		if(itsRoot == nullptr)
		{
			return nullptr;
		}
		if(itsRoot->left != nullptr)
		{
			findRightmostChild(itsRoot->left);
		}
		return itsRoot;
	}


public:

	BST(Node<T>* root = nullptr) : root(root)
	{
	}

	bool search(const T& data)
	{
		// Recursive function called with root as seed
		return findNode(root, data) != nullptr;
	}

	void insert(const T& data)
	{
		// Recursive function called with root as seed
		insertNode(root, data);
	}

	void remove(const T& data)
	{
		Node<T> * searchNode = findNode(root, data);
		if( searchNode != nullptr)
		{
			Node<T> * nearestChild = findRightmostChild(searchNode->left);
			if(nearestChild == nullptr)
			{
				nearestChild = findLeftmostChild(searchNode->right);
				if(nearestChild == nullptr)
				{
					if(searchNode->parent == nullptr)
					{
						root = nullptr;
					}
					else
					{
						if(searchNode->parent->left->data == searchNode->data)
						{
							searchNode->parent->left = nullptr;
						}
						else
						{
							searchNode->parent->right = nullptr;
						}
					}
				}
			}
			if(nearestChild != nullptr)
			{
				searchNode->data = nearestChild->data;
				if (nearestChild->parent == searchNode)
				{
					searchNode->left = nearestChild->left;
				}
				else
				{
					nearestChild->parent->right = nearestChild->left;
				}
			}			
		}
	}

};