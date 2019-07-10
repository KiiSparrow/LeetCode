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
	int diameterOfBinaryTree(TreeNode* root)
	{
		int ans = 0;
		path(root, ans);

		return ans;
	}

	int path(TreeNode* root, int& dia)
	{
		if (!root)
			return 0;

		int left = path(root->left, dia);
		int right = path(root->right, dia);

		dia = max(dia, left + 1 + right);

		return max(left, right) + 1;
	}
};