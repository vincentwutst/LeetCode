class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > result;
		vector<vector<int> > post;
		vector<int> tmp;
		if (num.size() == 1)
		{
			result.push_back(num);
			return result;
		}

		for (int i = 0; i < num.size(); i++)
		{
			tmp = num;
			tmp.erase(tmp.begin()+i);//抹去第i位
			post = permute(tmp);
			for (int j = 0; j < post.size(); ++j)
			{
				post[j].insert(post[j].begin(), num[i]);//在子数组首位插入抹去的第i位
				result.push_back(post[j]);//子数组添加到二维数组中
			}
		}
		return result;

	}
};
