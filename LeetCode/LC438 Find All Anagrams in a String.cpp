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
	vector<int> findAnagrams(string s, string p)
	{
		vector<int> ans;
		int slen = s.size();
		int plen = p.size();
		sort(p.begin(), p.end());

		for (int i = 0; i < slen - plen + 1; ++i)
		{
			string temp(s, i, plen);
			sort(temp.begin(), temp.end());

			if (temp == p)
				ans.push_back(i);
		}
		
		return ans;
	}
};