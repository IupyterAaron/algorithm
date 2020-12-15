/**
*		讲个序列的中位数
*
（1）求出两个序列的中位数a和b；
（2）比较a和b，有下面三种情况；
2.1 ： a == b 输出a或b,算法结束；
2.2 ： a < b 则中位数在a~b之间，所以舍弃A中a之前的数得到序列A1，舍弃B中b之后的数得到序列B1。
2.3 ： a>b 则中位数在b~a之间，所以舍弃A中a之后的数得到序列A1，舍弃B中b之前的数得到序列B1。
注意：
在求解过程中一定要保证两个序列中的元素个数相等！！！！。避免其中某个序列先达到中有一个元素的情况。下面代码请仔细思考。
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