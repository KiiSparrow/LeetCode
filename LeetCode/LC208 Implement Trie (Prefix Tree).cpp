#include "LeetCode.h"
using namespace std;


static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Trie
{
public:
	/** Initialize your data structure here. */
	Trie()
	{
		root = new treeNode;
	}

	/** Inserts a word into the trie. */
	void insert(string word)
	{
		auto ptr = root;
		for (char ch : word)
		{
			if (ptr->next[ch - 'a'] == nullptr)
			{
				ptr->next[ch - 'a'] = new treeNode(ch);
			}

			ptr = ptr->next[ch - 'a'];
		}
		ptr->isValid = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		auto ptr = root;
		for (char ch : word)
		{
			if (ptr->next[ch - 'a'] == nullptr)
				return false;
			ptr = ptr->next[ch - 'a'];
		}
		return ptr->isValid;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix)
	{
		auto ptr = root;
		for (char ch : prefix)
		{
			if (ptr->next[ch - 'a'] == nullptr)
				return false;
			ptr = ptr->next[ch - 'a'];
		}
		return true;
	}
private:
	struct treeNode
	{
		char ch;
		bool isValid;
		vector<treeNode*> next;

		treeNode() :ch(0), isValid(false), next(vector<treeNode*>(26, nullptr))
		{
		}
		treeNode(char _ch) :ch(_ch), isValid(false), next(vector<treeNode*>(26, nullptr))
		{

		}
	};
	treeNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */