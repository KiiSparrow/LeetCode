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
	int maxDepth(TreeNode* root)
	{
		if (root == nullptr)
			return 0;

		else
			return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};
