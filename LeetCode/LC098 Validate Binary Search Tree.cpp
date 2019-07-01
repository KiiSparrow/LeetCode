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
	bool isValidBST(TreeNode* root)
	{
		if (!root)
			return true;

		return checkLeft(root->left, LONG_MIN, root->val) && checkRight(root->right, root->val, LONG_MAX);
	}

	bool checkLeft(TreeNode* p, long l, long r)
	{
		if (!p)
			return true;

		if (p->val >= r || p->val <= l)
			return false;

		return checkLeft(p->left, l, p->val) && checkRight(p->right, p->val, r);
	}

	bool checkRight(TreeNode* p, long l, long r)
	{
		if (!p)
			return true;

		if (p->val <= l || p->val >= r)
			return false;

		return checkLeft(p->left, l, p->val) && checkRight(p->right, p->val, r);
	}
};