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
private:
	int cap;
	list<pair<int, int>> cache;
	unordered_map<int, decltype(cache)::iterator> kv;

public:
	LRUCache(int capacity)
	{
		cap = capacity;
	}

	int get(int key)
	{
		auto res = kv.find(key);
		if (res == kv.end())
			return -1;

		auto cur = *kv[key];

		cache.erase(kv[key]);
		cache.push_front(cur);
		kv[key] = cache.begin();

		return cur.second;
	}

	void put(int key, int value)
	{
		auto cur = kv.find(key);
		if (cur == kv.end())
		{
			if (cache.size() == cap)
			{
				auto last = cache.back();
				kv.erase(last.first);
				cache.pop_back();
			}
			cache.push_front(make_pair(key, value));
			kv[key] = cache.begin();
		}
		else
		{
			cache.erase(kv[key]);
			cache.push_front(pair<int, int>(key, value));
			kv[key] = cache.begin();
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */