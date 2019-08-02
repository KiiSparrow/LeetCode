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
	int minDistance(string word1, string word2)
	{
		if (word1.empty())
			return word2.size();
		if (word2.empty())
			return word1.size();

		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
		for (int i = 0; i < word1.size() + 1; ++i)
			dp[i][0] = i;
		for (int j = 0; j < word2.size() + 1; ++j)
			dp[0][j] = j;

		for (int i = 1; i < word1.size() + 1; ++i)
		{
			for (int j = 1; j < word2.size() + 1; ++j)
			{
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = 1 + min3(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}

		return dp.back().back();
	}
private:
	int min3(const int& a, const int& b, const int& c)
	{
		return a < b ? (a < c ? a : c) : (b < c ? b : c);
	}
};