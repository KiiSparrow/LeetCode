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
	int numTrees(int n)
	{
		vector<int> ans;
		ans.push_back(1);
		ans.push_back(1);
		ans.push_back(2);
		for (int i = 3; i <= n; ++i)
		{
			int t = 0;
			for (int j = 1; j <= i; ++j)
			{
				t += ans[j - 1] * ans[i - j];
			}
			ans.push_back(t);
		}
		return ans[n];
	}
};