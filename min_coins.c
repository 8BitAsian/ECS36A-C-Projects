#include <stdio.h>

int main ()
{
	printf("Enter number of cents: ");
	int cents = 0;
	scanf("%d", &cents);
	if (cents >= 0)
	{
		int quarters = cents/25;
		cents %= 25;
		int dimes = cents/10;
		cents %= 10;
		int nickels = cents/5;
		cents %= 5;
		int pennies = cents/1;
		printf("q=%d, d=%d, n=%d, p=%d\n", quarters, dimes, nickels, pennies);
	}
	return 0;
}
