/**
��Ԫ��ټ�����
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
				printf("������%d  ĸ����%d  С����%d  \n", x, y, z);
			}
		}
	}
	if (count == 0) {
		printf("�����޽�");
	}
	else
	{
		printf("����%d�ֽ������", count);
	}
}

int main()
{
	Chicken();
	return 0;
}