/*����һ������ n ���� n^n �ĸ�λ���Ƕ��١�*/

#include <stdio.h>

int fun(int n, int k)//���η���n��k����
{
	if (k == 1)//1����Ϊ����
	{
		return n;
	}
	else if (k == 0)//0����Ϊ1
	{
		return 1;
	}
	if (k % 2 == 0)
	{
		return fun(n, k / 2) * fun(n, k / 2);//n����==n/2���ݵ�ƽ��
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