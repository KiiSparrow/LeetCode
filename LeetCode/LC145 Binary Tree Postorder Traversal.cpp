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
	vector<int> postorderTraversal(TreeNode* root)//Iteratively
	{
		if (!root)
			return {};

		stack<TreeNode*> st;
		st.push(root);
		
		vector<int> ans;
		auto cur = root;
		while (!st.empty())
		{
			cur = st.top();
			if (cur->left || cur->right)
			{
				if (cur->right)
					st.push(cur->right);
				if (cur->left)
					st.push(cur->left);

				cur->left = nullptr;
				cur->right = nullptr;
			}
			else
			{
				ans.push_back(cur->val);
				st.pop();
			}
		}

		return ans;
	}

	vector<int> postorderTraversal_Recursive(TreeNode* root)
	{
		vector<int> ans;
		bTreePost(root, ans);

		return ans;
	}

	void bTreePost(TreeNode* root, vector<int>& ans)
	{
		if (!root)
			return;

		bTreePost(root->left, ans);
		bTreePost(root->right, ans);

		ans.push_back(root->val);
	}
};