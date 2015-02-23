class Solution {
public:
	vector<vector<int> > subsets(vector<int> &s)
	{
		vector<vector<int> > result;
		int n = s.size();
		sort(s.begin(), s.end());// 输出要求有序
		for (int i = 0; i<pow(2, n); ++i)//如n=3, 2^3=8, i= 000, 001, 010, 011, 100, 101, 110, 111
		{
			vector<int> tmp;
			int index = 0;
			int j = i;
			while (j > 0)
			{
				if (j & 1)
					tmp.push_back(s[index]);// 为1的位上填入s[]对应的值
				j >>= 1;
				++index;
			}
			result.push_back(tmp);
		}
		return result;
	}
};
