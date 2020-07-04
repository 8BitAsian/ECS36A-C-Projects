#include <stdio.h>
int main()
{
	printf("Enter the first two numbers:\n");
	int firstNum = 0;
	int secondNum = 0;
	scanf("%d", &firstNum);
	scanf("%d", &secondNum);
	int sum = (firstNum + secondNum);
	int product = (firstNum * secondNum);
	printf("The sum is: %d.\n", sum);
	printf("The product is: %d.\n", product);
	return 0;
}
