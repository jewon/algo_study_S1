#include<iostream>
using namespace std;

const int MAX_N = 10000;
// Counting Sorting

int main()
{
	int size;

	scanf_s("%d", &size);
	int arr[MAX_N + 1];
	int temp;

	for (int i = 0; i < MAX_N+1; i++)
		arr[i] = 0;

	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &temp);
		arr[temp]++;
	}

	for (int i = 1; i < MAX_N + 1; i++)
		arr[i] += arr[i - 1];

	for (int i = 1; i < MAX_N + 1; i++)
		for (int j = 0; j < arr[i] - arr[i - 1]; j++)
			printf("%d\n", i);

	system("pause");

	return 0;
}