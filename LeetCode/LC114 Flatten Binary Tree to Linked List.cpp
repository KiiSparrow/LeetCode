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
	void flatten(TreeNode* root)
	{
		stack<TreeNode*> st;
		TreeNode* p = root;

		while (p)
		{
			if (p->left)
			{
				if (p->right)
					st.push(p->right);
				p->right = p->left;
				p->left = nullptr;
			}
			else if (!p->right && !st.empty())
			{
				p->right = st.top();
				st.pop();
			}

			p = p->right;
		}
	}
};