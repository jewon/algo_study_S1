#include<iostream>
using namespace std;

/*
�պ� ���� (From Wikipedia)

�պ� ������ ������ ���� �۵��Ѵ�.

����Ʈ�� ���̰� 0 �Ǵ� 1�̸� �̹� ���ĵ� ������ ����. �׷��� ���� ��쿡��
���ĵ��� ���� ����Ʈ�� �������� �߶� ����� ũ���� �� �κ� ����Ʈ�� ������.
�� �κ� ����Ʈ�� ��������� �պ� ������ �̿��� �����Ѵ�.
�� �κ� ����Ʈ�� �ٽ� �ϳ��� ���ĵ� ����Ʈ�� �պ��Ѵ�.
*/

void whatthehell(int * &a, int size);

int main()
{
	int * a;
	int size;

	// ������ �Է¹ް� �Ҵ�
	scanf("%d", &size);
	a = new int[size + 1];

	// �Է¹���
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