#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <malloc.h>

#define ALPHABET_SIZE 26

int find_subsequence(int *sequence, int n);

int main(void)
{
	int n;
	int *sequence;
	int res;

	scanf("%d", &n);
	sequence =  malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i)
		scanf("%d", &sequence[i]);

	res = find_subsequence(sequence, n);

	if (res != INT_MAX)
		printf("%d\n", res);
	else
		printf("NONE\n");

	free(sequence);

	return 0;
}

int find_subsequence(int *sequence, int n)
{
	int array_alphabet[ALPHABET_SIZE] = {0};
	int count = 0;
	int left = 0;
	int len = INT_MAX;

	for (int right = 0; right < n; ++right) {
		array_alphabet[sequence[right] - 1]++;

		if (array_alphabet[sequence[right] - 1] == 1)
			count++;

		while (count == ALPHABET_SIZE) {
			if (right - left + 1 < len)
				len = right - left + 1;

			if (array_alphabet[sequence[left] - 1] == 1)
				count--;

			array_alphabet[sequence[left] - 1]--;

			left++;
		}
	}

	return len;
}
