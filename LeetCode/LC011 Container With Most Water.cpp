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
	int maxArea(vector<int>& height)
	{
		queue<pair<int, int>> up;
		stack<pair<int, int>> down;

		up.push(make_pair(height[0], 0));
		down.push(make_pair(height[0], 0));

		//模仿数据流输入情况
		for (int i = 1; i < height.size(); ++i)
		{
			//up
			if (height[i] > up.back().first)
				up.push(make_pair(height[i], i));

			//down
			while (!down.empty() && height[i] >= down.top().first)
				down.pop();
			down.push(make_pair(height[i], i));
		}

		int ans = 0;
		pair<int, int> left, right;
		while (!up.empty() && !down.empty())
		{
			left = up.front();
			right = down.top();
			ans = max(ans, (right.second - left.second) * min(left.first, right.first));
			if (left.first < right.first)
				up.pop();
			else
				down.pop();
		}

		return ans;
	}

	int maxArea_old(vector<int>& height)
	{
		int len = height.size();
		int ans = 0;
		int i = 0, j = len - 1;
		while (i < j)
		{
			ans = max(ans, min(height[i], height[j]) * (j - i));
			if (height[i] < height[j])
				++i;
			else
				--j;
		}
		return ans;
	}
};