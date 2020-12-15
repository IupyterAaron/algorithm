/*
*		组合问题——求最大子段和
*/


#include<stdio.h>
int MaxSum(int a[], int left, int right)
{
	int sum = 0, midSum = 0, leftSum = 0, rightSum = 0;
	int center, s1, s2, lefts, rights;
	if (left == right)
	{
		sum = a[left];
	}
	else
	{
		center = (left + right) / 2;
		leftSum = MaxSum(a, left, center);
		rightSum = MaxSum(a, center + 1, right);
		s1 = 0;
		lefts = 0;
		for (int i = center; i >= left; i--)
		{
			lefts += a[i];
			if (lefts > s1)
			{
				s1 = lefts;
			}
		}
		s2 = 0;
		rights = 0;
		for (int j = center + 1; j <= right; j++)
		{
			rights += a[j];
			if (lefts > s2)
			{
				s2 = rights;
			}
		}
		midSum = s1 + s2;
		if (midSum < leftSum)
		{
			sum = leftSum;
		}
		else
		{
			sum = midSum;
		}
		if (midSum < rightSum)
		{
			sum = rightSum;
		}
		else
		{
			sum = midSum;
		}
	}
	return sum;
}


int main()
{
	int a[20] = { 5,-9,35,-25,4,9,15,-68,26,3,-5,-16,9,48,56,42,-63,2,8,16 };
	int sum = 0;
	sum = MaxSum(a, 0, 20);
	printf("%d", sum);
	return 0;
}