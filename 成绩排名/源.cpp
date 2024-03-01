#include <stdio.h>

void shellsort(int list[], int n) {
	int dk, i ,j, temp;
	for (dk = n / 2; dk >= 1; dk = dk / 2)
	{
		for(i= dk; i < n; i++)
		if (list[i]> list[i-dk]) {
			temp = list [i];
			for (j = i - dk; j >= 0 && temp > list[j]; j -= dk)
			{
				list[j + dk] = list[j];
			}
			list[j + dk] = temp;
		}
	}
}

void main() {
	int scorelist[1000]={ 0 };
	int n = 0;
	int m;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &scorelist[i]);
	}
	scanf_s("%d",&m);
	shellsort(scorelist,n);
	printf("%d", scorelist[m-1]);
}

