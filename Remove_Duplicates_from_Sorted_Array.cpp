class Solution {
public:
	int removeDuplicates(int A[], int n)
	{
		if (n < 2) return n;
		int end = 0;
		for (int i = 1; i < n; i++)
		{
			if (A[end] != A[i])
			{
				end++;
				if (end != i)
					A[end] = A[i];
			}
		}
		return end + 1;
	}
};
