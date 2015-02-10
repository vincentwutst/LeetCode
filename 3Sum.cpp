class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num)
	{
		vector<vector<int> > result;
		if (num.size() < 3) return result;

		int left, right;//左右夹逼
		int n = num.size();
		sort(num.begin(), num.end());//从小到大排序

		for (int i = 0; i < n - 2; ++i)
		{
			if (i > 0 && num[i] == num[i - 1]) continue;//如遇相同元素，跳过
			left = i + 1;
			right = n - 1;
			while (left < right)
			{
				if (left > i + 1 && num[left] == num[left - 1])//左遇相同元素跳过
				{
					left++;
					continue;
				}
				if (right < n - 1 && num[right] == num[right + 1])//右遇相同元素跳过
				{
					right--;
					continue;
				}
				if (num[left] + num[right] == 0 - num[i])
				{
					result.push_back({ num[i], num[left], num[right] });
					left++;
				}
				else if (num[left] + num[right] < 0 - num[i])
					left++;
				else
					right--;
			} 

		}
		return result;
	}
};
