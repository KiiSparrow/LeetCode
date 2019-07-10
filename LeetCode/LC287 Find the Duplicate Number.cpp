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
	int findDuplicate(vector<int>& nums)
	{
		int n = nums.size();

		int k;
		for (int i = 0; i < n; ++i)
		{
			k = abs(nums[i]) - 1;
			if (nums[k] < 0)
				return k + 1;
			nums[k] *= -1;
		}

		return -1;
	}

	//int findDuplicate_floyd(vector<int>& nums)
	//{
	//	//Floyd求环
	//	int fast = 0;
	//	int slow = 0;

	//	do
	//	{
	//		slow = nums[slow];
	//		fast = nums[nums[fast]];
	//	} while (slow != fast);

	//	int ans = 0;
	//	while (ans != slow)
	//	{
	//		ans = nums[ans];
	//		slow = nums[slow];
	//	}

	//	return ans;
	//}

	//int findDuplicate_nlogn(vector<int>& nums)
	//{
	//	int left = 1;
	//	int right = nums.size() - 1;
	//	int mid;
	//	int cnt;
	//	
	//	while (left < right)
	//	{
	//		mid = (left + right) / 2;
	//		cnt = 0;
	//		for (int num : nums)
	//		{
	//			if (num <= mid)
	//				++cnt;
	//		}

	//		if (cnt <= mid)
	//			left = mid + 1;
	//		else
	//			right = mid;
	//	}

	//	return left;
	//}
};