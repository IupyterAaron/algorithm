#include <string>
#include <stdio.h>

/*
* 串匹配问题——BF算法
* BF算法的伪代码描述
*	输入 主串S，模式T
*	输出T在S中的位置
*	1.初始化主串比较开始的位置 index=0
*	2.在串S和串T中设置比较起始的下标i=0，j=0
*   3.重复下列操作，知道S或T的字符均比较完毕
*		3.1如果S[i]==T[j]，则继续比较S和T中的下一对字符
*		3.2否则，下一趟匹配的开始位置index++，回溯下标i = index, j = 0;
*	4.如果T中所有字符比较完毕，则返回匹配开始的位置index；否则返回0
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