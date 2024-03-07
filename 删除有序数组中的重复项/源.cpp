/*双指针法移除有序数组中重复项，并输出新数组长度*/
#define MAX 1000
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int slow = 1, fast = 1;
    while (fast < numsSize)
    {
        if (nums[fast] != nums[fast - 1])
        {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}

void main()
{
    int nums[MAX];
    int n;
    int i;
    scanf_s("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf_s("%d", &nums[i]);
    }
    n = removeDuplicates(nums, n);
    printf("%d\n", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
}