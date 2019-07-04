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
	int sumNumbers(TreeNode* root)
	{
		if (!root)
			return 0;

		int sum = 0;
		sumRe(root, 0, sum);

		return sum;
	}

	void sumRe(TreeNode* root, int cur, int& sum)
	{
		cur = 10 * cur + root->val;

		if (!root->left && !root->right)
		{
			sum += cur;
			return;
		}

		if (root->left)
			sumRe(root->left, cur, sum);
		if (root->right)
			sumRe(root->right, cur, sum);
	}
};