/*
*		分治法——快速排序
*	划分
*	求解子问题
*	合并
*
*/

#include <stdio.h>

int r[20] = { 12,58,32,47,59,66,32,47,82,1,23,35,38,49,16,32,28,75,42,19 };

int Partition(int r[], int first, int end)
{
	int i = first;
	int j = end;
	while (i<j)
	{
		while (i < j && r[i] < r[j])
		{
			j--;
		}
		if (i<j)
		{
			int temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			i++;
		}
		while (i < j && r[i] <= r[j])
		{
			i++;
		}
		if (i < j)
		{
			int temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			j--;
		}
	}
	return i;
}

void QuickSort(int r[], int first, int end)
{
	int pivot;
	if (first < end)
	{
		pivot = Partition(r, first, end);
		QuickSort(r, first, pivot-1);
		QuickSort(r, pivot + 1, end);

	}
}

int main()
{
	QuickSort(r, 0, 20);
	for (int i = 0; i < 20; i++)
	{
		printf("%d   ", r[i]);
	}

	return 0;

}