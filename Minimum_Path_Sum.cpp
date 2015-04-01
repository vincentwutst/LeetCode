class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		const int m = grid.size();
		const int n = grid[0].size();
		vector<int> f(n, INT_MAX);// 初始值是INT_MAX，因为后面用了min 函数。
		f[0] = 0;
		for (int i = 0; i < m; i++) {
			f[0] = f[0] + grid[i][0];//初始化每一行的第一个值=上面的值+本身的值
			for (int j = 1; j < n; j++) {
				// 左边的f[j]，表示更新后的f[j]，与公式中的f[i][j] 对应
				// 右边的f[j]，表示老的f[j]，与公式中的f[i-1][j] 对应
				f[j] = min(f[j - 1], f[j]) + grid[i][j];
			}
		}
		return f[n - 1];
	}
};
