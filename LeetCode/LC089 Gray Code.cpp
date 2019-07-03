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
	vector<int> grayCode(int n)
	{
		int m = 1 << n;
		vector<int> ans;

		for (int i = 0; i < m; i++)
			ans.push_back(i ^ i >> 1);

		return ans;
	}
};