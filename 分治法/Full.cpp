/*
*				���η�һ���򵥵����ӡ���������ת����
*	�㷨������
*	1. ���size����0�����㷨����
*	2. ���sie=1����data[begin][begin]= number,�㷨����
*	3. ��ʼ���С����±�i=j=begin;
*	4. �ظ�����������sie-1�Σ���д����A
*		4.1 data[i][j] = number,number++
*		4.2 ���±�++�����±겻��
*	5. �ظ�����������sie-1�Σ���д����B
*		4.1 data[i][j] = number,number++
*		4.2 ���±겻�䣬���±�++
*	6. �ظ���������size-1�Σ���д����C
*		6.1 data[i][j] = number,number++
*		6.2 ���±�--�����±겻��
*	7. �ظ�����������sie-1�Σ���д����D
*		4.1 data[i][j] = number,number++
*		4.2 ���±겻�䣬���±�j--
*	8. ���ú���Full����size-2�׷���������
*/

#include <stdio.h>
#define N 5 //����
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