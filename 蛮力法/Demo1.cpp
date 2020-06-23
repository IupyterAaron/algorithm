/**
百元买百鸡问题
*/
#include <stdio.h>

void Chicken()
{
	int x, y, z;
	int count = 0;
	for (x = 0; x <= 20; x++)
	{
		for (y = 0; y <= 33; y++)
		{
			z = 100 - x - y;
			if ((z % 3 == 0) && (5 * x + 3 * y + z / 3 == 100))
			{
				count++;
				printf("公鸡：%d  母鸡：%d  小鸡：%d  \n", x, y, z);
			}
		}
	}
	if (count == 0) {
		printf("方案无解");
	}
	else
	{
		printf("共有%d种解决方法", count);
	}
}

int main()
{
	Chicken();
	return 0;
}