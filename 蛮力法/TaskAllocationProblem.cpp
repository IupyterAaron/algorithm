/*
* 蛮力法解决任务成本问题
*		算法描述
*	1. 初始化最小总成本 minCost = MAx;
*	2. 对集合的每一个全排列执行如下操作：
*		2.1 初始化当前的总成本cost = 0;
*		2.2 对排列的每一个元素p,执行 cost = cost +C[i][p]
*		2.3 如果cost<minCost, 则minCost = cost;
*	3.  输出minCost
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