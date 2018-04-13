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
	scanf_s("%d", &size);
	a = new int[size + 1];

	int sum = 0;

	// �Է¹���
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &a[i]);
		sum += a[i];
	}

	whatthehell(a, size); // ��������

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

	printf("%d", (sum + size/2) / size); // ������
	printf("\n");
	printf("%d", a[size / 2]); // �߾Ӱ�
	printf("\n");
	printf("%d", max_freq);// �ֺ�
	printf("\n");
	printf("%d", a[size - 1] - a[0]);// ����

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