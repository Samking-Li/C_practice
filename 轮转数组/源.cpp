/*����һ���������� nums���������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����
�㷨˼�룺����������ʵ�з�ת��������ԭ��������Ҫ��ת�������飬�ͻ��ܵ�������ǰ�档��ʱ�򣬴� k ���ָ����飬���������飬���Խ��з�ת���ɡ�

���룺
5
3
1 2 3 4 5

�����
3 4 5 1 2
*/

#include <stdio.h>
#define MAX 1000

void rev(int* nums,int start, int stop)
{
	int temp;
	while (start < stop)
	{
		temp = nums[start];
		nums[start] = nums[stop];
		nums[stop] = temp;
		start++;
		stop--;
	}
}

void rotate(int* nums, int numsSize, int k) {
	int i;
	int temp;
	rev(nums, 0, numsSize - 1);
	rev(nums, 0, k-1);
	rev(nums, k, numsSize - 1);
}


void main()
{
	int nums[MAX]={0};
	int i;
	int n, k;
	scanf_s("%d", &n);
	scanf_s("%d", &k);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &nums[i]);
	}
	rotate(nums, n, k);
	for (i = 0; i < n; i++)
	{
		printf("%d", nums[i]);
	}
}