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
	string longestPalindrome(string s)
	{
		int maxLen = 0, maxStart = 0;
		for (int i = 0; i < s.size();)
		{
			int start = i, end = i;
			while (end + 1 < s.size() && s[end] == s[end + 1])
				end++;
			i = end + 1;
			while (start - 1 >= 0 && end + 1 < s.size() && s[start - 1] == s[end + 1])
			{
				start--;
				end++;
			}
			if (end - start + 1 > maxLen)
			{
				maxLen = end - start + 1;
				maxStart = start;
			}
		}

		return s.substr(maxStart, maxLen);
	}

	/*
	string longestPalindrome_dp(string s)//dp
	{
		int len = s.size();
		if (len < 2) return s;
		vector<vector<int>> dp(len, vector<int>(len, 0));

		int start = 0, max = 1;
		for (int j = 0; j < len; ++j)
		{
			dp[j][j] = 1;
			for (int i = j - 1; i >= 0; --i)
			{
				if (s[i] == s[j])
				{
					if (j - i == 1)
					{
						dp[i][j] = 2;
					}
					else
					{
						if (dp[i + 1][j - 1])
							dp[i][j] = dp[i + 1][j - 1] + 2;
						else
							dp[i][j] = 0;
					}
				}
				else
				{
					dp[i][j] = 0;
				}

				if (dp[i][j] > max)
				{
					max = dp[i][j];
					start = i;
				}
			}
		}

		return s.substr(start, max);
	}
	*/

	/*
	string longestPalindrome_manacher(string s)
	{
		int l = s.size();
		if (l < 2) return s;

		int nl = 2 * l + 1;
		string str(nl, '#');
		for (int i = 0; i < l; ++i)
		{
			str[2 * i + 1] = s[i];
		}

		vector<int> RL(nl, 0);
		int maxRight = 0;
		int pos = 0;
		int maxRadius = 0;
		int maxIter = 0;
		for (int i = 0; i < nl; ++i)
		{
			if (i < maxRight)
			{
				RL[i] = countStr(str, i, min(RL[2 * pos - i], maxRight - i));
			}
			else
			{
				RL[i] = countStr(str, i);
			}

			if (i + RL[i] > maxRight)
			{
				maxRight = i + RL[i];
				pos = i;
			}

			if (RL[i] > maxRadius)
			{
				maxRadius = RL[i];
				maxIter = i;
			}
		}

		if (maxRadius < 2)
			return string(s, 0, 1);

		string ans;
		for (int i = maxIter - maxRadius; i <= maxIter + maxRadius; ++i)
		{
			if (str[i] != '#')
				ans.push_back(str[i]);
		}

		return ans;
	}

	int countStr(string s, int index, int start = 0)
	{
		int ans = start;
		int l = s.size();
		for (int i = start + 1; index - i >= 0 && index + i < l; ++i)
		{
			if (s[index - i] == s[index + i])
				++ans;
			else
				break;
		}
		return ans;
	}
	*/
};