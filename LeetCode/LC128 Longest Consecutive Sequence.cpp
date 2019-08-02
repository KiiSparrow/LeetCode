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
	int longestConsecutive(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		unordered_set<int> st(nums.begin(), nums.end());

		int maxLen = 0;
		for (auto p : st)
		{
			if (st.find(p - 1) != st.end())
				continue;

			int tmp = 0;
			while (st.find(p) != st.end())
			{
				++tmp;
				++p;
			}

			maxLen = max(maxLen, tmp);
		}

		return maxLen;
	}
};