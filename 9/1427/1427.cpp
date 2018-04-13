#include<iostream>
using namespace std;

void whatthehell(int * &a, int size);

int main()
{
	int a = 0;
	scanf_s("%d", &a);

	int * arr = new int [10 + 1];
	int size;
	for (size = 0; a != 0; size++)
	{
		arr[size] = a % 10;
		a /= 10;
	}

	whatthehell(arr, size);

	for (int i = size - 1; i > -1; i--)
		printf("%d", arr[i]);

	delete[] arr;
	system("pause");
	return 0;
}

void whatthehell(int * &a, int size)
{
	// 1개남았으면 정렬 노필요
	if (size == 1)
		return;


	int * ah = &a[size / 2];
	whatthehell(a, size / 2); // 낮은부분 정렬
	whatthehell(ah, size - (size / 2)); // 높은부분 정렬

	int * b = new int[size + 1]; // 결과
	int p = 0; // 현재 들어가야할 위치
	int p1 = 0; // 낮은부분 비교대상 위치
	int p2 = size / 2; // 높은부분 비교대상 위치


	for (int p = 0; p < size; p++)
	{
		if ((a[p1] > a[p2] || p1 == size / 2) && p2 != size)
		{ // p2가 끝에 도달 하지 않고, p1이 끝에 도달하거나, 둘다 중간인데 p2가 작으면
			b[p] = a[p2];
			p2++; // p2 선택하고 다음꺼
		}
		else
		{ // 아니면
			b[p] = a[p1];
			p1++; // p1 선택하고 다음꺼
		}
	}

	for (p = 0; p < size; p++)
		a[p] = b[p];

	delete[] b;

	return;
}