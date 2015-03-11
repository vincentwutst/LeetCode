class Solution {
public:
	int reverse(int x) {
		long long res = 0;//long long 防溢出
		for (; x; x /= 10)
			res = res * 10 + x % 10;
		if (res <= INT_MAX && res >= INT_MIN)//防止溢出
			return res;
		else
			return 0;
	}
};
