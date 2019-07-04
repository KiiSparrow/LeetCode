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
		int ans = INT_MIN;
		maxSum(root, ans);

		return ans;
	}

	int maxSum(TreeNode* root, int& ans)
	{
		int left = 0, right = 0;

		if (root->left)
			left = max(0, maxSum(root->left, ans));
		if (root->right)
			right = max(0, maxSum(root->right, ans));

		ans = max(ans, root->val + left + right);

		return root->val + max(left, right);
	}

	inline int max(int a, int b)
	{
		return a > b ? a : b;
	}
};