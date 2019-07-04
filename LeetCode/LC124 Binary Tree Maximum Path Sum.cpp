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
	int maxPathSum(TreeNode* root)
	{
		if (!root)
			return 0;

		int ans = INT_MIN;
		maxSum(root, ans);

		return ans;
	}

	pair<int, int> maxSum(TreeNode* root, int& ans)
	{
		int mid = root->val;
		pair<int, int> left, right;
		left = make_pair(INT_MIN, INT_MIN);
		right = left;

		if (root->left)
		{
			left = maxSum(root->left, ans);
			mid += left.second;
		}
		if (root->right)
		{
			right = maxSum(root->right, ans);
			mid += right.second;
		}

		int tolMax = max(mid, max(left.first, right.first));
		int midMax = root->val + max(left.second, right.second);

		if (!root->left && !root->right)
			midMax = root->val;

		ans = max(ans, tolMax);

		return pair<int, int>(tolMax, midMax);
	}
};