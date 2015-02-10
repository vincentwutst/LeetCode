class Solution {
public:
	void merge(int A[], int m, int B[], int n)
	{
		int p = m - 1;
		int q = n - 1;
		int tmp = m + n - 1;

		while ((p >= 0) && (q >= 0))
			A[tmp--] = A[p] > B[q] ? A[p--] : B[q--];

		while (q >= 0)//if A reaches end but B not 
			A[tmp--] = B[q--];
	}
};
