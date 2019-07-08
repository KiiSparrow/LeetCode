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
		vector<int> path;
		return subSum(root, path, sum);
	}

	int subSum(TreeNode* root, vector<int>& path, int sum)
	{
		if (!root)
			return 0;

		path.push_back(root->val);

		int ans = 0;
		int re = 0;
		for (int i = path.size() - 1; i >= 0; --i)
		{
			re += path[i];
			if (re == sum)
				++ans;
		}

		int childAns = subSum(root->left, path, sum) + subSum(root->right, path, sum);

		path.pop_back();

		return ans + childAns;
	}

	/*
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
	*/
};