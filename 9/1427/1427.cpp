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
	// 1���������� ���� ���ʿ�
	if (size == 1)
		return;


	int * ah = &a[size / 2];
	whatthehell(a, size / 2); // �����κ� ����
	whatthehell(ah, size - (size / 2)); // �����κ� ����

	int * b = new int[size + 1]; // ���
	int p = 0; // ���� ������ ��ġ
	int p1 = 0; // �����κ� �񱳴�� ��ġ
	int p2 = size / 2; // �����κ� �񱳴�� ��ġ


	for (int p = 0; p < size; p++)
	{
		if ((a[p1] > a[p2] || p1 == size / 2) && p2 != size)
		{ // p2�� ���� ���� ���� �ʰ�, p1�� ���� �����ϰų�, �Ѵ� �߰��ε� p2�� ������
			b[p] = a[p2];
			p2++; // p2 �����ϰ� ������
		}
		else
		{ // �ƴϸ�
			b[p] = a[p1];
			p1++; // p1 �����ϰ� ������
		}
	}

	for (p = 0; p < size; p++)
		a[p] = b[p];

	delete[] b;

	return;
}