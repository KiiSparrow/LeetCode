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
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));

		dp[0][1] = 1;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (obstacleGrid[i][j])
					dp[i + 1][j + 1] = 0;
				else
					dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
			}
		}

		return dp[m][n];
	}
};