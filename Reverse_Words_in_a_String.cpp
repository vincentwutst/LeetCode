class Solution {
public:
	void reverseWords(string &s) {
		string ret;
		int j = s.size();//记录词的尾部
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == ' ')
				j = i;
			else if (i == 0 || s[i - 1] == ' ') {
				if (!ret.empty()) ret.append(" ");//词之间添加一个空格
				ret.append(s.substr(i, j - i));
			}
		}
		s = ret;
	}
};
