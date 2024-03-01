#include <stdio.h>

void main()
{
	char ch[1000];
	gets_s(ch);
	int i;
	for (i = 0; ch[i] != '\0'; i++)
	{
	}
	if (i % 2 == 0)
	{
		int j = i / 2 - 1;
		int k = j + 1;
		while (ch[j] == ch[k])
		{
			if (j != 0)
			{
				j--; k++;
			}
			else
			{
				printf("yes!");
				return ;
			}
		}
		printf("no!");
	}
	else
	{
		int j = i / 2 - 1;
		int k = j + 2;
		while (ch[j] == ch[k])
		{
			if (j != 0)
			{
				j--; k++;
			}
			else
			{
				printf("yes!");
				return ;
			}
		}
		printf("no!");
	}
}