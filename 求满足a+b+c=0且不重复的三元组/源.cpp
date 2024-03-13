/*数组长度为n，范例：
输入：
10
5 -2 3 -5 0 -1 3 2 8 4
输出：
{-5,0,5}{2,-5,3}{-2,2,0}{-2,-1,3}

算法思想：数组排列后任意符合条件且不重复的三元组必然满足最小的在最前，最大的在最后的条件，并且必然对应一个中间数。
因此，只需要在每轮循环中确定一个中间数，并让大小双指针从中间数的位置出发遍历，当<0时大指针右移，>0时小指针左移，就可找到符合条件的的组合。
并且，若一个中间数对应着两个三元组时，例如{-5 -3 0 3 5}中以0为中间数，必然是先找到{-3 0 3}，
此时只需将小（大）指针向左（右）移动一位打破条件，算法就会继续往后寻找直至找出满足条件的{-5 0 5}
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int move(int A[], int low, int high)
{
	int pivot = A[low];
	while (low < high && A[high] >= pivot)
	{
		high--;
	}
	A[low] = A[high];
	while (low < high && A[low] <= pivot)
	{
		low++;
	}
	A[high] = A[low];
	A[low] = pivot;
	return low;
}

void quicksort(int A[], int low, int high)
{
	if (low < high)
	{
		int pivotpos = move(A, low, high);
		quicksort(A, low, pivotpos - 1);
		quicksort(A, pivotpos + 1, high);
	}
}

void find(int list[], int mid, int n)
{
	int low = mid - 1;
	int high = mid + 1;
	while (low >= 0 && high < n)
	{
		if ((list[low] + list[mid] + list[high]) == 0)
		{
			printf("{%d,%d,%d}", list[low], list[mid], list[high]);
			low=low - 1;
			while (list[low] == list[low + 1])
			{
				low--;
			}
			high = high + 1;
			while (list[high] == list[high - 1])
			{
				high++;
			}
		}
		while ((list[low] + list[mid] + list[high]) < 0)
		{
			high++;
		}
		while ((list[low] + list[mid] + list[high]) > 0)
		{
			low--;
		}
	}
	if (mid > 1)
	{
		mid = mid - 1;
		while (list[mid] == list[mid + 1])
		{
			mid--;
		}
		find(list, mid, n);
	}
}

void main()
{
	int i;
	int list[MAX];
	int n;
	int low, high, mid;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &list[i]);
	}
	quicksort(list, 0, (n - 1));
	find(list, (n - 2), n);
}



