#include <stdio.h>

/*
	—°‘Ò≈≈–Ú
*/

void SelectSort(int r[], int n)
{
	int i, j, index, temp;
	for ( i = 0; i < n; i++)
	{
		index = i;
		for ( j = i + 1; j < n ; j++)
		{
			if (r[j] < r[index])
			{
				index = j;
			}
		}
		if (index != i)
		{
			temp = r[i];
			r[i] = r[index];
			r[index] = temp;
		}
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
	SelectSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d   ", arr[i]);
	}
	return 0;
}