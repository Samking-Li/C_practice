/*输入一个整数 n ，求 n^n 的个位数是多少。*/

#include <stdio.h>

int fun(int n, int k)//分治法求n的k次幂
{
	if (k == 1)//1次幂为自身
	{
		return n;
	}
	else if (k == 0)//0次幂为1
	{
		return 1;
	}
	if (k % 2 == 0)
	{
		return fun(n, k / 2) * fun(n, k / 2);//n次幂==n/2次幂的平方
	}
	else
	{
		return fun(n, k / 2) * fun(n, k / 2) * n;
	}

}


void main()
{
	int n;
	scanf_s("%d", &n);
	printf("%d", fun(n, n));
}