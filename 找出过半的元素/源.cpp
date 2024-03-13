/*Ħ��ͶƱ������Ϊ����Ԫ������������ֵĴ������Դ���n/2�������ò�ͬԪ����ȥ��ͬԪ�أ�ʣ�µı�Ȼ����ͬԪ��
���룺
10
1 1 2 0 1 1 2 2 1 1 
�����
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
			if (count < 0) {    //��Ʊ��С��0��˵����Ԫ�ز��Ǻ�ѡԪ��
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
