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
		int slen = s.size();
		int plen = p.size();
		if (slen < plen)
			return {};

		vector<int> ans;
		vector<int> pcode(26, 0);
		vector<int> scode(26, 0);

		for (auto c : p)
		{
			++pcode[c - 'a'];
		}
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
			++scode[s[right] - 'a'];
			--scode[s[left] - 'a'];
			++left;
			if (scode == pcode)
				ans.push_back(left);
		}
		
		return ans;
	}
};