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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (!root)
			return nullptr;
		if (root == p || root == q)
			return root;

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		if (left && left != p && left != q)
			return left;

		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		if (left && right)
			return root;
		if (left)
			return left;
		if (right)
			return right;

		return nullptr;
	}
};