#include "my_strtok.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
char* myStrtok(const char* str, const char* delims)
{
	static int index = 0;
	static int len = 0;
	static char copy[100];
	static char buf[100];
	char* token = malloc(100 * sizeof(char));
	if (str != NULL && delims != NULL)
	{
		index = 0;
		len = strlen(str);
		int len2 = strlen(delims);
		for (int i = 0; i < len; ++i)
		{
			buf[i] = str[i];
			copy[i] = str[i];
		}
		for (int j = 0; j < len; ++j)
		{
			for (int k = 0; k < len2; ++k)
			{
				if (buf[j] == delims[k])
				{
					buf[j] = '\0';
					
				}	
			}
		}
		for (int l = 0; buf[l] != '\0'; ++l)
		{
			token[l] = buf[l];
			index = l + 1;
		}
		return token;
			
	}
	else if (!str && index != 0 && delims != NULL)
	{
		if (index == len)
		{
			free(token);
			return NULL;
		}
		else
		{
			for (int h = 0; h < len; ++h)
			{
				buf[h] = copy[h];
			}
			index += 1;
			int len2 = strlen(delims);
			for (int i = index; i < len; ++i)
			{
				for (int j = 0; j < len2; ++j)
				{
					if (buf[i] == delims[j])
					{
						buf[i] = '\0';
					}
				}
			}
			if (buf[index] == '\0')
			{
				while (buf[index] == '\0' && buf[index + 1] == '\0')
				{
					index += 1;
				}
				index += 1;
			}
		
			for (int k = 0; buf[index] != '\0'; ++k)
			{
				token[k] = buf[index];
				index += 1;   
			}
		}
		
		return token;
	}
	else
	{
		free(token);
		return NULL;
	}
}

