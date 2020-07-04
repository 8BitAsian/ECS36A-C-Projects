#include "str_utils.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
void testStrrpbrk(void)
{
	//Test Case 1 - Basic Lowercase
	char str1[] = "Hello, my name is Aaron";
	char *ptr1 = strrpbrk(str1, "abc"); 
	assert(strcmp(ptr1, "aron") == 0);
	
	//Test Case 2 - Upper and Lowercase
	char str2[] = "Hello, my name is Aaron";
        char *ptr2 = strrpbrk(str2, "ABC");
        assert(strcmp(ptr2, "Aaron") == 0);
	
	//Test Case 3 - Numbers
        char str3[] = "124354655734365768";
        char *ptr3 = strrpbrk(str3, "3");
        assert(strcmp(ptr3, "365768") == 0);

	//Test Case 4 - Passing in Null
        char str4[] = "This should return NULL.";
        char *ptr4 = strrpbrk(str4, NULL);
        assert(!ptr4);
	
	//Test Case 5 - Passing in Null 2
        char *ptr5 = strrpbrk(str4, "ABC");
        assert(!ptr5);

	//Test Case 6 - No Matches
        char *ptr6 = strrpbrk(str4, "!!!!!!");
        assert(!ptr6);
	printf("All test cases have passed for strrpbrk().\n");
	
}

void testparseForHighest(void)
{
	//Test Case 1 - Basic Template, highest is last
	char str1[] = "1;2;3;4;5";
	int highest = -1;
	int retval = parseForHighest(str1, &highest);
	assert(retval == 1);
	assert(highest == 5);
	
	//Test Case 2 - Basic Template, highest in middle
        char str2[] = "1;2;99;4;5";
        highest = -1;
        retval = parseForHighest(str2, &highest);
        assert(retval == 1);
        assert(highest == 99);

	//Test Case 3 - Excessive White Space
        char str3[] = "12;                 3";
        highest = -1;
        retval = parseForHighest(str3, &highest);
        assert(retval == 1);
        assert(highest == 12);

	//Test Case 4 - All Same Vale
        char str4[] = "5;5;5;5;5";
        highest = -1;
        retval = parseForHighest(str4, &highest);
        assert(retval == 1);
        assert(highest == 5);

	//Test Case 5 - Passing in Null
        retval = parseForHighest(str4, NULL);
        assert(retval == 0);

	//Test Case 6 - Passing in Null 2
        retval = parseForHighest(NULL, &highest);
        assert(retval == 0);


        printf("All test cases have passed for parseForHighest().\n");	


}

int main()
{
	testStrrpbrk();
	testparseForHighest();
}
