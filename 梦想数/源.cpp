/*采用“超时”判断，即循环次数超过指定次数时，认为是死循环，即非梦想数*/
#include <stdio.h>


bool isdreamnum(int n)
{
	int limit = 100000;
	int i = 1;
	while (n != 1 && i < limit)
	{
		int result = 0;
		while (n != 0)
		{
			result += (n % 10) * (n % 10);
			n = n / 10;
		}
		n = result;
		i++;
	}
	if (n == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void main()
{
	int n = 0;
	printf("输入：");
	scanf_s("%d",&n);
	if (isdreamnum(n))
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
}