class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] == 1) return 0;

		vector<int> DP(n, 0);
		DP[0] = 1;
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (obstacleGrid[i][j] == 1)
					DP[j] = 0;
				else if (j >0)
					DP[j] = DP[j - 1] + DP[j];
			}
		}
		return DP[n - 1];
	}
};
