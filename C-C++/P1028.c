#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);

	int array[1001];
	array[0] = 1;
	array[1] = 1;
	for (int j = 2; j <= num; j++)
	{
		array[j] = 0;
		for (int i = 0; i <= j / 2; i++)
			array[j] += array[i];
	}
	printf("%d", array[num]);
}