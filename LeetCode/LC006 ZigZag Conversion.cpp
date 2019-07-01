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
	string convert(string s, int numRows)
	{
		if (numRows == 1)
			return s;

		int len = s.size();
		vector<string> sm(numRows);
		int next = 0;
		int step = 1;
		for (int i = 0; i < len; ++i)
		{
			sm[next].push_back(s[i]);

			if (next == 0)
				step = 1;
			if (next == numRows - 1)
				step = -1;

			next += step;
		}

		string ans;
		for (auto t : sm)
		{
			ans += t;
		}

		return ans;
	}
};