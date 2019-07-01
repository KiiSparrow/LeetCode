#include "LeetCode.h"
using namespace std;


static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		auto b = nums.begin();
		auto e = nums.end();
		int count = nums.size();

		while (b != e)
		{
			if (*b == val)
			{
				swap(*b, *(e - 1));
				--e;
				--count;
			}
			else
			{
				++b;
			}
		}

		return count;
	}
};