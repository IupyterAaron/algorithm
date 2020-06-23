/*
*		������������������
*/

#include <stdio.h>

int ClosestPoints(int x[], int y[], int n)
{
	int index1, index2;		//��¼����Ե��±�
	int d, minDist = 1000;	//���������벻���� 1000
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			if (d < minDist)
			{
				minDist = d;
				index1 = i; 
				index2 = j;
			}
		}
	}
	printf("����ĵ����(%d, %d)", index1, index2);
	return minDist;
}

int main()
{
	int n = 10;
	int x[10] = {55, 96, 45, 68, 73, 82, 95, 55, 99, 96};
	int y[10] = {22, 38, 2, 1, 58, 63, 71, 54, 96, 20};
	int d = ClosestPoints(x, y, n);
	printf("��̾���Ϊ%d", d);
	return 0;
}