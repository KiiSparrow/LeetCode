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
	vector<string> letterCombinations(string digits)
	{
		if (digits.size() == 0)
			return vector<string>(0);

		vector<string> num{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		return sub(num, digits);
	}

	vector<string> sub(vector<string> &num, string digits)
	{
		vector<string> ans;
		if (digits.size() == 1)
		{
			for (auto subStr : num[digits[0] - '0'])
			{
				string temp;
				ans.push_back(subStr + temp);
			}
			return ans;
		}

		vector<string> temp = sub(num, digits.substr(1));
		for (auto startChar : num[digits[0] - '0'])
		{
			for (auto subStr : temp)
			{
				ans.push_back(startChar + subStr);
			}
		}
		return ans;
	}
};