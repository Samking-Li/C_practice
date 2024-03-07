/*不采用额外内存空间，移除值=var的元素并保持数组其它元素顺序不变*/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int fast = 1, slow = 1;
    while (fast<numsSize)
    {
        if (nums[fast] != val)
        {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}

void main()
{
    int i;
    int nums[5] = {1,3,2,4,2};
    int numsize = removeElement(nums, 5, 2);
    for ( i = 0; i < numsize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n%d", numsize);
}