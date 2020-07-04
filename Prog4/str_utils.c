#include "str_utils.h"

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

char *strrpbrk(char *str, char *targets)
{	
	char *output = NULL;
	//Ensuring no Null pointers passed in
	if (str && targets)
	{	
		//This loop cycles through the string until it stops at a Null Terminator
		for (int i = 0; str[i] != '\0' ; ++i)
		{
			//This subloop iterates until Null Terminator is reached for each value of i
			for (int j = 0; targets[j] != '\0'; ++j)
			{	
				//If j == i for any iteration, output is set to that index[i]
				if (str[i] == targets[j] && &str[i] != NULL)
				{
					output = &str[i];
				}
			}
		}
	}
	return(output);		
}


int parseForHighest(char *input, int *highest)
{
	//Ensures no Null pointers passed in
	if (input && highest)
	{
			char *token = NULL;
			token = strtok(input, " ; ");
			//Variable TempTok converts every token value from array to integer in order to store in highest
			int TempTok = atoi(token);
			*highest = TempTok;	
			//This is so tokenization continues until there are no more values to tokenize
			while (token != NULL)
			{	
				//We use strtok to tokenize the string; 
				//When a token is completed, it is converted to int and compared with highest.
				token = strtok(NULL, " ; ");
				if (token != NULL)
				{
					TempTok = atoi(token);
					if (TempTok > *highest)
					{
					*highest = TempTok;
					}
				}
			} 	
	}
	else
	{
		return 0;
	}
	return 1;	
}
