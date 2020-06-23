#include <stdio.h>

void bubbleSort(int* arr, int n)
{
	int m, i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (arr[j] > arr[j + 1])
			{
				m = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = m;
			}
}

int main()
{
	int n = 10;
	int arr[10];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	bubbleSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d    ", arr[i]);
	}
}