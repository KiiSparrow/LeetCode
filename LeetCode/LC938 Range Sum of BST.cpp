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
	int rangeSumBST(TreeNode* root, int L, int R)
	{
		int sum = 0;
		bstSum(root, L, R, sum);

		return sum;
	}

	void bstSum(TreeNode* root, int& L, int& R, int& sum)
	{
		if (!root)
			return;

		if (L <= root->val && root->val <= R)
		{
			sum += root->val;
			bstSum(root->left, L, R, sum);
			bstSum(root->right, L, R, sum);
		}
		else if (root->val < L)
		{
			bstSum(root->right, L, R, sum);
		}
		else
		{
			bstSum(root->left, L, R, sum);
		}

	}
};