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
	vector<string> generateParenthesis(int n)
	{
		if (n == 0)
			return vector<string>{""};

		vector<string> ans;

		for (int i = 0; i < n; ++i)
		{
			for (auto left : generateParenthesis(i))
			{
				for (auto right : generateParenthesis(n - 1 - i))
				{
					ans.push_back("(" + left + ")" + right);
				}
			}
		}

		return ans;
	}

	vector<string> generateParenthesis2(int n)
	{
		vector<string> ans;
		genSub(ans, "", 0, 0, n);
		return ans;
	}

	void genSub(vector<string> &ans, string cur, int left, int right, int max)
	{
		if (cur.size() == max * 2)
		{
			ans.push_back(cur);
			return;
		}

		if (left < max)
		{
			genSub(ans, cur + '(', left + 1, right, max);
		}
		if (right < left)
		{
			genSub(ans, cur + ')', left, right + 1, max);
		}
	}
};