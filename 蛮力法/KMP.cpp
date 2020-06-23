
/*
* 串的模式匹配算法——KMP算法
* 输入 主串S，模式T
* 输出 T在S的位置
* 伪代码描述
*	在串S和串T中分别设置比较的起始下标 i = 0, j = 0
*	重复下列操作，直到S或T的所有字符均比较完毕
*		如果S[i]==T[j]，则继续比较S和T的下一堆字符
*		否则，将下标j回溯到next[j]的位置，即j=next[j]
*		如果j等于-1，则将下标i和j分别加1，准备下一趟比较
*	如果T中所有字符均比较完毕，则返回本地匹配的开始位置，否则返回0
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void kmpMatch(char* s, int sLength, char* p, int pLength, int* prefix)
{
    int pPoint = 0;
    for (int i = 0; i <= sLength - pLength; i++)
    {


        while (pPoint != 0 && (s[i] != p[pPoint]))
        {
            pPoint = prefix[pPoint - 1];
        }
        if (s[i] == p[pPoint])
        {
            pPoint++;
            if (pPoint == pLength)
            {
                printf("找到:%d \n", i - pPoint + 1);
                //pPoint = 0;//上一个在s匹配的字符串,不能成为下一个匹配字符串的一部分
                pPoint = prefix[pPoint - 1];//上一个在s匹配的字符串,也能成为下一个匹配字符串的一部分
            }
        }


    }
}

void kmpPrefixFunction(char* p, int length, int* prefix)
{
    prefix[0] = 0;
    int k = 0;//前缀的长度
    for (int i = 1; i < length; i++)
    {
        while (k > 0 && p[k] != p[i])
        {
            k = prefix[k - 1];
        }
        if (p[k] == p[i])//说明p[0...k-1]共k个都匹配了
        {
            k = k + 1;
        }
        prefix[i] = k;
    }
}


//匹配函数的朴素算法,用于比较
void normal_match(char* s, int sLength, char* p, int pLength) {
    int k;
    for (int i = 0; i < sLength - pLength + 1; i++) {
        for (k = 0; k < pLength; k++) {
            if (s[i + k] != p[k]) {
                break;
            }
        }
        if (k == pLength) {
            printf("找到:%d \n", i);
        }

    }
}


int main()
{
    char s[] = "ababacababababababbaabbababaabaababacabababababbcababbabababcababba";
    char p[] = "ababacab";
    int pLength = strlen(p);
    int* prefix = (int*)malloc(pLength * sizeof(int));
    kmpPrefixFunction(p, pLength, prefix);
    printf("字符串的最长前缀长度分别是:");
    for (int i = 0; i < pLength; i++)
    {
        printf("%d\t", prefix[i]);
    }
    printf("\n使用KMP匹配\n");
    kmpMatch(s, strlen(s), p, pLength, prefix);

    printf("使用朴素算法:\n");
    normal_match(s, strlen(s), p, pLength);

    return 0;
}