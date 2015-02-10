class Solution {
public:
	double pow(double x, int n) {
		double result;
		bool nagtive = false;
		if (n < 0)
		{
			nagtive = true;
			n *= -1;
		}

		if (n == 0)
			return 1;

		double v = pow(x, n / 2);
		if (n % 2 != 0)
			result = v * v * x;
		else
			result = v *v;

		if (nagtive)
			result = 1 / result;

		return result;
	}
};
