/*有两个按非递减顺序排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
nums1 长度为 m+n ， num2 长度为 n。将 nums2 合并入 nums1 中并使合并后的 nums1 保持非递减顺序序列。*/
#include <stdio.h>
#define MAX 1000

void merge(int* nums1, int* nums2, int m, int n)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int temp[MAX] = { 0 };
	for (k = 0; k < (m + n); k++)
	{
		if (i == m)
		{
			temp[k] = nums2[j];
			j++;
			continue;
		}
		else if (j == n)
		{
			temp[k] = nums1[i];
			i++;
			continue;
		}
		else if (nums1[i] < nums2[j] && i < m)
		{
			temp[k] = nums1[i];
			i++;
		}
		else if (nums2[j] <= nums1[i] && j < n)
		{
			temp[k] = nums2[j];
			j++;
		}
	}
	for (i = 0; i < (m + n); i++)
	{
		nums1[i] = temp[i];
	}
}

bool main()
{
	int m, n;
	int i;
	int nums1[MAX] = { 0 };
	int nums2[MAX] = { 0 };
	scanf_s("%d", &m);
	scanf_s("%d", &n);
	for (i = 0; i < m;i++)
	{
		scanf_s("%d", &nums1[i]);
	}
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &nums2[i]);
	}
	merge(nums1, nums2, m, n);

	for (i = 0; i < (m + n); i++)
	{
		printf("%d", nums1[i]);
	}
	return true;
}