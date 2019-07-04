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
	vector<int> preorderTraversal(TreeNode* root)
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
			st.pop();
			ans.push_back(cur->val);

			if (cur->right)
				st.push(cur->right);
			if (cur->left)
				st.push(cur->left);
		}

		return ans;
	}
};