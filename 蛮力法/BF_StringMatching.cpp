#include <string>
#include <stdio.h>

/*
* ��ƥ�����⡪��BF�㷨
* BF�㷨��α��������
*	���� ����S��ģʽT
*	���T��S�е�λ��
*	1.��ʼ�������ȽϿ�ʼ��λ�� index=0
*	2.�ڴ�S�ʹ�T�����ñȽ���ʼ���±�i=0��j=0
*   3.�ظ����в�����֪��S��T���ַ����Ƚ����
*		3.1���S[i]==T[j]��������Ƚ�S��T�е���һ���ַ�
*		3.2������һ��ƥ��Ŀ�ʼλ��index++�������±�i = index, j = 0;
*	4.���T�������ַ��Ƚ���ϣ��򷵻�ƥ�俪ʼ��λ��index�����򷵻�0
*/

int Bf(char S[], char T[])
{
	int index = 0;
	int i = 0, j = 0;
	while ((S[i] != '\0') && (T[j] != '/0'))
	{
		if (S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			index++;
			i = index;
			j = 0;
		}
	}
	if (T[j] == '\0')
	{
		return index + 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	char S[] = "abcabcacb";
	char T[] = "abc";
	int a = 0;
	a = Bf(S, T);
	printf("%d", a);
	return 0;
}