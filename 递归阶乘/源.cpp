#include<stdio.h>

int fun(int n) 
{
	int result;
	if (n > 1)
	{
		result = n * fun(n - 1);
		return result;
	}
	else if(n == 1)
	{
		return 1;
	}
}

void main()
{
	int n;
	scanf_s("%d", &n);
	printf("%d", fun(n));
}