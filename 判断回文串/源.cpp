#include <stdio.h>
#include<string.h>

void main()
{
	char ch[1000];
	gets_s(ch);
	int i, j;
	i = 0; j = strlen(ch)-1;
	while (i < j)
	{
		i++;
		j--;
		if (ch[i]!=ch[j])
		{
			printf("No!");
			return ;
		}
	}
	printf("Yes!");
	return;
}