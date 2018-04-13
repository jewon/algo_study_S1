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
	scanf_s("%d", &size);
	a = new int[size + 1];

	int sum = 0;

	// 입력받음
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &a[i]);
		sum += a[i];
	}

	whatthehell(a, size); // 병합정렬

	int max_freq = 8001;
	int pre_max_freq = 8001;

	int b[8002];
	for (int i = 0; i < 8002; i++)
		b[i] = 0;
	for (int i = 0; i < size; i++)
		b[(a[i] + 4000)]++;
	for (int i = 8000; i > -1; i--)
	{
		if (b[i] >= b[max_freq])
		{
			pre_max_freq = max_freq;
			max_freq = i;
		}
	}
	if (b[max_freq] == 1)
		max_freq = a[1];
	else if (b[pre_max_freq] == b[max_freq])
		max_freq = pre_max_freq - 4000;
	else
		max_freq -= 4000;

	/*
		
	int label_count_max_p = size - 1;
	int label_count_max = 1;
	int label_count = 1;
	int temporary_p = -1;

	a[size] = 4001;
	for (int i = size - 1; i != -1; i--)
	{
		if (a[i] == a[i + 1])
			label_count++;
		else
		{
			if (label_count_max < label_count)
			{
				label_count_max = label_count;
				label_count_max_p = i + 1;
				temporary_p = -1;
			}
			else if (label_count_max = label_count)
			{
				temporary_p = label_count_max_p;
				label_count_max_p = i + 1;
			}
			label_count = 1;
		}
	}

	if (temporary_p >= 0)
		label_count_max_p = temporary_p;

	if (label_count_max == 1)
		label_count_max_p = 1;

	int lebel_count_max_value = a[label_count_max_p];*/

	int mean;
	if (sum%size > size / 2)
		mean = sum / size + 1;
	else
		mean = sum / size;

	printf("%d", (sum + size/2) / size); // 산술평균
	printf("\n");
	printf("%d", a[size / 2]); // 중앙값
	printf("\n");
	printf("%d", max_freq);// 최빈값
	printf("\n");
	printf("%d", a[size - 1] - a[0]);// 범위

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