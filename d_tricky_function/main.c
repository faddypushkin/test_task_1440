#include <stdio.h>
#include <stdbool.h>

int f(int n);

float g(int n);

int main(void)
{
	float number[10] = {0};
	bool flag;
	int count = 0;
	float res = -1;

	for (int i = 2; i < 10000001; ++i) {
		res = g(i);
		flag = true;

		for (int j = 0; j < 10; ++j)
			if (res == number[j]) {
				flag = false;
				break;
			}

		if (!flag)
			continue;

		count++;
		number[count] = res;
		printf("%.7f\n", res);
	}

	return 0;
}

int f(int n)
{
	int res = 0;
	int temp;

	while (n) {
		temp = n % 10;
		n /= 10;

		res *= 10;
		res += temp;
	}

	return res;
}

float g(int n)
{
	return (float) f(f(n)) / n;
}
