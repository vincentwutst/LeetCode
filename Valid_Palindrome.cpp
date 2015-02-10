class Solution {
public:
	char toLower(char c)//全部转成小写，'0'=48,'A'=65,'a'=97
	{
		if (c >= 'A' && c <= 'Z')
			return (c + ('a' - 'A'));
		return c;
	}

	bool isPalindrome(string s)
	{
		if (s.empty()) return true;//如是空字符串，是回文
		string ss;
		stack<char> st;
		int cnt = 0;
		for (int i = 0; i < s.size(); ++i)
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A'&& s[i] <= 'Z')
				|| (s[i] >= '0'&& s[i] <= '9'))//剔除非字母数字元素
			{
				ss.append(1, toLower(s[i]));//在ss尾部追加1位元素--小写化了的s[i]
				st.push(toLower(s[i]));//同时入栈--小写化了的s[i]
			}

		for (int i = 0; i < ss.size(); ++i)
		{

			if (ss[i] != st.top())//字符串的当前元素是否等于栈顶元素？
				cnt++;
			st.pop();//抛掉栈顶元素
		}

		if (cnt == 0)
			return true;
		else
			return false;
	}
};
