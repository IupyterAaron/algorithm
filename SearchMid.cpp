/**
*		�������е���λ��
*
��1������������е���λ��a��b��
��2���Ƚ�a��b�����������������
2.1 �� a == b ���a��b,�㷨������
2.2 �� a < b ����λ����a~b֮�䣬��������A��a֮ǰ�����õ�����A1������B��b֮������õ�����B1��
2.3 �� a>b ����λ����b~a֮�䣬��������A��a֮������õ�����A1������B��b֮ǰ�����õ�����B1��
ע�⣺
����������һ��Ҫ��֤���������е�Ԫ�ظ�����ȣ�����������������ĳ�������ȴﵽ����һ��Ԫ�ص�����������������ϸ˼����
*
*/

#include <stdio.h>

int SearchMid(int A[], int B[], int n)
{
	int s1 = 0;
	int e1 = n - 1 ;
	int s2 = 0;
	int e2 = n - 1;
	int mid1, mid2;
	while (s1<e1 && s2<e2)
	{
		mid1 = (s1 + e1) / 2;
		mid2 = (s2 + e2) / 2;
		if (A[mid1] == B[mid2])
			return A[mid1];
		if (A[mid1] < B[mid2])
		{
			if ((s1 + e1) % 2 == 0)
			{
				s1 = mid1;
			}
			else
			{
				s1 = mid1 + 1;
			}
			e2 = mid2;
		}
		else
		{
			if ((s2 + e2) % 2 == 0)
			{
				s2 = mid2;
			}
			else
			{
				s2 = mid2 + 1;
			}
			e1 = mid1;
		}
	}
	if (A[s1] < B[s2])
	{
		return A[s1];
	}
	else
	{
		return B[s2];
	}
}

int main() {
	int n = 7;
	int A[7] = { 1,5,8,9,12,34,36};
	int B[7] = { 2,6,9,11,21,36,40 };
	int a = 0;
	a = SearchMid(A, B, n);
	printf("%d", a);
	return 0;
}