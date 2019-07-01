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
	int minimumTotal(vector<vector<int>>& triangle)
	{
		if (triangle.empty())
			return 0;

		vector<int> dp(triangle.size());
		dp[0] = triangle[0][0];
		for (int i = 1; i < triangle.size(); i++)
		{
			for (int j = i; j >= 0; j--)
			{
				if (j == i)
					dp[j] = dp[j - 1] + triangle[i][j];
				else if (j == 0)
					dp[j] += triangle[i][j];
				else
					dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
			}
		}

		return *min_element(dp.begin(), dp.end());
	}

	/*int minimumTotal(vector<vector<int>>& triangle)
	{
		if (triangle.size() == 0)
			return 0;

		for (int i = triangle.size() - 2; i >= 0; i--)
		{
			for (int j = 0; j < triangle[i].size(); j++)
			{
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return triangle[0][0];
	}*/
};