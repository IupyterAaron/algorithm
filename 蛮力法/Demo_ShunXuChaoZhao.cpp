#include <stdio.h>
/*
* 蛮力法——顺序查找
* 时间复杂度O(n)
*/
int SeqSearch1(int r[], int n, int k)
{
	int i = n;
	while (i > 0 && r[i] != k)
	{
		i--;
	}
	return i;
}

int SeqSearch2(int r[], int n, int k)
{
	int i = n;		//从数组高端开始寻找
	r[0] = k;		//设置岗哨
	while (r[i] != k)
		i--;
	return i;
}

int main()
{
	int n = 10;

	int arr[10] = { 0,5,56,88,55,24,81,1,36,22 };

	int a1 = SeqSearch1(arr, 10, 56);
	int a2 = SeqSearch2(arr, 10, 56);

	printf("%d,%d", a1, a2);

	return 0;
}