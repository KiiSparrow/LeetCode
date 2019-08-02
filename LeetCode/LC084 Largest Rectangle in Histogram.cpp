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
	int largestRectangleArea(vector<int>& heights)
	{
		stack<int> st;
		st.push(-1);
		int maxArea = 0;

		for (int i = 0; i < heights.size(); ++i)
		{
			while (st.top() != -1 && heights[i] <= heights[st.top()])
			{
				int currentHeight = heights[st.top()];
				st.pop();
				maxArea = max(maxArea, currentHeight * (i - st.top() - 1));
			}
			st.push(i);
		}

		while (st.top() != -1)
		{
			int currentHeight = heights[st.top()];
			st.pop();
			maxArea = max(maxArea, currentHeight * ((int)heights.size() - st.top() - 1));
		}

		return maxArea;
	}
};