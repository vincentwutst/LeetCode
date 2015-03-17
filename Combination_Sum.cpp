class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
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
		for (size_t i = start; i < nums.size(); i++) { // 扩展状态  
			//优化剪枝，如：{2,3,6,7} target=7;那么到了2,3之后7-2-3=4,nums[i]=6  
			//这样4<6那么6和7都不用继续下面的计算了，直接返回就可以了。  
			//这里是最好的剪枝位置了。  
			if (gap < nums[i]) return; // 剪枝  

			intermediate.push_back(nums[i]); // 执行扩展动作
			dfs(nums, gap - nums[i], i, intermediate, result);
			intermediate.pop_back(); // 撤销动作
		}
	}
};
