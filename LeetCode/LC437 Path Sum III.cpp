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
	int pathSum(TreeNode* root, int sum)
	{
		int ans = 0;
		DFS(root, sum, ans);

		return ans;
	}

	void DFS(TreeNode* root, int sum, int& ans)
	{
		if (!root)
			return;

		DFSSum(root, 0, sum, ans);

		DFS(root->left, sum, ans);
		DFS(root->right, sum, ans);
	}

	void DFSSum(TreeNode* root, int cur,int sum, int& ans)
	{
		if (!root)
			return;

		cur += root->val;
		if (cur == sum)
			++ans;

		DFSSum(root->left, cur, sum, ans);
		DFSSum(root->right, cur, sum, ans);
	}
};