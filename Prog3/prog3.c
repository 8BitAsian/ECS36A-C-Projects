#include "prog3.h"

void sum3(int a, int b, int c, int *sum)
{
	if (!sum) 
	{
		return;	
	}
	else
	{
		*sum = a + b + c;
	}	
}

void testSum3(void)
{
    // Test case #1.
    int sum = 0;
    sum3(5, 8, 19, &sum);
    assert(sum == 32);

    // Test case #2.
    sum3(-5, 20, 0, &sum);
    assert(sum == 15);

    // Test case #3. No assertion needed here; just need a crash to not occur.
    sum3(14, 17, 18, NULL);


    fprintf(stderr, "testSum3(): All test cases passed!\n");
}

int compareArrays(float *arr1, float *arr2, int arrLen, int *pos)
{

	//Checks whether any of the arguments are NULL
	if (!arr1 || !arr2 || !pos)
	{
		return -1;
	}
	else
	{	
		//mismatch variable keeps track if unmatching characters have been found.
		int mismatch = 0;
		//Uses arrLen in order to filter through and match letters. 
		for (int i = 0; i < arrLen; ++i)
		{
			if (arr1[i] != arr2[i])
			{
				*pos = i;
				mismatch = 1;
			}
		}
		if (mismatch == 1)
		{
			return 0;
		}
		else
		{
			*pos = -1;
			return 1;
		}
	}
}		

void testCompareArrays(void)
{
	
	//Test Case 1 - Matching Arrays
	float arr1[] = {1.0, 2.0, 3.0, 4.0, 5.0};
	float arr2[] = {1.0, 2.0, 3.0, 4.0, 5.0};
	int pos = -2;
	int retval = compareArrays(arr1, arr2, 5, &pos);
	assert (retval == 1);
	assert (pos == -1);
	
	//Test Case 2 - Mismatched Arrays
	float arr3[] = {1.0, 3.0, 5.0, 7.0, 9.0};
	float arr4[] = {2.0, 4.0, 5.0, 7.0, 9.0};
	retval = compareArrays(arr3, arr4, 3, &pos);
	assert (retval == 0);
	assert (pos == 1);
	
	//Test Case 3 - Mismatched Arrays 2
	float arr5[] = {1.0, 2.0, 3.0, 4.0, 5.0};
	float arr6[] = {1.0, 2.0, 3.0, 4.0, 6.0};
	retval = compareArrays(arr5, arr6, 5, &pos);
	assert (retval == 0);
	assert (pos == 4);
	
	//Test Case 4 - Arrays with Operators
	float arr7[] = {1.2, 24.0/8.0, 4*3};
	float arr8[] = {12.0/10.0, 3.0, 12.0};
	retval = compareArrays(arr7, arr8, 3, &pos);
	assert (retval == 1);
	assert (pos == -1);
	
	//Test Case 5 - Mismatched Arrays 3
	float arr9[] = {1.0, 3.0, 5.0, 7.0, 9.0};
	float arr10[] = {1.0, 2.0, 5.0, 6.0, 9.0};
	retval = compareArrays(arr9, arr10, 5, &pos);
	assert (retval == 0);
	assert (pos == 3);
	
	//Test Case 6 - Passing in NULL Pointers
	float arr11[] = {1.0};
	float arr12[] = {1.0};
	retval = compareArrays(NULL, arr11, 5, &pos);
	assert (retval == -1);
	retval = compareArrays(arr11, arr12, 5, NULL);
	assert (retval == -1);
	
	

	fprintf(stderr, "testCompareArrays(): All test cases passed!\n");
}

int performShiftCipher(char *inputText, int k, char *outputText)
{
	//ensures that properly-sized k value is passed in and that input/output are not NULL
	if ((k >= -MAX_SHIFT_CIPHER_KEY && k <= MAX_SHIFT_CIPHER_KEY) && !(!inputText) && !(!outputText))
	{
		int len = strlen(inputText);
		for (int i = 0; i <= len; ++i)
		{
			int index = inputText[i] + k;
			//Checks in the case of lowercase letters. 
			if (isalpha(inputText[i]) && islower(inputText[i]))
                	{
				//These lines are dedicated to configuring wrap-around
				if (index > 'z')
				{
					//We use a modulo of the total number of alphabet letters to add to the initial value
					outputText[i] = (index  - 'a') % 26 + 'a';
				}
				else if (index < 'a')
                        	{
                        		outputText[i] = (index  - 'z') % 26 + 'z';
                        	}
				else
				{
					outputText[i] = index;
				}	
	
			}	
			//Checks om the case of uppercase letters
			else if (isalpha(inputText[i]) && isupper(inputText[i]))
                	{
                        	//These lines are dedicated to configuring wrap-around
                        	if (index > 'Z')
                        	{
                                	//We use a modulo of the total number of alphabet letters to add to the initial value
                                	outputText[i] = (index  - 'A') % 26 + 'A';
                        	}
                        	else if (index < 'A')
                        	{
                                	outputText[i] = (index  - 'Z') % 26 + 'Z';
                        	}
				else
				{
					outputText[i] = index;	
				}
	
			}
			//ensures characters that aren't letters can still be output
			else if (!isalpha(inputText[i]))
			{	
				outputText[i] = inputText[i];
			}	
		}

	}
	else
	{
		return 0;
	}
return 1;
}

void testPerformShiftCipher(void)
{	
	//Test Case 1 - Enciphering Standard Shift with lowercase
	char plainText1[] = "hello";
	char cipherText[100];
	int retval = performShiftCipher(plainText1, 5, cipherText);
	assert (strcmp(cipherText, "mjqqt") == 0);

	//Test Case 2 - Deciphering Standard Shift with lowecase
	char plainText2[] = "mjqqt";
	retval = performShiftCipher(plainText2, -5, cipherText);
	assert (strcmp(cipherText, "hello") == 0);

	//Test Case 3 - Enciphering Standard Shift with uppercase
	char plainText3[] = "HELLO";
	retval = performShiftCipher(plainText3, 5, cipherText);
	assert (strcmp(cipherText, "MJQQT") == 0);	

	//Test Case 4 - Passing in String with numbers and odd characters
	char plainText4[] = "12345'%&";
	retval = performShiftCipher(plainText4, 5, cipherText);
	assert (strcmp(cipherText, "12345'%&") == 0);

	//Test Case 5 - Passing in String with both case of letters and odd characters
	char plainText5[] = "Hello, World!";
	retval = performShiftCipher(plainText5, 5, cipherText);
	assert (strcmp(cipherText, "Mjqqt, Btwqi!") == 0) ;

	//Test Case 6 - K value is too Large 
	retval = performShiftCipher(plainText5, 501, cipherText);
	assert (retval == 0);

	//Test Case 7 - K value is too Small
        retval = performShiftCipher(plainText5, -501, cipherText);
        assert (retval == 0);
	
	//Test Case 8 - Positive Wrap Around
	retval = performShiftCipher(plainText5, 50, cipherText);
	assert (strcmp(cipherText, "Fcjjm, Umpjb!") == 0);
	
	//Test Case 9 - Negative Wrap Around
	retval = performShiftCipher(plainText5, -75, cipherText);
	assert (strcmp(cipherText, "Khoor, Zruog!") == 0);

	//Test Case 10 - NULL Pointers
	retval = performShiftCipher(NULL, 5, cipherText);
	assert (retval == -1);
	
	fprintf(stderr, "testPerformShiftCipher(): All test cases passed!\n");
}
