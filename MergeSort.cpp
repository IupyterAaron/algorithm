/*
*			�����㷨�����鲢����
*	�㷨α��������
*		1. ���s����t������������ֻ��һ����¼���㷨����
*		2. ���㻮���е㣺m=(s+t)/2
*		3. ��ǰ��������н�����������
*		4. �Ժ��������н�����������
*		5. �ϲ�������������
*/

#include <math.h>
#include <stdio.h>

void Marge(int r[], int r1[], int s, int m, int t)			//�ϲ�������
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