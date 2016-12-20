#include <stdio.h>

void main() 
{
	char str[999];
	FILE * file;
	file = fopen("test.txt", "r");
	if (file) 
	{
		while (fscanf(file, "%s", str) != EOF)
		{
			printf("%s", str);
		}
		fclose(file);
	}
}