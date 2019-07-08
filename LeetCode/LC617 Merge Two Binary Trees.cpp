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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
	{
		if (!t1)
			return t2;
		if (!t2)
			return t1;

		t1->val += t2->val;
		merge(t1, t2);

		return t1;
	}

	void merge(TreeNode* t1, TreeNode* t2)
	{
		if (t1->left && t2->left)
		{
			t1->left->val += t2->left->val;
			merge(t1->left, t2->left);
		}
		else if (t2->left)
		{
			t1->left = t2->left;
		}
		
		if (t1->right && t2->right)
		{
			t1->right->val += t2->right->val;
			merge(t1->right, t2->right);
		}
		else if (t2->right)
		{
			t1->right = t2->right;
		}
	}
};