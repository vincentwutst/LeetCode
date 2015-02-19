class Solution {
public:
	string addBinary(string a, string b)
	{
		string result;
		bool carry = false;
		int na = a.size();
		int nb = b.size();
		int max = (na >= nb) ? na : nb;
		
		//给小的前面补0
		if (na > nb)
			for (int i = 0; i < na - nb; i++)
				b.insert(b.begin(), '0');
		else if (na < nb)
			for (int i = 0; i < nb - na; i++)
				a.insert(a.begin(), '0');

		for (int i = max - 1; i >= 0; i--)
		{
			int tmp;
			if (carry)
				tmp = (a[i] - '0') + (b[i] - '0') + 1;//有进位
			else
				tmp = (a[i] - '0') + (b[i] - '0');//无进位

			if (tmp == 0)//'0'+'0'
			{
				result.insert(result.begin(), '0');
				carry = false;
			}
			else if (tmp == 1)//'1'+'0' or '0'+'1'
			{
				result.insert(result.begin(), '1');
				carry = false;
			}
			else if (tmp == 2)//'1'+'1'
			{
				result.insert(result.begin(), '0');
				carry = true;
			}
			else if (tmp == 3)//'1'+'1'+进位
			{
				result.insert(result.begin(), '1');
				carry = true;
			}
		}

		if (carry)//添加首位的进位
			result.insert(result.begin(), '1');
		return result;
	}
};
