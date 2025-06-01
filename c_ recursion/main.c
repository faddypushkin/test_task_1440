#include <stdio.h>

int f(int n);

int main(void)
{
	int num;
	int step = 0;
	int a[10] = {0};

	for (int i = 0; i < 14; i++) {
		num = f(i);

		if (num % 2 == 1) {
			a[step] = num;
			step++;
		}
	}

	for (int i = 0; i < 10; i++)
		printf("A[%d] = %d\n", i, a[i]);
	
	return 0;
}

int f(int n)
{
	if (n == 0)
		return 1;

	if (n == 1)
		return 3;

	return 5 * f(n - 1) + f(n - 2);
}
