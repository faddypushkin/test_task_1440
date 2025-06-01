#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct {
	int left;
	int right;
} segment;

int compare(const void *segment1, const void *segment2);

int count_points(segment *arr_segments, int n);

int main(void)
{
	int n;
	segment *arr_segments;
	int res;

	scanf("%d", &n);
	arr_segments =  malloc(n * sizeof(segment));
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr_segments[i].left, &arr_segments[i].right);

	res = count_points(arr_segments, n);

	printf("%d\n", res);

	free(arr_segments);

	return 0;
}

int compare(const void *val1, const void *val2)
{
	segment *segment1 = (segment *) val1;
	segment *segment2 = (segment *) val2;

	return segment1->right - segment2->right;
}

int count_points(segment *array, int n)
{
	int res = 0;
	int point = -1;

	qsort(array, n, sizeof(segment), compare);

	for (int i = 0; i < 200; i++)
		if ((point < array[i].left) || (point > array[i].right)) {
			res++;
			point = array[i].right;
		}

	return res;
}
