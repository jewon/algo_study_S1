#include<iostream>
using namespace std;

/*
합병 정렬 (From Wikipedia)

합병 정렬은 다음과 같이 작동한다.

리스트의 길이가 0 또는 1이면 이미 정렬된 것으로 본다. 그렇지 않은 경우에는
정렬되지 않은 리스트를 절반으로 잘라 비슷한 크기의 두 부분 리스트로 나눈다.
각 부분 리스트를 재귀적으로 합병 정렬을 이용해 정렬한다.
두 부분 리스트를 다시 하나의 정렬된 리스트로 합병한다.
*/

void whatthehell(int * &a, int size);

int main()
{
	int * a;
	int size;

	// 사이즈 입력받고 할당
	scanf("%d", &size);
	a = new int[size + 1];

	// 입력받음
	for (int i = 0; i < size; i++)
		scanf("%d", &a[i]);

	whatthehell(a, size);

	for (int i = 0; i < size; i++)
	{
		printf("%d", a[i]);
		printf("\n");
	}

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
		{
			b[p] = a[p2];
			p2++;
		}
		else
		{
			b[p] = a[p1];
			p1++;
		}
	}

	for (p = 0; p < size; p++)
		a[p] = b[p];

	delete[] b;

	return;
}