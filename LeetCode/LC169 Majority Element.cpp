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
	int majorityElement(vector<int>& nums)
	{
		int ans = 0;
		int max = 0;
		unordered_map<int, int> nmap;

		for (auto n : nums)
		{
			nmap[n] += 1;
			if (nmap[n] > max)
			{
				max = nmap[n];
				ans = n;
			}
		}

		return ans;
	}
};