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
		string pcode(26, 'a' - 1);
		string scode(26, 'a' - 1);

		for (auto c : p)
		{
			++pcode[c - 'a'];
		}

		int slen = s.size();
		int plen = p.size();

		if (slen < plen)
			return {};

		for (int i = 0; i < plen; ++i)
		{
			++scode[s[i] - 'a'];
		}
		if (scode == pcode)
			ans.push_back(0);

		int left = 0;
		int right = plen;

		for (; right < slen; ++right)
		{			
			++scode[s[right - 'a']];
			--scode[s[left - 'a']];
			++left;
			if (scode == pcode)
				ans.push_back(left);
		}
		
		return ans;
	}
};