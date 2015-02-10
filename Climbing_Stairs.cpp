class Solution {
public:
	//Recursive method
	int climbStairs1(int n)
	{
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 2;

		return climbStairs1(n - 1) + climbStairs1(n - 2);
	}

	//Iterative method
	int climbStairs2(int n)
	{
		if (n == 0) return 0;
		int prev = 0;
		int cur = 1;
		int tmp = 0;
		for (int i = 1; i <= n; ++i)
		{
			tmp = cur;
			cur += prev;
			prev = tmp;
		}
		return cur;
	}
};
