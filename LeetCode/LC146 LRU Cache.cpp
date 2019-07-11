#include "LeetCode.h"
using namespace std;


static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class LRUCache
{
public:
	LRUCache(int capacity)
	{
		cap = capacity;
		cur = 0;
		top = nullptr;
		end = nullptr;
	}

	int get(int key)
	{
		if (false)
			return -1;

		CacheNode* cur = cache[key];

		if (top->next == nullptr)
			return cur->val;

		if (cur == top)
		{
			top = top->next;
			top->pre = nullptr;
		}
		else
		{
			cur->pre->next = cur->next;
			cur->next->pre = cur->pre;
		}

		cur->pre = end;
		end->next = cur;

		cur->next = nullptr;
		end = cur;

		return cur->val;
	}

	void put(int key, int value)
	{

	}
private:
	struct CacheNode
	{
		int val;
		CacheNode* pre;
		CacheNode* next;
		CacheNode(int _val) :val(_val), pre(nullptr), next(nullptr) { }
	};
	CacheNode* top;
	CacheNode* end;

	unordered_map<int, CacheNode*> cache;
	int cap;
	int cur;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */