#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		return 0;
	}
	char *str = argv[1];
	int len = strlen(str);
	int i, j, word_count = 1;
	char word[len];
	
	for (i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			word_count++;
		}
	}
	int max_word_len = 0;
	for (i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			if (i - j > max_word_len)
			{
				max_word_len = i - j;
			}
			j = i + 1;
		}
	}
	if (i - j > max_word_len)
	{
		max_word_len = i - j;
	}
	for (i = 0; i < max_word_len + 4; i++)
	{
		printf("*");
	}
	printf("\n");
	j = 0;
	for (i = 0; i < len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			word[j] = '\0';
			printf("* ");
			printf("%s", word);
			for (j = strlen(word); j < max_word_len; j++)
			{
				printf(" ");
			}
			printf(" *\n");
			j = 0;
		}
		else
		{
			word[j++] = str[i];
		}
	}
	word[j] = '\0';
	printf("* ");
	printf("%s", word);
	for (j = strlen(word); j < max_word_len; j++)
	{
		printf(" ");
	}
	printf(" *\n");
	for (i = 0; i < max_word_len + 4; i++)
	{
		printf("*");
	}
	printf("\n");
	return 0;
}
