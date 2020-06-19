/*
*			排序算法——归并排序
*	算法伪代码描述
*		1. 如果s等于t，则排序区间只有一个记录，算法结束
*		2. 计算划分中点：m=(s+t)/2
*		3. 对前半个子序列进行升序排序
*		4. 对后半个子序列进行升序排序
*		5. 合并两个升序序列
*/

#include <math.h>
#include <stdio.h>

void Marge(int r[], int r1[], int s, int m, int t)			//合并子序列
{
	int i = s;
	int j = m + 1;
	int k = s;
	while (i <= m && j <= t)
	{
		if (r[i] <= r[j])
		{
			r1[k++] = r[i++];
		}
		else
		{
			r1[k++] = r[j++];
		}
	}
	while (i <= m)
	{
		r1[k++] = r[j++];
	}
	
}
void MargeSoft(int r[], int s, int t)
{
	int m, r1[1000];
	if (s == t)
	{
		return;
	}
	else
	{
		m = (s + t) / 2;
		MargeSoft(r, s, m);
		MargeSoft(r, m + 1, t);
		Marge(r, r1,s, m,t);
		for (int i = s; i <= t; i++)
		{
			r[i] = r1[i];
		}
	}
}


int main()
{
	int r[20] = { 5, 6, 98, 53, 5, 45, 18, 75, 15, 13, 26, 34, 53, 12, 11, 96, 67, 82, 53, 66 };
	int s = 0, t = 20;

	MargeSoft(r, s, t);
	for (int i = 0; i < t; i++)
	{
		printf("%d   ", r[i]);
	}

	return 0;
}