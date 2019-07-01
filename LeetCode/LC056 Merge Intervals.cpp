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
	Solution()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
	}

	vector<vector<int>> merge(vector<vector<int>>& intervals)
	{
		map<int, int> count;
		for (auto inter : intervals)
		{
			count.insert(pair<int, int>(inter[0], inter[1]));
			count[inter[0]] = max(count[inter[0]], inter[1]);
		}

		vector<vector<int>> ans;
		int flag = 1;

		for (auto it : count)
		{
			flag = 1;
			for (auto &res : ans)
			{
				if (it.first <= res[1])
				{
					res[1] = max(res[1], it.second);
					flag = 0;
					break;
				}
			}

			if (flag)
			{
				ans.push_back(vector<int>{it.first, it.second});
			}
		}

		return ans;
	}
};