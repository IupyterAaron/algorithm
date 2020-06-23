/*
* �������������ɱ�����
*		�㷨����
*	1. ��ʼ����С�ܳɱ� minCost = MAx;
*	2. �Լ��ϵ�ÿһ��ȫ����ִ�����²�����
*		2.1 ��ʼ����ǰ���ܳɱ�cost = 0;
*		2.2 �����е�ÿһ��Ԫ��p,ִ�� cost = cost +C[i][p]
*		2.3 ���cost<minCost, ��minCost = cost;
*	3.  ���minCost
*/

#include <iostream>
#include <cstring>

using namespace std;

int visit[11], num[11];
int n, value = 9999999;
int martrix[4][4];

void findLowValue()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += martrix[i - 1][num[i] - 1];
    }
    if (sum < value)
    {
        value = sum;
    }
}

void dfs(int length)
{
    if (length > n)
    {
        findLowValue();
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (visit[i] == 0)
            {
                visit[i] = 1;
                num[length] = i;
                dfs(length + 1);
                visit[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> n;
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> martrix[i][j];
        }
    }
    dfs(1);
    cout << "minValue:" << value;
    return 0;
}