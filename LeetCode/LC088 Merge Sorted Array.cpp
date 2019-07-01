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
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		vector<int> ans(m + n, 0);
		int i = 0, j = 0;
		int k = 0;
		for (; i < m && j < n; ++k)
		{
			if (nums1[i] < nums2[j])
			{
				ans[k] = nums1[i];
				++i;
			}
			else
			{
				ans[k] = nums2[j];
				++j;
			}
		}

		if (i == m)
		{
			while (j < n)
			{
				ans[k] = nums2[j];
				++k;
				++j;
			}
		}
		else if (j == n)
		{
			while (i < m)
			{
				ans[k] = nums1[i];
				++k;
				++i;
			}
		}

		nums1 = ans;
	}
};