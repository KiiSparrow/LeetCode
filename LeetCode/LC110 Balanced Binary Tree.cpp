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
	bool isBalanced(TreeNode* root)
	{
		int height = 0;
		return isBalanHei(root, height);
	}

	bool isBalanHei(TreeNode* root, int& hei)
	{
		if (!root)
		{
			hei = 0;
			return true;
		}

		int leftHei = 0;
		int rightHei = 0;
		
		if (isBalanHei(root->left, leftHei) && isBalanHei(root->right, rightHei))
		{
			hei = max(leftHei, rightHei) + 1;
			return abs(leftHei - rightHei) <= 1;
		}

		return false;
	}
};