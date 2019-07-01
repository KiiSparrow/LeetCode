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
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> ans;
		stack<TreeNode*> node;
		TreeNode* cur = root;

		while (cur || !node.empty())
		{
			if (cur)
			{
				node.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = node.top();
				node.pop();
				ans.push_back(cur->val);
				cur = cur->right;
			}
		}

		return ans;
	}
};