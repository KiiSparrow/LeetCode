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
	vector<TreeNode*> generateTrees(int n)
	{
		if (n == 0)
			return {};

		vector<vector<vector<TreeNode*>>> dp(n + 1, vector<vector<TreeNode*>>(n + 1));
		for (int j = 1; j <= n; j++)
		{
			dp[j][j].push_back(new TreeNode(j));
			for (int i = j - 1; i >= 1; i--)
			{
				for (int k = i; k <= j; k++)
				{
					vector<TreeNode*> *leftPart, *rightPart;

					if (i <= k - 1)
						leftPart = &dp[i][k - 1];
					else
						leftPart = new vector<TreeNode*>{ nullptr };

					if (k + 1 <= j)
						rightPart = &dp[k + 1][j];
					else
						rightPart = new vector<TreeNode*>{ nullptr };

					for (auto left : *leftPart)
					{
						for (auto right : *rightPart)
						{
							TreeNode* node = new TreeNode(k);
							node->left = left;
							node->right = right;
							dp[i][j].push_back(node);
						}
					}
				}
			}
		}

		return dp[1][n];
	}

	vector<TreeNode*> generateTrees_Backtracking(int n)
	{
		if (n == 0)
			return {};
		return genSubTree(1, n);
	}

	vector<TreeNode*> genSubTree(int left, int right)
	{
		if (left > right)
			return { nullptr };
		if (left == right)
			return { new TreeNode(left) };

		vector<TreeNode*> ans;
		for (int i = left; i <= right; i++)
		{
			for (auto leftSub : genSubTree(left, i - 1))
			{
				for (auto rightSub : genSubTree(i + 1, right))
				{
					TreeNode *temp = new TreeNode(i);
					temp->left = leftSub;
					temp->right = rightSub;
					ans.push_back(temp);
				}
			}
		}

		return ans;
	}
};