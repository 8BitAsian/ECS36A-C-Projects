#include "arr_utils.h"
#include <stdio.h>
#define MAX_BUF_LEN 30

int sumArrs(int *arr1, int *arr2, int len, int *outputArr)
{	
	//Checks for Null pointers
	if (!arr1 || !arr2 || !outputArr)
	{
		return 0;
	}
	else
	{
		//For loop uses variable len to iterate though both arrays, combining their values at same index
		for (int i = 0; i < len; ++i)
		{
			int sumVal = arr1[i] + arr2[i];
			outputArr[i] = sumVal;
		}
	}
return 1;
}

int minAtSameIndex(int *arr1, int *arr2, int *arr3, int len, int *index)
{
	//inTrack arrays are sub-arrays that keep track of all matching indexes
	//incount keeps track of the index and resets whenever a new min is found
        int inTrack1[MAX_BUF_LEN], inTrack2[MAX_BUF_LEN], inTrack3[MAX_BUF_LEN];	
	int inCount1 = 0, inCount2 = 0, inCount3 = 0;
	//Checking for NULL pointers
	if (!arr1 || !arr2 || !arr3 || !index)
	{
		return 0;
	}
	else
	{
		//These variables keep track of the minimum value of each array
		int min1 = arr1[0], min2 = arr2[0], min3 = arr3[0];
		for (int i = 0; i < len; ++i)
		{
			//Sets initial index in inTrack to 0
			if (i == 0)
                        {
                                inTrack1[0] = i;
                        }
			//If i != 0, these else ifs compares current array value to the min
			//if value is == min, it adds it to the next index. 
			//If it is less, it replaces the min and clears inTrack and inCount
                        else if (arr1[i] == min1)
                        {
                                inCount1 += 1;
                                inTrack1[inCount1] = i;
                        }
			else if (arr1[i] < min1)
			{
				min1 = arr1[i];
				inCount1 = 0;
				inTrack1[inCount1] = i;
			}
                }
			
		//Same logic as last for loop		
		for (int j = 0; j < len; ++j)
		{		
			if (j == 0)
			{
				inTrack2[0] = j;
			}
			else if (arr2[j] == min2)
                        {
				inCount2 += 1;
                                inTrack2[inCount2] = j;
                        }
                        else if (arr2[j] < min2)
                        {
                                min2 = arr2[j];
                                inCount2 = 0;
                                inTrack2[inCount2] = j;
                        }
		}	
		//Same logic as last for loop
		for (int k = 0; k < len; ++k)
		{
			if (k == 0)
                        {
                                inTrack3[0] = k;
                        }
                        else if (arr3[k] == min3)
                        {
                                inCount3 += 1;
                                inTrack3[inCount3] = k;
                        }
                        else if (arr3[k] < min3)
                        {
                                min3 = arr3[k];
                                inCount3 = 0;
                                inTrack3[inCount3] = k;
                        }
		}

		//These nested for loops compare each version of inTrack to the next
		for (int x = 0; x <= inCount1; ++x)
		{
			for (int y = 0; y <= inCount2; ++y)
			{
				if (inTrack1[x] == inTrack2[y])
				{
					for (int z = 0; z <= inCount3; ++z)
					{
						//If there is an inTrack value that all 3 arrays share, it is passed to *index
						if (inTrack2[y] == inTrack3[z])
						{
							*index = inTrack3[z];
							return 1;
						}
					}
				}
			}
		}

	}
*index = -1;
return 0;
}

