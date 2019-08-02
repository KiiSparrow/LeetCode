#include "LeetCode.h"
using namespace std;


static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
	int rob(TreeNode* root)
	{
		if (!root)
			return 0;

		auto steal = dp(root);

		return max(steal.first, steal.second);
	}

	pair<int, int> dp(TreeNode* root)
	{
		auto left = make_pair(0, 0);
		auto right = make_pair(0, 0);

		if (root->left)
			left = dp(root->left);
		if (root->right)
			right = dp(root->right);

		return make_pair(max(left.first, left.second) + max(right.first, right.second), root->val + left.first + right.first);
	}
};