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
	int strStr(string haystack, string needle)
	{
		if (!needle.size())
			return 0;
		if (haystack.size() < needle.size())
			return -1;

		int k = 0;
		for (int i = 0; i < haystack.size(), i + needle.size() <= haystack.size(); ++i)
		{
			if (haystack[i] == needle[0])
			{
				k = 1;
				for (int j = 1; j < needle.size(); ++j)
				{
					if (haystack[i + j] != needle[j])
					{
						k = 0;
						break;
					}
				}
				if (k)
					return i;
			}
		}

		return -1;
	}
};