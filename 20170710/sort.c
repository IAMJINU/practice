#include <stdio.h>
#include<time.h>

#define ARRAY_SIZE  10
void main()
{

	int randomNum_a[ARRAY_SIZE] = { 0, };
	int temp = 0;

	int i;

	srand(time(NULL));

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		randomNum_a[i] = (rand() % 10000) + 22222;
	}

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d - %d\r\n", i, randomNum_a[i]);
	}

	printf("\n");

	for (i = 0; i < (ARRAY_SIZE); i++)
	{
		for (int j = 0; j < (ARRAY_SIZE - 1); j++)
		{
			if (randomNum_a[j] > randomNum_a[j + 1])
			{
				temp = randomNum_a[j + 1];
				randomNum_a[j + 1] = randomNum_a[j];
				randomNum_a[j] = temp;
			}
		}
	}

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d - %d\r\n", i, randomNum_a[i]);
	}

	getch();

	return;
}