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
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		auto A = nums1;
		auto B = nums2;
		if (A.size() > B.size())
			swap(A, B);

		int left = 0;
		int right = A.size();
		int halfLen = (A.size() + B.size() + 1) / 2;

		while (left <= right)
		{
			int i = (left + right) / 2;
			int j = halfLen - i;

			if (i < right && B[j - 1] > A[i])
				left = i + 1;
			else if (i > left && A[i - 1] > B[j])
				right = i - 1;
			else
			{
				int maxLeft = 0;
				if (i == 0)
					maxLeft = B[j - 1];
				else if (j == 0)
					maxLeft = A[i - 1];
				else
					maxLeft = max(A[i - 1], B[j - 1]);
				if ((A.size() + B.size()) % 2)
					return maxLeft;

				int minRight = 0;
				if (i == A.size())
					minRight = B[j];
				else if (j == B.size())
					minRight = A[i];
				else
					minRight = min(A[i], B[j]);
				
				return (double)(maxLeft + minRight) / 2;

			}
		}
	}
};

class Solution2
{
public:
	void findMid(int begin, int end, vector<int>& mid)
	{
		mid[0] = (end + begin) / 2;
		if ((end - begin + 1) % 2)
		{
			mid[1] = mid[0];
		}
		else
		{
			mid[1] = mid[0] + 1;
		}
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		if (nums1.size() > nums2.size())
			swap(nums1, nums2);

		int b1 = 0, e1 = nums1.size() - 1;
		int b2 = 0, e2 = nums2.size() - 1;
		vector<int> mid1(2), mid2(2);

		if (e1 == -1)
		{
			findMid(b2, e2, mid2);
			return (double)(nums2[mid2[0]] + nums2[mid2[1]]) / 2;
		}
		if (e2 == -1)
		{
			findMid(b1, e1, mid1);
			return (double)(nums1[mid1[0]] + nums1[mid1[1]]) / 2;
		}

		findMid(b1, e1, mid1);
		findMid(b2, e2, mid2);
		int cut = (e1 - b1) / 2;

		while (cut)
		{
			if (nums1[mid1[0]] < nums2[mid2[0]])
			{
				b1 += cut;
				e2 -= cut;
			}
			else
			{
				b2 += cut;
				e1 -= cut;
			}

			findMid(b1, e1, mid1);
			findMid(b2, e2, mid2);
			cut = (e1 - b1) < (e2 - b2) ? (e1 - b1) / 2 : (e2 - b2) / 2;
		}

		int mid0Num, mid1Num;

		if (mid1[0] == mid1[1] && mid2[0] == mid2[1])//2
		{
			if (mid2[0] != b2 && nums1[mid1[0]] < nums2[mid2[0] - 1])
				return (double)(nums2[mid2[0] - 1] + nums2[mid2[0]]) / 2;
			else if (mid2[0] != e2 && nums1[mid1[0]] > nums2[mid2[0] + 1])
				return (double)(nums2[mid2[0]] + nums2[mid2[0] + 1]) / 2;
			else
				return (double)(nums1[mid1[0]] + nums2[mid2[0]]) / 2;
		}
		else if (mid1[0] == mid1[1] && mid2[0] != mid2[1])//3
		{
			if (nums1[mid1[0]] < nums2[mid2[0]])
			{
				return nums2[mid2[0]];
			}
			else if (nums1[mid1[0]] > nums2[mid2[1]])
			{
				return nums2[mid2[1]];
			}
			else
			{
				return nums1[mid1[0]];
			}
		}
		else if (mid1[0] != mid1[1] && mid2[0] == mid2[1])//3
		{
			if (nums1[mid1[1]] < nums2[mid2[0]])
			{
				if (mid2[0] != b2 && nums1[mid1[1]] < nums2[mid2[0] - 1])
					return nums2[mid2[0] - 1];
				else
					return nums1[mid1[1]];
			}
			else if (nums1[mid1[0]] > nums2[mid2[0]])
			{
				if (mid2[0] != e2 && nums1[mid1[0]] > nums2[mid2[0] + 1])
					return nums2[mid2[0] + 1];
				else
					return nums1[mid1[0]];
			}
			else
			{
				return nums2[mid2[0]];
			}
		}
		else//4
		{
			if (nums1[mid1[1]] < nums2[mid2[0]])
			{
				if (mid2[0] != b2 && nums1[mid1[1]] < nums2[mid2[0] - 1])
					return (double)(nums2[mid2[0] - 1] + nums2[mid2[0]]) / 2;
				else
					return (double)(nums1[mid1[1]] + nums2[mid2[0]]) / 2;
			}
			else if (nums1[mid1[0]] > nums2[mid2[1]])
			{
				if (mid2[1] != e2 && nums1[mid1[0]] > nums2[mid2[1] + 1])
					return (double)(nums2[mid2[1]] + nums2[mid2[1] + 1]) / 2;
				else
					return (double)(nums1[mid1[0]] + nums2[mid2[1]]) / 2;
			}
			else
			{
				int midUpNum = nums1[mid1[0]] > nums2[mid2[0]] ? nums1[mid1[0]] : nums2[mid2[0]];
				int midDownNum = nums1[mid1[1]] < nums2[mid2[1]] ? nums1[mid1[1]] : nums2[mid2[1]];
				return (double)(midUpNum + midDownNum) / 2;
			}
		}
	}
};