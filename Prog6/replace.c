#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_SIZE 100
#define LINE_BUF_SIZE (MAX_LINE_SIZE + 1)

int main(int argc, char *argv[])
{
	FILE *input;
	FILE *output;
	if ((argc != 7) || (argv[3] > argv[4]) || (argv[3] < 0) || (argv[4] < 0))
	{
		return 1;
	}
	else
	{
		if ((input = fopen(argv[1], "r")))
		{
			if ((output = fopen(argv[2], "w")))
			{
				int start = atoi(argv[3]);
				int end = atoi(argv[4]);
				char buf[LINE_BUF_SIZE];
				char bufCopy[LINE_BUF_SIZE];
				for (int i = 1; fgets(buf, MAX_LINE_SIZE, input); i++)
				{
					if (i >= start && i <= end)
					{
						int lineLen = strlen(buf);
						int tarlen = strlen(argv[5]);
						char* hit;
						if (strstr(buf, argv[5]))
						{
							hit = strstr(buf, argv[5]);
							int len1 = hit - buf;
							strncpy(bufCopy, buf, len1);
					        	strcat(bufCopy, argv[6]);
							hit += tarlen;
							if (lineLen == (hit - buf))
							{
								fputs(bufCopy, output);
							}
							else
							{
								strcat(bufCopy, hit);
								fputs(bufCopy, output);
							}
							
						}
						else
						{
							fputs(buf, output);
						}			
					}
					else
					{
						fputs(buf, output);
					}
				memset(buf, '\0', LINE_BUF_SIZE);
				memset(bufCopy, '\0', LINE_BUF_SIZE);
						
				}
			}
			else
			{
				perror("Error opening output file.");
				return 1;
			}
		} 
		else
		{
			perror("Error opening input file.");
			return 1;
		}
	}
	fclose(input);
	fclose(output);
	return 0;	
}
