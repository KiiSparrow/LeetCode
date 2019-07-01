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
	int maximalSquare(vector<vector<char>>& matrix)
	{
		int m = matrix.size();
		if (!m)
			return 0;
		int n = matrix[0].size();
		if (!n)
			return 0;

		vector<vector<int>> dp(m, vector<int>(n));
		int ans = 0;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '0')
					continue;
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
				ans = max(ans, dp[i][j]);
			}
		}

		return ans * ans;
	}
};