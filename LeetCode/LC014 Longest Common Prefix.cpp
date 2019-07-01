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
	string longestCommonPrefix(vector<string>& strs)
	{
		if (strs.size() == 0)
			return "";
		string res{ strs[0] };
		for (int i = 1; i < strs.size(); ++i)
		{
			string temp;
			for (int j = 0; j < res.length(); ++j)
			{
				if (res[j] == strs[i][j])
				{
					temp.push_back(res[j]);
					continue;
				}
				else
				{
					break;
				}
			}
			res = temp;
		}

		return res;
	}
};