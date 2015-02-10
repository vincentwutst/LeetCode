class Solution {
public:
	vector<int> twoSum(vector<int> &num, int target) {
		vector<int> result;
		map<int, int> mapping;

		for (int i = 0; i != num.size(); ++i)//put vector into map
		{
			mapping[num[i]] = i;
		}

		for (int i = 0; i != num.size(); ++i)
		{
			int gap = target - num[i];

			//mapping.find(k): 如果容器中存在按k索引的元素，则返回指向该元素的迭代器
			//mapping.end()指向容器的最后一个元素的下一位置
			if (mapping.find(gap) != mapping.end() && mapping[gap] > i)
			{
				//题目中例子是 index1=1，而非0，所以此处+1
				result.push_back(i + 1);
				result.push_back(mapping[gap] + 1);//同上
				break;
			} 
		}
		return result;
	}
};
