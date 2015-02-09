class Solution {
public:
	long long MAX = ((int)0x7fffffff);
	long long MIN = ((int)0x80000000);

	int atoi(const char *str)
	{
		long long result = 0;
		int sign = 1;

		while (*str && *str == ' ') //move to the first number,not a ' '
			str++;

		if (*str == '+')//positive or nagtive
			str++;
		else if (*str == '-')
		{
			sign = -1;
			str++;
		}

		while (*str)
		{
			if (*str >= '0' && *str <= '9')
			{
				//(*str - '0')减去0的ASCII码，得到0-9的数字
				result = result * 10 + (*str - '0');

				//在循环内判断最大最小，而不是在循环结束后判断，是为了防止溢出
				if (result*sign >= MAX)
					return MAX;
				if (result*sign <= MIN)
					return MIN;

				str++;
			}
			else
				break;
		}

		result = result*sign;
		return result;
	}
};
