class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > result; // 最终结果
		vector<int> intermediate; // 中间结果
		dfs(candidates, target, 0, intermediate, result);
		return result;
	}

	void dfs(vector<int>& nums, int gap, int start, vector<int>& intermediate,
		vector<vector<int> > &result) 
	{
		if (gap == 0) { // 找到一个合法解
			result.push_back(intermediate);
			return;
		}
//		int previous = -1; //记录前一个数
		for (int i = start; i < nums.size(); i++) { // 扩展状态  
			if(i>start && nums[i]==nums[i-1]) continue;
			if (gap < nums[i]) return; // 剪枝  
//			previous = nums[i];
			intermediate.push_back(nums[i]); // 执行扩展动作
			dfs(nums, gap-nums[i], i+1, intermediate, result);
			intermediate.pop_back(); // 撤销动作
		}
	}
};
