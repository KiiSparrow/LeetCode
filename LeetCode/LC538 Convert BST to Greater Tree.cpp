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
	TreeNode* convertBST(TreeNode* root)
	{
		int sum = 0;
		reversDFS(root, sum);
		
		return root;
	}

	void reversDFS(TreeNode* root, int& sum)
	{
		if (!root)
			return;

		reversDFS(root->right, sum);
		root->val += sum;
		sum = root->val;
		reversDFS(root->left, sum);
	}
};