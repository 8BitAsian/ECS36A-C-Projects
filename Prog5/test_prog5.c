#include "prog5.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_calculateRowSums(void)
{
	//Test Case 1 - Standard Case, same lengths
	int row1[] = {1, 2, 3};
	int row2[] = {4, 5, 6};
	int row3[] = {7, 8, 9};
	int rowWidths1[] = {3, 3, 3};
	int numRows = 3;
	int *rows1[] = {row1, row2, row3};
	int *sums1 = calculateRowSums(rows1, numRows, rowWidths1);
	assert(sums1[0] == 6);
	assert(sums1[1] == 15);
	assert(sums1[2] == 24);
	free(sums1);

	 //Test Case 1 - more rows, less columns
        int row4[] = {1, 2};
        int row5[] = {3, 4};
        int row6[] = {5, 6};
	int row7[] = {7, 8};
	int row8[] = {9, 10};
        int rowWidths2[] = {2, 2, 2, 2, 2};
        numRows = 5;
        int *rows2[] = {row4, row5, row6, row7, row8};
        int *sums2 = calculateRowSums(rows2, numRows, rowWidths2);
        assert(sums2[0] == 3);
        assert(sums2[1] == 7);
        assert(sums2[2] == 11);
	assert(sums2[3] == 15);
	assert(sums2[4] == 19);
        free(sums2);

	//Test Case 3 - Different row lengths and negative numbers
	int row9[] = {-1, 2, -3};
        int row10[] = {4, -5, 6, -7};
        int row11[] = {-8, 9, -10, 11, -12};
        int rowWidths3[] = {3, 4, 5};
        numRows = 3;
        int *rows3[] = {row9, row10, row11};
        int *sums3 = calculateRowSums(rows3, numRows, rowWidths3);
        assert(sums3[0] == -2);
        assert(sums3[1] == -2);
        assert(sums3[2] == -10);
        free(sums3);

	//Test Case 4 - Illegal inputs and NULL

	int *sums4 = calculateRowSums(NULL, numRows, rowWidths3);
	assert(!sums4);
	
	int *sums5 = calculateRowSums(rows3, -5000, rowWidths3);
        assert(!sums5);
	
	int *rows4[] = {NULL, NULL, NULL};
	int *sums6 = calculateRowSums(rows4, numRows, rowWidths3);
	assert(!sums6);
	free(sums6);
	
	
	printf("All test cases have passed.\n");

}

void test_sumSubsquare(void)
{
	{
		//Test 1 - Standard Case, 3 x 3
		int nr = 3;
		int nc = 3;
		int ** arr = malloc(nr * sizeof(int*));
		for (int r = 0; r < nr; ++r)
			arr[r] = malloc(nc * sizeof(int));
		arr[0][0] = 1;
		arr[0][1] = 3;
		arr[0][2] = 5;
		arr[1][0] = 2;
		arr[1][1] = 4;
		arr[1][2] = 6;
		arr[2][0] = 7;
		arr[2][1] = 9;
		arr[2][2] = 11;
		int result = -1;
		int retVal = sumSubsquare(arr, nr, nc, 0, 2, 0, 2, &result);
		assert(result == 48);
		assert(retVal == 1);
		for (int r = 0; r < nr; ++r)
                        free(arr[r]);
                free(arr);	
	}


	{
                //Test 2 - Bigger, uneven grid, 4 x 5; 2 x 4 subsquare with negatives
                int nr = 4;
                int nc = 5;
                int ** arr = malloc(nr * sizeof(int*));
                for (int r = 0; r < nr; ++r)
                        arr[r] = malloc(nc * sizeof(int));
                arr[0][0] = 22;
                arr[0][1] = -15;
                arr[0][2] = 5;
                arr[0][3] = 9;
                arr[0][4] = 0;
                arr[1][0] = -2;
		arr[1][1] = -8;
                arr[1][2] = 11;
                arr[1][3] = 100;
		arr[1][4] = -73;
                int result = -1;
                int retVal = sumSubsquare(arr, nr, nc, 0, 1, 0, 4, &result);
                assert(result == 49);
                assert(retVal == 1);
		for (int r = 0; r < nr; ++r)
			free(arr[r]);
		free(arr);
        }
	
	{
		//Test Case 3 - Bottom 4 Values
		int nr = 3;
                int nc = 3;
                int ** arr = malloc(nr * sizeof(int*));
                for (int r = 0; r < nr; ++r)
                        arr[r] = malloc(nc * sizeof(int));
                arr[0][0] = 1;
                arr[0][1] = 3;
                arr[0][2] = 5;
                arr[1][0] = 2;
                arr[1][1] = 4;
                arr[1][2] = 6;
                arr[2][0] = 7;
                arr[2][1] = 9;
                arr[2][2] = 11;
                int result = -1;
                int retVal = sumSubsquare(arr, nr, nc, 1, 2, 1, 2, &result);
                assert(result == 30);
                assert(retVal == 1);
                for (int r = 0; r < nr; ++r)
                        free(arr[r]);
                free(arr);

		 //Test Case 5 - NULL pointers
        	retVal = sumSubsquare(NULL, nr, nc, 1, 2, 1, 2, &result);
        	assert(retVal == 0);

        	retVal = sumSubsquare(arr, nr, nc, 1, 2, 1, 2, NULL);
        	assert(retVal == 0);
	}

	printf("All test cases have passed.\n");
}

static int testTransform1(char* str)
{
	if (strcmp(str, "xyz")) return 1;
	else return 0;
}
	
static int testTransform2(char* str)
{
	if (strlen(str) == 4) return 0;
	else if (strlen(str) < 3) return 3;
	else return 5;
}

static int testTransform3(char* str)
{
        if (strlen(str) != 3) return strlen(str) + 7;
        else return 7;
}

void test_applyTransformation(void)
{
	//Test Case 1 - Transform 1
	{
		int len = 5;
		char *terms[] = {"abc", "xyz", "abc", "xyz", "def"};
		int* arr = applyTransformation(terms, len, testTransform1);
		assert(arr[0] == 1);
		assert(arr[1] == 0);
		assert(arr[4] == 1);
		free(arr);
	}

	 //Test Case 2 - Transform 2
        {
                int len = 5;
                char *terms[] = {"Hello", "I", "am", "a", "UCD", "student"};
                int* arr = applyTransformation(terms, len, testTransform2);
                assert(arr[0] == 5);
                assert(arr[1] == 3);
                assert(arr[4] == 5);
                free(arr);
        }
	
	//Test Case 3 - Transform 3
	{
                int len = 3;
                char *terms[] = {"yes", "no", "yes"};
                int* arr = applyTransformation(terms, len, testTransform3);
                assert(arr[0] == 7);
                assert(arr[1] == 9);
                assert(arr[2] == 7);
                free(arr);
        }

	printf("All test cases have passed.\n");
}

int main()
{
	test_calculateRowSums();
	test_sumSubsquare();
	test_applyTransformation();
}
