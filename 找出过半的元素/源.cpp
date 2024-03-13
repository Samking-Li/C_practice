/*摩尔投票法：因为多数元素在数组里出现的次数绝对大于n/2，所以用不同元素消去相同元素，剩下的必然是相同元素
输入：
10
1 1 2 0 1 1 2 2 1 1 
输出：
1
*/


#include <stdio.h>
#define MAX 1000

int majorityElement(int* nums, int numsSize) {
	int candi = nums[0];
	int count = 1;
	int i;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == candi)
		{
			count++;
		}
		else
		{
			count--;
			if (count < 0) {    //若票数小于0，说明该元素不是候选元素
				candi = nums[i];
				count = 1;
			}
		}
	}
	return candi;
}


void main()
{
	int n;
	int i;
	int nums[MAX];
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &nums[i]);
	}
	printf("%d", majorityElement(nums, n));
}
