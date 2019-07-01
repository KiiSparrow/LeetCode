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
	int minDepth(TreeNode* root)
	{
		if (!root)
			return 0;
		if (!root->left && !root->right)
			return 1;
		if (!root->left)
			return minDepth(root->right) + 1;
		if (!root->right)
			return minDepth(root->left) + 1;

		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};