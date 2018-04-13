#include<iostream>
#include<cmath>
using namespace std;

const int MAX_N = 8001; // ������ ������(-4000~4000)

// ��ü������ ī���� ���� �˰����� �߰��� �� ���� �ݺ�, ���ǹ��� ���� ���� ����

int main()
{
	int size;

	scanf("%d", &size); // ũ�� �Է�
	int arr[MAX_N + 1]; // �޴� ���� ���� + 1�� �Ҵ�
	int temp; // ����
	int sum = 0; // ����

	for (int i = 0; i < MAX_N + 1; i++)
		arr[i] = 0; // �ʱ�ȭ

	// arr�� ������׷� �����
	for (int i = 0; i < size; i++)
	{ // ���ۿ� ���� �ϳ� ����
		
		scanf("%d", &temp);
		arr[temp + 4000]++; // ���� ���� �ش��ϴ� �ε�����++
		sum += temp; // ����
	}

	int median = 8001; // ������
	int max = 8001; // �ִ밪
	int min = 8001; // �ּڰ�

	int max_count_index1 = 8001; // ù ��°�� �󵵼� ���� �ε���
	int max_count_index2 = 8001; // �� ��°�� �󵵼� ���� �ε���
	
	// �ִ�, �ּ�, �ֺ� ���ϱ�
	for (int i = MAX_N - 1; i > -1; i--)
	{ // 8000�������� �ϳ��� ������
		
		if (max > 8000 && arr[i] > 0)
			max = i; // ���� ó�� ���ڰ� ��Ÿ���� �ε����� �ִ밪��
		
		if (arr[i] > 0)
			min = i; // �󵵰� 1�̻��� �ε����� ��� �����ؼ� �������� ���� �� �ּڰ���
		
		if (arr[i] >= arr[max_count_index1])
		{ // ���� �󵵼��� ������ ����� �ִ�󵵼����� ���ų� ������
			max_count_index2 = max_count_index1; // ������ �ε����� 2�� �ε�����
			max_count_index1 = i; // ������ ���� 1�� �ε�����
		}
	}// �ִ�󵵰� �ΰ� �̻��� �ε������� ��Ÿ���� ���� �������� 1��, �� ��° ���� 2���� ����ȴ�


	// �ִ�� �ߺ� �˻�
	if (arr[max_count_index1] != arr[max_count_index2]) // ��������ҿ� ����������� �󵵼��� �ٸ�: �ֺ��� �����ϴ�
		max_count_index2 = max_count_index1; // 2�� �ε��� ���� �ʿ����, 2���� �����

	// else �󵵼��� ���� ��� �׳� 2�� �ε��� �����ϸ� ��

	// ������ ã��
	for (int i = 1; i < MAX_N; i++)
	{ // ���������� �׷� ����
		arr[i] += arr[i - 1]; // ���������� �׷�����
		if (arr[i] > size / 2) // �����󵵰� ���� �Ѿ�� (size�� �׻� Ȧ��)
		{
			median = i; // �� ������ �ε����� �������� �ȴ�
			break; // ��
		}
	}

	printf("%.0f\n", floor((sum*1.0) / (size*1.0) + 0.5)); // ���� ��������ȯ �Ѵٰ� �ص� ��� Ÿ���̳� ���Կ����� � ���� ���� �Ŀ��� Ǯ���⵵ �Ѵ�...
	/*
	�׽�Ʈ :
	cout << (float)3 / (float)2 + 0.5 ; �ϸ� 2�� ��µȴ�. ����???
	*/
	printf("%d\n", median - 4000); // ������
	printf("%d\n", max_count_index2 - 4000); // �ֺ�
	printf("%d\n", max - min); // ����

	return 0;
}