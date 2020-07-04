#include "towers.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_BUFFER_SIZE 500

struct tower
{
	int xVal;
	int yVal;
	int tHeight;
};

struct towerStars
{
	int xVal;
	int yVal;
	int stars;
};

//Manages splitting up heights into the adjacent cells
int towerMath(int numTowers, struct tower* tower)
{
	int counter = numTowers;

    	for (int j = 0; j < numTowers; ++j)
    	{
        	if (tower[j].tHeight%2 == 0)
        	{
            		counter += 1;
            		int div = tower[j].tHeight / 2;
            		tower[j + numTowers].xVal = tower[j].xVal - 1;
            		tower[j + numTowers].yVal = tower[j].yVal;
            		tower[j + numTowers].tHeight = div;
            		tower[j].xVal = tower[j].xVal + 1;
            		tower[j].tHeight = div;
        	}
        	else if (tower[j].tHeight%2 != 0)
        	{
            		counter += 2;
            		int div = (tower[j].tHeight-1) / 2;
					tower[j].tHeight = 1;
            		tower[j + numTowers].xVal = tower[j].xVal;
            		tower[j + numTowers].yVal = tower[j].yVal + 1;
            		tower[j + numTowers].tHeight = div;
            		tower[j + numTowers + 2].xVal = tower[j].xVal;
            		tower[j + numTowers + 2].yVal = tower[j].yVal - 1;
            		tower[j + numTowers + 2].tHeight = div;
        	}
    	}
    	return counter;    
}

//The Recursive Call
int _splittingTowers(struct tower* tower, int numTowers)
{
	int counter = numTowers;
	for (int i = 0; i < counter; ++i)
	{
		if (tower[i].tHeight == 1)
		{
			return counter;	
		}
	//	else if (tower[i].tHeight <= 0)
	//	{
	//		i += 1;
	//	}
		else
		{
			counter = towerMath(numTowers, tower);
			return _splittingTowers(tower, counter);
		}
	}
	return counter;

}

//Initializes the original passed in values
int* splittingTowers(int* xCoords, int* yCoords, int* heights, int numTowers, int* maxStars)
{	
	
	struct tower* tower = malloc(MAX_BUFFER_SIZE * sizeof(struct tower));
	if (!xCoords || !yCoords || !heights || !maxStars)
	{
		return NULL;
	}
	else
	{
		for (int i = 0; i < numTowers; ++i)                        
		{       
			tower[i].xVal = xCoords[i];
            tower[i].yVal = yCoords[i];
			if (heights[i] > 0)
			{
				tower[i].tHeight = heights[i];
			}
		}
	}
	int counter =  _splittingTowers(tower, numTowers);
	//Attempting to print out every cell, or every instance of tower
	/*for (int j = 0; j < counter; ++j)
	{
		printf("x: %d, y: %d, height: %d\n", tower[j].xVal, tower[j].yVal, tower[j].tHeight);
	}*/

	struct towerStars* towerStars = malloc(MAX_BUFFER_SIZE * sizeof(struct towerStars));
	for (int k = 0; k < counter; ++k)
	{
		for (int l = 1; l < counter - 1; ++l)
		{
			if (tower[k].xVal == tower[l].xVal && tower[k].yVal == tower[l].yVal)
			{
				towerStars[k].xVal = tower[k].xVal;
				towerStars[k].yVal = tower[k].yVal;	
				towerStars[k].stars += 1;
			}
			else if (tower[k].xVal == tower[l-1].xVal && tower[k].yVal == tower[l-1].yVal)
			{
				towerStars[k].xVal = towerStars[k-1].xVal;
				towerStars[k].yVal = towerStars[k-1].yVal;	
				towerStars[k].stars = towerStars[k-1].stars;
			}
			else
			{
				towerStars[k].xVal = tower[k].xVal;
				towerStars[k].yVal = tower[k].yVal;
				towerStars[k].stars = 1;
			}
		}
	}

	/*for(int m = 0; m < counter; ++m)
	{
		printf("x: %d, y: %d, stars: %d\n", towerStars[m].xVal, towerStars[m].yVal, towerStars[m].stars);
	}*/

	int output[MAX_BUFFER_SIZE];
	for (int i = 0; i < MAX_BUFFER_SIZE; ++i)
	{
		output[i] = 0;
	}

	int indexer = 1;
	for (int j = 0; j < counter; ++j)
	{
		if (towerStars[j].stars != 1)
		{
			if (towerStars[j].xVal == towerStars[j+1].xVal && towerStars[j].yVal == towerStars[j+1].yVal)
				continue;
			else
			{
				output[towerStars[j].stars]+= 1;
			}
			indexer += 1;
		}
		else
		{
			output[towerStars[j].stars] += 1;
		}
		
	}
	*maxStars = indexer;
	int* retArr = malloc(indexer * sizeof(int));
	for(int n = 1; n <= indexer; ++n)
	{
		retArr[n-1] = output[n];
	}

	return retArr;
}


/*int main()
{
	int xCoords[] = {2,2};
	int yCoords[] = {2,2};
	int heights[] = {4,4};
	int numTowers = 2;
	int maxStars = -1;
	int* ret = splittingTowers(xCoords, yCoords, heights, numTowers, &maxStars);
	printf("%d\n", maxStars);
	for (int i = 0; i < sizeof(ret)/sizeof(ret[0]); ++i)
		printf("%d\n",ret[i]);
}*/


