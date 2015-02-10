class Solution {
public:
	int threeSumClosest(vector<int> &num, int target){
		int result = 0;
		int min_gap = 0x7fffffff;//最大值
		int n = num.size();

		if (n < 3)
			return 0;

		sort(num.begin(), num.end());//从小到大排序
		int left, right, tmp;

		for (int i = 0; i < n - 2; i++)
		{
			left = i + 1;
			right = n - 1;
			while (left < right)
			{
				tmp = num[i] + num[left] + num[right];
				if (abs(tmp - target) < min_gap)
				{
					result = tmp;
					min_gap = abs(tmp - target);
				}
				if (tmp < target)
					left++;
				else
					right--;
			}
		}
		return result;
	}
};
