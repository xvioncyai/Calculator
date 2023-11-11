#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int swap(char* a, char* b, int* alen, int* blen)
{
	char cn[100] = { '\0' };
	int c = *alen;
	*alen = *blen;
	*blen = c;
	strcpy(cn, a);
	strcpy(a, b);
	strcpy(b, cn);
	return 0;
}

int sum(char* a, char* b, char* c, int alen, int blen, int* carry)
{
	int sum = 0;
	for (; blen >= 0; alen--, blen--)
	{
		sum = (a[alen] - '0') + (b[blen] - '0') + *carry;
		*carry = sum / 10;
		c[alen] = (sum % 10) + '0';
	}
	for (; alen >= 0; alen--)
	{
		sum = (a[alen] - '0') + *carry;
		*carry = sum / 10;
		c[alen] = (sum % 10) + '0';
	}
	return 0;
}

int main()
{
	char a[100] = { '\0' }, b[100] = { '\0' }, c[101] = { '\0' }, cn[100] = { '\0' };
	char ch;
	scanf("%s %c %s", a, &ch, b);
	int alen = strlen(a) - 1;
	int* al = &alen;
	int blen = strlen(b) - 1;
	int* bl = &blen;
	int carry = 0;
	int* x = &carry;

	if (ch == '+')
	{

		if (blen > alen)
		{
			swap(a, b, al, bl);
		}
		sum(a, b, c, alen, blen, x);
		if (*x == 1)
			printf("%d", 1);
		printf("%s", c);
	}
	else if (ch == '-')
	{
		char m[100] = { '\0' };
		int flag = 0, t = blen, k = alen;
		if (blen > alen)
		{
			flag = 1;
			swap(a, b, al, bl);
			t = blen, k = alen;
		}
		else if (alen == blen)
		{
			int j = 0;
			while (j <= alen)
			{
				if (b[j] > a[j]) {
					flag = 1;
					swap(a, b, al, bl);
					t = blen, k = alen;
					break;
				}
				else if (a[j] > b[j])
					break;
				j++;
			}
		}

		for (; blen >= 0; blen--, alen--)
		{
			m[alen] = '9' - b[blen] + '0';
		}
		for (; alen >= 0; alen--)
		{
			m[alen] = '9';
		}
		blen = t, alen = k;
		while (m[k] == '9')
		{
			m[k] = '0';
			k--;
			if (k == 0)
				break;
		}
		m[k] += 1;
		sum(a, m, c, alen, alen, x);
		if (flag == 1)
			printf("%c", '-');
		int count = 0;
		while (1)
		{
			if (c[count] != '0')
				break;
			else if (count == alen)
				break;
			else
				count++;
		}
		for (; count <= alen; count++)
			printf("%c", c[count]);
	}

	return 0;
}