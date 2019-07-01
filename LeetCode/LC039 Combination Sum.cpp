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
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		//sort(candidates.begin(), candidates.end());
		return combinationSumRe(candidates, target);
	}

	vector<vector<int>> combinationSumRe(vector<int>& candidates, int target)
	{
		if (target < 1)
			return vector<vector<int>>(1, vector<int>(0));

		vector<vector<int>> ans;
		if (find(candidates.begin(), candidates.end(), target) != candidates.end())
			ans.push_back(vector<int>{target});

		for (int i = 0; i < candidates.size(); ++i)
		{
			for (vector<int> temp : combinationSumRe(candidates, target - candidates[i]))
			{
				if (temp.empty())
					continue;
				if (temp[0] < candidates[i])
					continue;
				vector<int> sub{ candidates[i] };
				sub.insert(sub.end(), temp.begin(), temp.end());
				ans.push_back(sub);
			}
		}

		return ans;
	}
};