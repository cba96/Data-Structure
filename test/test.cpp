// 컴언어1 실습문제 (해도되고 안해도 됨^^)
#include <stdio.h>
#include <stdlib.h>

#define	COFFEE_PRICE	3500
#define	TAX_RATE		0.10

int main(void)
{
	//printf("\"ASCII code\", '\A\', \\t, \'B\', \\n\n");
	int n = 0, m = 0;

	// An asterisk (*) following the percent sign suppresses assignment
	// of the next input field, which is interpreted as a field of the specified type.
	// The field is scanned but not stored.
	scanf("%d %*s %d", &n, &m);
	printf("%d %d\n", n, m);

	/*
	int nNumberOfCoffee = 0;
	int nTotalPrice = 0;

	printf("커피 몇 잔 드실래요? ");
	scanf_s("%d", &nNumberOfCoffee);

	nTotalPrice = nNumberOfCoffee * COFFEE_PRICE;

	printf("영수증\n");
	printf("========================================\n");
	printf("커피\n");
	printf("\t%d\t%10d\n", nNumberOfCoffee, nTotalPrice);
	printf("========================================\n");
	printf("공급가액:\t%10d\n", (int)((double) nTotalPrice * (1.0 - TAX_RATE)));
	printf("VAT 금액:\t%10d\n", (int)((double) nTotalPrice * TAX_RATE));
	printf("========================================\n");
	printf("결제금액:\t%10d\n", nTotalPrice);

	printf("%0*d", 5, 3); // 00003 is output
	printf( "%.*f", 3, 3.14159265 ); // 3.142 output
	*/

	return 0;
}