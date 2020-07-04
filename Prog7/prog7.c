#include "prog7.h"
#include <stdio.h>
#include <assert.h>
int getProduct(int* arr, int arrLen)
{
	int index = 0;
	if (index == arrLen - 1)
	{
		return arr[index];
	}
	else
	{
		return arr[index] * getProduct(arr + 1, arrLen - 1); 
	}
	
}

int linearSearch(int* arr, int arrLen, int target)
{
	int index = 0;
	if (arr[index] == target)
	{
		return 1;
	}
	if (index == (arrLen) && arr[index] != target)
	{
		return 0;
	}
	else
	{
		return linearSearch(arr + 1, arrLen - 1, target);
	}
}

