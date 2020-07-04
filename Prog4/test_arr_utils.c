#include "arr_utils.h"
#include <stdio.h>
#include <assert.h>

void testsumArrs(void)
{
	//Test Case 1 - Basic Example
	int arr1[] = {1, 2, 3};
	int arr2[] = {4, 5, 6};
	int outputArr1[3];
	int retval = sumArrs(arr1, arr2, 3, outputArr1);
	assert(outputArr1[0] == 5);
	assert(outputArr1[1] == 7);
	assert(outputArr1[2] == 9);
	assert(retval == 1);

	//Test Case 2 - Same Numbers
        int arr3[] = {20, 20, 20};
        int arr4[] = {20, 20, 20};
        int outputArr2[3];
        retval = sumArrs(arr3, arr4, 3, outputArr2);
        assert(outputArr2[0] == 40);
        assert(outputArr2[1] == 40);
        assert(outputArr2[2] == 40);
        assert(retval == 1);

	//Test Case 3 - Bigger Buffer and Negative Numbers
	int arr5[] = {-1, -2, -3, -4, -5, -6, -7};
        int arr6[] = {8, 9, 10, 11, 12, 13, 14};
        int outputArr3[7];
        retval = sumArrs(arr5, arr6, 7, outputArr3);
        assert(outputArr3[0] == 7);
        assert(outputArr3[3] == 7);
        assert(outputArr3[6] == 7);
        assert(retval == 1);
	
	//Test Case 4 - Null Pointers passed in
	retval = sumArrs(NULL, arr6, 7, outputArr3);
	assert(retval == 0);

	//Test Case 5 - Null Pointers 2
	retval = sumArrs(arr5, arr6, 7, NULL);
        assert(retval == 0);
	
	printf("All test cases have passed in testsumArrs().\n");
}
void testminAtSameIndex(void)
{
	//Test Case 1 - Basic Example
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[] = {6, 7, 8, 9, 10};
	int arr3[] = {11, 12, 13, 14, 15};
	int index = -2;
	int retval = minAtSameIndex(arr1, arr2, arr3, 5, &index);
	assert(retval == 1);
	assert(index == 0);

	//Test Case 2 - Multiple Minimums
        int arr4[] = {1, 2, 1, 4, 1};
        int arr5[] = {6, 7, 6, 9, 6};
        int arr6[] = {11, 12, 11, 14, 11};
        index = -2;
        retval = minAtSameIndex(arr4, arr5, arr6, 5, &index);
        assert(retval == 1);
        assert(index == 0);
	
	//Test Case 3 - No Matching Minimum
        int arr7[] = {1, 2, 1, 4, 1};
        int arr8[] = {67, 7, 6, 9, 6};
        int arr9[] = {1, 12, 1101, 14, 11};
        index = -2;
        retval = minAtSameIndex(arr7, arr8, arr9, 5, &index);
        assert(retval == 0);
        assert(index == -1);

	//Test Case 4 - All Same Values
        int arr10[] = {1, 1, 1, 1, 1};
        int arr11[] = {1, 1, 1, 1, 1};
        int arr12[] = {1, 1, 1, 1, 1};
        index = -2;
        retval = minAtSameIndex(arr10, arr11, arr12, 5, &index);
        assert(retval == 1);
        assert(index == 0);

	//Test Case 5 - Negatives
        int arr13[] = {1, 1, -1, 1, 1};
        int arr14[] = {1, 1, -1, 1, 1};
        int arr15[] = {1, 1, -1, 1, 1};
        index = -2;
        retval = minAtSameIndex(arr13, arr14, arr15, 5, &index);
        assert(retval == 1);
        assert(index == 2);
	
	//Test Case 6 - Null Pointer passed in
	retval = minAtSameIndex(NULL, arr14, arr15, 5, &index);
	assert(retval == 0);

	//Test Case 6 - Null Pointer passed in
        retval = minAtSameIndex(arr13, arr14, arr15, 5, NULL);
        assert(retval == 0);

	
	printf("All test cases have passed in testminAtSameIndex().\n");
}
	
int main()
{
	testsumArrs();
	testminAtSameIndex();
}
