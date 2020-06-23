/*
* 蛮力法求解哈密顿回路
*	算法
*	1. 对顶点集合的每一个排列进行如下操作：
*		1.1 循环变量j从1~n-1执行如下操作
*			1.1.1 如果顶点vi 和 vij+1 之间不存在边，则执行步骤1，进行下一个排列
*			1.1.2 否则 i++
*	2. 输出无解信息
*/
/*
使用蛮力法求解：
1、首先规定作为起止点的顶点。由于回路是无向的，因此起止点可直接任选；
2、规定中间点的其中两点的先后次序。这步是对基本穷举的简单优化：对每对线路（每条回路都有顺时针和逆时针两
种序列表示法）来说，不同的只是线路的方向，因此，若选择任意两个中间顶点，并规定该两顶点的先后次序（比如顶
点a必须排在b前方），就可以把顶点序列的数量减半。
（这一改进后，排列的总次数仍需要(n-1)!/2次，这意味着除非问题规模很小，不然穷举查找法是不实用的）。
3、通过生成n-1个中间点的组合来得到所有的线路，计算这些线路的长度，排序求得最短线路。
*/
#include <iostream>  
#include <cstring>  
#define N 101
using namespace std;
int n, m;
int u, v;
int g[N][N];
int vis[N], appear[N];
int ans[N], num[N];
int length;

void dfs(int last, int i)//last表示上次访问的点 
{
    vis[i] = 1;//标记为已经访问过  
    appear[i] = 1;//标记为已在一张图中出现过  

    ans[length++] = i;//记录答案  
    for (int j = 1; j <= num[i]; j++)
    {
        if (g[i][j] == 1 && g[i][j] != last)//回到起点构成哈密顿环  
        {
            ans[++length] = g[i][j];//存储答案

            for (int i = 1; i <= length - 1; i++) //找到了一个环，输出ans
                cout << ans[i] << ' ';
            cout << ans[length] << endl;

            length--;//长度-1
            break;
        }
        if (!vis[g[i][j]])//遍历与i相关联的所有未访问的点。  
            dfs(i, g[i][j]);
    }
    length--;
    vis[i] = 0;//回溯
}
int main()
{
    int x;
    memset(vis, 0, sizeof(vis));
    memset(appear, 0, sizeof(appear));

    cin >> n >> m; //读入点数与边数
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v; //读入两点
        g[u][++num[v]] = v;//记录u-v的边
        g[v][++num[v]] = u;//记录v-u的边
    }

    for (x = 1; x <= n; x++) //枚举每一个点，将其作为起点来尝试访问
    {
        if (!appear[x])//如果点x不在之前曾经被访问过的图里  
        {
            length = 0;//记录答案的长度  
            dfs(0, x);
        }
    }
    return 0;
}
