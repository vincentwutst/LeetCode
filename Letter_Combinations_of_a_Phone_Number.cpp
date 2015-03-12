class Solution {
public:
	//如输入“23”
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits == "") return res;//如果输入为空，输出空
		string tmp(digits.size(), ' ');//临时字符串长度为2
		dfs(digits, 0, tmp, res);
		return res;
	}

	void dfs(const string &digits, int index, string &tmp, vector<string>&res)
	{
		string numap[] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		if (index == digits.size())//index表示输入字符串字符个数。从0开始递增，当index=2时，输出一个结果， 如：“ad”
		{
			res.push_back(tmp);
			return;//返回至上次调用之处
		}
		for (int i = 0; i < numap[digits[index] - '0'].size(); i++)//当index为0时，把“abc”循环一遍；当index为1时，把“def”循环一遍；
		{
			tmp[index] = numap[digits[index] - '0'][i];//取“abc”中的第i位
			dfs(digits, index + 1, tmp, res);//取完“abc”（index=0）中的一位后，再取“def”（index=1）中的一位
		}
	}
};
