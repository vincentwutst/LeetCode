class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		int result = 1, n = num.size();
		if (n == 0) return 0;
		
		unordered_set<int> ht;
		for (int i = 0; i < n; i++)
			ht.insert(num[i]);//数组元素全部装入hashtable
		
		while (!ht.empty())
		{
			int maxlen = 1;
			int curr = *(ht.begin());//设当前值为表中第一个值
			ht.erase(curr);//删除表中的该值

			int tmp = curr - 1;//向小的方向递减
			while (!ht.empty() && ht.find(tmp)!= ht.end())
			{
				ht.erase(tmp);
				maxlen++;
				tmp--;
			}

			tmp = curr + 1;//向大的方向递增
			while (ht.empty() == false &&
				ht.find(tmp) != ht.end())
			{
				ht.erase(tmp);
				maxlen++;
				tmp++;
			}
			if (result < maxlen) result = maxlen;
		}
		return result;
	}
};
