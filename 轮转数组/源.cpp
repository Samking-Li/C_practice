/*给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
算法思想：对整个数组实行翻转，这样子原数组中需要翻转的子数组，就会跑到数组最前面。这时候，从 k 处分隔数组，左右两数组，各自进行翻转即可。

输入：
5
3
1 2 3 4 5

输出：
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