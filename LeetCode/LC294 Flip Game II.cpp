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
	bool canWin(string s)
	{
		vector<int> initState;
		int cnt = 0;
		int maxLen = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '+')
			{
				++cnt;
			}
			if (s[i] == '-' || i + 1 == s.size())
			{
				if (cnt > 1)
					initState.push_back(cnt);
				maxLen = max(maxLen, cnt);
				cnt = 0;
			}
		}

		vector<int> g(maxLen + 1, 0);
		for (int len = 2; len <= maxLen; ++len)
		{
			unordered_set<int> st;
			for (int left = 0; left < len / 2; ++left)
			{
				int right = len - left - 2;
				st.insert(g[left] ^ g[right]);
			}
			g[len] = firstMissingNumber(st);
			st.clear();
		}

		int ans = 0;
		for (auto s : initState)
		{
			ans ^= g[s];
		}
		return ans != 0;
	}

	int firstMissingNumber(unordered_set<int> gameSub)
	{
		int n = gameSub.size();
		for (int i = 0; i < n; ++i)
		{
			if (!gameSub.count(i))
				return i;
		}

		return n;
	}

};