#pragma once
#include <map>
#include <vector>
#include <string>

using namespace std;

class Trie
{
	class TrieNode;

	typedef map<char, TrieNode*> TrieMap; // A map of children for each node
	typedef map<char, TrieNode*>::iterator TrieMapIter; // Iter for map

	// Internal TrieNode class - not relevant outside Trie
	class TrieNode
	{
	public:
		TrieNode(char c = '\0', bool cw = false, TrieNode* p = nullptr) :
			val(c), parent(p), completesWord(cw)
		{
			children.clear();
		}

		char val;
		TrieNode* parent;
		bool completesWord;
		TrieMap children;
	};



public:
	Trie()
	{
		root = new TrieNode('\0', true);
	}


	~Trie()
	{

	}


	void insert(string str) const
	{
		TrieNode* temp;
		unsigned int len = 0;
		if (len = findPrefixEnd(str, temp) < str.length())
		{
			for(int i=len-1; i < str.length(); i++)
			{
				if(i == str.length()-1)
				{
					temp->children[str[i]] = new TrieNode(str[i], true, temp);
					return;
				}
				temp->children[str[i]] = new TrieNode(str[i], false, temp);
				temp = temp->children[str[i]];
			}
		}
		temp->completesWord = true;
		return;
	}


	bool search(string str) const
	{
		TrieNode* temp;
		if(findPrefixEnd(str, temp) == str.length())
		{
			return temp->completesWord;
		}
		return false;
	}


	void remove(string str) const
	{
		// YOUR CODE GOES HERE
	}

	void findAllWithPrefix(string prefix, vector<string>& strings) const
	{
		// YOUR CODE GOES HERE
		TrieNode* preEnd;
		if(findPrefixEnd(prefix, preEnd) != prefix.length())
		{
			return;
		}

	}


private:

	// findPrefixEnd: 
	// Sets the parameter end to the last node in the prefix of str and returns the length of the prefix
	unsigned int findPrefixEnd(string str, TrieNode*& end) const
	{
		TrieNode* cur = root;
		TrieMapIter res;
		unsigned int i = 0;

		// Find (part of) key already in trie
		for (; i < str.length(); i++)
		{
			if ((res = cur->children.find(str[i])) != cur->children.end())
			{
				cur = res->second;
			}
			else break;
		}
		
		end = cur;
		
		return i;
	}


	TrieNode* root;
};
