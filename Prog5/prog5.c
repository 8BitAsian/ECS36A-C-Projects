#include "prog5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* calculateRowSums(int** vals, int numRows, int* rowWidths)
{
	//Ensures no NULL pointers are passed in
	if (!vals || !rowWidths || numRows < 0)
	{
		return NULL;
	}
	else
	{
		//Creates an array for the total number of rows.
		//malloc creates this array using dynamic memory allocation
		int* arr = malloc(numRows * sizeof(int*));
		
		//for loop iterates through numRows array
		for (int i = 0; i < numRows; ++i)
		{
			int sum = 0;
			
			//Var width uses the current iteration to determine the length of the current row
			//Var *index uses the current iteration to determine the array of values that must be summed
			int width = rowWidths[i]; 
			int *index = vals[i];
			
			//This loop takes *index and iterates through it in order to calculate the sum
			//The sum value is assigned to a spot in arr and the array is returnedi
			if (!index)
			{
				free(arr);
				return NULL;
			}
			else
			{
				for (int j = 0; j < width; ++j)
				{
					sum += index[j];
					arr[i] = sum;
				}
			}		
		}
		return arr;
	}
}	

int sumSubsquare(int** arr, int numRows, int numCols, int rowStart, int rowEnd, int colStart, int colEnd, int* result)
{
	int sum = 0;
	
	//Checks for NULL pointers and for illegal inputs
	if (!arr || !result || rowStart > numRows || numRows < 0 || numCols < 0 || rowStart < 0 || colStart > numCols || colStart < 0)
	{
		return 0;
	}
	else
	{
		//This loop ensures that we are only dealing with row values within our parameters
		for (int i = rowStart; i <= rowEnd; ++i)
		{
			//This loop ensures that we are dealing with column values within our parameters
			//It uses i and j iterations in order to create a "coordinate" point for a 2D array
			for (int j = colStart; j <= colEnd; ++j)
			{
				//the arr value that corresponds to i and j is added to sum and returned
				sum += arr[i][j];
			}
		}	
	}
	*result = sum;
	return 1;
}

int* applyTransformation(char **strings, int numStrings, int (*transform)(char*))
{
	//Allocate memory for the transformation array
	int* arr = malloc(numStrings * sizeof(char*));
	
	//this loop applies the transformation for each item in the strings array
	for (int i = 0; i < numStrings; i++)
	{
		//Based on the iteration, string item is transformed using the function and is passed into the array
		arr[i] = (*transform)(strings[i]);
	}
	return arr;
}
