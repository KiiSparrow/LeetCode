#include "LeetCode.h"
using namespace std;


static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class NumArray
{
private:
	vector<int> sum;
public:
	NumArray(vector<int>& nums)
	{
		sum.resize(nums.size() + 1);
		sum[0] = 0;
		for (int i = 1; i <= nums.size(); i++)
		{
			sum[i] = sum[i - 1] + nums[i - 1];
		}
	}

	int sumRange(int i, int j)
	{
		return sum[j + 1] - sum[i];
	}
};