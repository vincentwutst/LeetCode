class Solution {
public:
	vector<vector<int> > combine(int n, int k) 
	{
		vector<vector<int> > result;
		if (k > n || k == 0) return result;

		vector<int> path;
		dfs(result, path, n, k, 1);
		return result;
	}

	void dfs(vector<vector<int> > &result, vector<int> &path, int n, int k, int start)
	{
		if (path.size() == k)
		{
			result.push_back(path);
			return;
		}

		for (int i = start; i <= n; i++)
		{
			path.push_back(i);
			dfs(result, path, n, k, i + 1);
			path.pop_back();
		}
	}

};
