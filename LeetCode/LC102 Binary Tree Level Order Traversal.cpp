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
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		if (!root)
			return {};

		vector<vector<int>> ans;
		queue<TreeNode*> cur;

		cur.push(root);

		while (!cur.empty())
		{
			vector<int> temp;
			int n = cur.size();

			for (int i = 0; i < n; i++)
			{
				auto p = cur.front();
				cur.pop();
				temp.push_back(p->val);

				if (p->left)
					cur.push(p->left);
				if (p->right)
					cur.push(p->right);
			}
			ans.push_back(temp);
		}

		return ans;
	}
};