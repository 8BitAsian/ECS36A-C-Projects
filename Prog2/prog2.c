#include <stdio.h>

int isUpper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int isLower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int isAlpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int isDigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int toLower(int c)
{
	if (c >= 65 && c <= 90)
	{
		return(c + 32);
	}
	else
	{
		return(c);
	}
}

int toUpper(int c)
{
        if (c >= 97 && c <= 122)
        {
                return(c - 32);
        }
        else
        {
                return(c);
        }
}

int foo(void)
{	
	int run = 0;
	char usrImp = 0;
	int counter = 0;
	do {
		printf("Enter character: ");
		scanf(" %c", &usrImp);	
		if (usrImp >= 97 && usrImp <= 122)
		{
			counter += 1;
			continue;
		}		

		if (usrImp >= 65 && usrImp <= 90)
		{	
			printf("Entered uppercase letter!\n"); 
			run += 1;
			return(counter);			}	
		else 
		{
			printf("Did not enter letter!\n");
			run += 1;
			return(counter);
		}
	} while(run == 0);
	return(0);
}

int goo(void)
{
	int run = 0;
	int usrImp1 = 0;
	int usrImp2 = 0;
	int prodsum = 0;
	int prod = 0;
	do {
		printf("Enter num1: ");
		scanf("%d", &usrImp1);
		printf("Enter num2: ");
		scanf("%d", &usrImp2);
		prod = usrImp1 * usrImp2;
		prodsum += prod;
		if (prod != 0)
		{
			continue;
		}
		else
		{
			run += 1;
			return(prodsum);
		}
	} while(run == 0);
return(0);
}

int foo2(int n, int k)
{
	int rtnVal = 0;
	for (int counter = 1; counter <= n; counter += 1)
		{
			int subVal = 0;
			for (int counter2 = 1; counter2 <= counter; counter2 += 1)
			{	
				if ((counter % counter2) == 0)
				{
					subVal += 1;
				}
			}
			if (subVal == k)
			{
				rtnVal += 1;
			}
		}
					
	return rtnVal;
}
// ===== CUT HERE =====
int main()
{
}

