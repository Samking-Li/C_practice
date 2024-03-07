/*�����ö����ڴ�ռ䣬�Ƴ�ֵ=var��Ԫ�ز�������������Ԫ��˳�򲻱�*/

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