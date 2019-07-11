#include "LeetCode.h"
using namespace std;


static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class MedianFinder
{
public:
	/** initialize your data structure here. */
	MedianFinder()
	{

	}

	void addNum(int num)
	{
		if (right.empty() || num <= right.top())
			left.push(num);
		else
			right.push(num);

		balHeap();
	}

	double findMedian()
	{
		if (left.size() == right.size())
			return ((double)left.top() + (double)right.top()) / 2;

		return left.top();
	}

	void balHeap()
	{
		int ls = left.size();
		int rs = right.size();

		if (ls > rs + 1)
		{
			right.push(left.top());
			left.pop();
		}
		else if (ls < rs)
		{
			left.push(right.top());
			right.pop();
		}
	}

private:
	priority_queue<int, vector<int>, less<int>> left;
	priority_queue<int, vector<int>, greater<int>> right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */