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
	string minWindow(string s, string t)
	{
		if (s.empty() || t.empty())
			return "";

		vector<int> tab(256, 0);
		vector<int> tar(256, 0);
		for (char ch : t)
		{
			++tar[ch];
		}
		
		int left = 0;
		string ans;
		int i = 0;
		while (i < s.size())
		{
			while (!isIncluded(tab, tar) && i < s.size())
			{
				++tab[s[i]];
				++i;
			}

			while (isIncluded(tab, tar))
			{
				--tab[s[left]];
				++left;
			}
			
			--left;
			++tab[s[left]];

			if (isIncluded(tab, tar) && (ans.empty() || i - left < ans.size()))
			{
				ans = s.substr(left, i - left);
			}

			--tab[s[left]];
			++left;
		}

		return ans;
	}
private:
	inline bool isIncluded(const vector<int>& s, const vector<int>& t) const
	{
		for (int i = 0; i < t.size(); ++i)
		{
			if (s[i] < t[i])
				return false;
		}
		return true;
	}
};