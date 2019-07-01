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
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, vector<string>> smap;

		for (auto str : strs)
		{
			smap[encode(str)].push_back(str);
		}

		vector<vector<string>> ans;
		for (auto it = smap.begin(); it != smap.end(); ++it)
		{
			ans.push_back((*it).second);
		}

		return ans;
	}

	inline string encode(string& str)
	{
		string strcode(26, '0');
		for (auto c : str)
		{
			++strcode[c - 'a'];
		}

		return strcode;
	}
};