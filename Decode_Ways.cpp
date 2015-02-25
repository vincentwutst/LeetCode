class Solution {
public:
int numDecodings(string s) 
{
	int n = s.size();
	if (n == 0) return 0;
	vector<int> d(n + 1,0);//d[i]表示s[0...i-1]的解码方法数目
	d[0] = 1;
	if (s[0] != '0')
		d[1] = 1;
	else 
		d[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (s[i - 1] != '0')//把末尾一个数字当做一个字母来考虑
		     d[i] = d[i - 1];
		else d[i] = 0;
		if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))//把末尾两个数字当做一个字母来考虑
		     d[i] += d[i - 2];//d[i] = ( s[i-1] == 0 ? 0 : d[i-1] ) 
                                     //     + ( s[i-2,i-1]可以表示字母 ？d[i-2] : 0 )
	}
	return d[n];
}
};
