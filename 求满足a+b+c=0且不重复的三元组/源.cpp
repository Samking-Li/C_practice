#include <stdio.h>
#include <stdlib.h>

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
	int list[1000];
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



