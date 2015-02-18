class Solution {
public:
	vector<string> anagrams(vector<string> &strs)
	{
		vector<string> result;
		map<string, vector<string> > mp;
		map<string, vector<string> >::iterator it;
		string tmp;
		for (int i = 0; i < strs.size(); i++)
		{
			tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			mp[tmp].push_back(strs[i]);//如果是回文，则不同字符顺序的strs[i]将一个接一个地插入到mp[tmp]中。sort后的tmp是相同的
		}
		for (it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second.size() > 1)//iterator.first <==> key ,  iterator.second <==> value
			{
				for (int i = 0; i < (it->second).size(); i++)
					result.push_back((it->second)[i]);
			}
		}
		return result;
	}
};
