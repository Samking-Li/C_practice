#include <stdio.h>

bool fun(char *list)
{
	char *p = list;
	int a1 = 0; 
	int a2 = 0; 
	int a3 = 0;
	while (*p)
	{
		switch (*p)
		{
		case '(':
			a1++;
			break;
		case '[':
			a2++;
			break;
		case '{':
			a3++;
			break;
		case ')':
			a1--;
			if (a1 < 0)
			{
				return false;
			}
			break;
		case ']':
			a2--;
			if (a2 < 0)
			{
				return false;
			}
			break;
		case '}':
			a3--;
			if (a3 < 0)
			{
				return false;
			}
			break;
		default:;
		}
		*p++;
	}
	if (a1==a2==a3==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}



void main() {
	char str[256] = { '0' };
	int i = 0;
	char ch;
	while ((ch = getchar()) != '\n')
	{
		str[i] = ch;
		i++;
	}
	str[i] = '\0';
	if (fun(str))
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
}