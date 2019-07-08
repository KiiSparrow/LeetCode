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
	int trap(vector<int>& height)
	{
		int ans = 0;
		stack<int> st;
		int cur = 0;

		while (cur < height.size())
		{
			while (!st.empty() && height[st.top()] < height[cur])
			{
				int bot = st.top();
				st.pop();
				if (st.empty())
					break;

				ans += (cur - st.top() - 1) * (min(height[st.top()], height[cur]) - height[bot]);
			}
			st.push(cur++);
		}


		return ans;
	}
};