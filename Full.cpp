/*
*				分治法一个简单的例子——数字旋转方阵
*	算法描述：
*	1. 如果size等于0，则算法结束
*	2. 如果sie=1，则data[begin][begin]= number,算法结束
*	3. 初始化行、列下标i=j=begin;
*	4. 重复下下述操作sie-1次，填写区域A
*		4.1 data[i][j] = number,number++
*		4.2 行下标++，列下标不变
*	5. 重复下下述操作sie-1次，填写区域B
*		4.1 data[i][j] = number,number++
*		4.2 行下标不变，列下标++
*	6. 重复下述操作size-1次，填写区域C
*		6.1 data[i][j] = number,number++
*		6.2 行下标--，列下标不变
*	7. 重复下下述操作sie-1次，填写区域D
*		4.1 data[i][j] = number,number++
*		4.2 行下标不变，列下标j--
*	8. 调用函数Full，在size-2阶方阵中填数
*/

#include <stdio.h>
#define N 5 //阶数
int main(void)
{
	int a[N][N];
	int i, j, m, t;
	t = 1;
	for (m = 1; m <= (N + 1) / 2; m++)
	{
		i = m - 1;
		for (j = m - 1; j < (N - m); j++)
			a[i][j] = t++;
		for (i = m - 1; i < (N - m); i++)
			a[i][j] = t++;
		for (j = N - m; j > m - 1; j--)
			a[i][j] = t++;
		for (i = N - m; i > m - 1; i--)
			a[i][j] = t++;
	}
	if (N % 2 == 1) a[N / 2][N / 2] = t;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
	getchar();
}