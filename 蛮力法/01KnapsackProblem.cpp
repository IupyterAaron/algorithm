
/**
*	蛮力法求解0/1背包问题
*伪代码描述
*	1. 初始化最大值maxValue = 0; 结果子集S = Ø;
*   2. 对集合{1， 2， ... , n}的每一个子集T，执行下述操作：
*		2.1 初始化背包的价值 value = 0; 背包重量 weight = 0;
*		2.2 对子集T的每一个元素j：
*			2.2.1 如果 weight + wj < C, 则 weight = weight + Wj; value = value + vj;
*			2.2.2 否则，转步骤2，考察下一个子集
*		2.3 如果maxValue<value,则maxValue = value; S=T;
*	3. 输出子集S中的各元素
*/

#include <stdio.h>
#include <math.h>

int c;		//背包容量
int bag_values = 0;		//背包价值
int goods_num;			//货物数量
int maxValue = -1;		//定义最大价值
int calc_arrangement(); //一个函数

struct things
{
	int weight;
	int value;
	int innerIndex[10] = { 0 };		//统计货物的下标
}goods[1001];

/*直接计算所有货物的全排列*/
int calc_arrangement()
{
	int head = 1;
	int tail = goods_num + 1;
	//tail指向的是最后一个元素 的 后一位

	while (head <= goods_num)
	{
		for (int i = head + 1; i < tail - 1; i++)
		{
			if (goods[i].innerIndex[head] != 1)  //就是说这个要与head的相加值的 其获得时候 并没有head的值参与其中
			{
				goods[tail].value = goods[head].value + goods[i].value;
				goods[tail].weight = goods[head].weight + goods[i].weight;
				for (int temp = 0; temp < goods_num; temp++)
				{
					goods[tail].innerIndex[temp] = goods[i].innerIndex[temp];
				}
				goods[tail].innerIndex[head] = 1;
				tail++;
			}
			else
			{
				continue;
			}
		}
		head++;
	}
	int index = -1;
	//用来记录我所取得的value最大的下标 
	for (int j = tail - 1; j > 0; j--)
	{
		if (goods[j].weight <= c)
		{
			if (goods[j].value > maxValue)
			{
				maxValue = goods[j].value;
				index = j;
			}
		}
		else
			continue;
	}
	return index;
}
int main()
{
	printf("请输入背包的容量");
	scanf("%d", &c);
	printf("请输入货物的数量");
	scanf("%d", &goods_num);
	printf("请输入每个货物的重量以及对应的价格：");
	for (int i = 1; i <= goods_num; i++)
	{
		scanf("%d", &goods[i].weight);
		scanf("%d", &goods->value);

		goods[i].innerIndex[i] = 1;
	}
	int index = calc_arrangement();
	printf("总价值为%d", maxValue);

	for (int i = 1; i <= 4; i++)
	{
		if (goods[index].innerIndex[i] != 0)
		{
			printf("选中物品的重量为%d， 它的价值为%d", goods[i].weight, goods[i].weight);
		}
	}
	return 0;
}

