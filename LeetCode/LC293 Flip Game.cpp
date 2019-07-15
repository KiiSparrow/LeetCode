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
	vector<string> generatePossibleNextMoves(string s)
	{
		int len = s.size();
		vector<string> ans;

		for (int i = 0; i < len - 1; ++i)
		{
			if (s.substr(i, 2) == "++")
			{
				ans.push_back(s.replace(i, 2, "--"));
				s.replace(i, 2, "++");
			}
		}

		return ans;
	}
};