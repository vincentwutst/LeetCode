class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> solution; // 中间结果
		vector<int> C;// C[i] 表示第i 行皇后所在的列编号
		dfs(n, 0, C, solution, result);
		return result;
	}

	void dfs(int n, int row, vector<int> &C, vector<string> &solution, vector<vector<string>> &result) {
		if (row == n) {// 终止条件，找到了一个可行解
			result.push_back(solution);
			return;
		}

		for (int j = 0; j<n; j++) {//j表示第j列
			if (validPos(C, row, j)) {
				string s(n, '.');
				s[j] = 'Q';
				solution.push_back(s);
				C.push_back(j);
				dfs(n, row + 1, C, solution, result);
				solution.pop_back();
				C.pop_back();
			}
		}
	}

	bool validPos(vector<int> &C, int row, int col) {
		if (row<C.size()) return false;
		for (int i = 0; i<C.size(); i++) {//C[i]表示第i 行皇后所在的列编号
			if (col == C[i] || abs(row - i) == abs(col - C[i]))
				return false;
		}
		return true;
	}
};
