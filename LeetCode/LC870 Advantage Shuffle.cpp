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
	vector<int> advantageCount(vector<int>& A, vector<int>& B)
	{
		class node
		{
		public:
			int val;
			int index;
		};
		vector<node> newB(B.size());
		for (int i = 0; i < B.size(); ++i)
		{
			newB[i].val = B[i];
			newB[i].index = i;
		}

		sort(A.begin(), A.end());
		sort(newB.begin(), newB.end(), [](node a, node b)
		{
			return a.val < b.val;
		});

		int leftA = 0, leftB = 0;
		int rightA = A.size() - 1;
		int rightB = rightA;

		while (leftB <= rightB)
		{
			if (A[rightA] > newB[rightB].val)
			{
				B[newB[rightB].index] = A[rightA];
				--rightA;
				--rightB;
			}
			else if (A[leftA] <= newB[leftB].val)
			{
				B[newB[rightB].index] = A[leftA];
				++leftA;
				--rightB;
			}
			else
			{
				B[newB[leftB].index] = A[leftA];
				++leftA;
				++leftB;
			}
		}

		return B;
	}
};