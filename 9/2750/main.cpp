#include<iostream>
using namespace std;

int main()
{
	int n; // �� �޴� ���� ����
	int i; // ���� �޴� �� �� ����?
	cin >> n;
	int tmp; // ���� �� �ӽ� ����
	int cur; // ���� �� ��

	int * arr = new int[n + 1]; // ���� ������ �迭
	for (i = 0; i < n; i++)
	{
		cur = i; // ������ ������ ���� �������� ���ڸ���
		cin >> tmp; // ���� �ϳ� �ް�
		for (int j = 0; j < i; j++)
		{	// ���ڰ� ���� �� ��ġ�� ���غ���
			if (tmp < arr[j])
			{  // ���� ���� �� ũ��
				cur = j;  // ���ڸ��� ���ڸ���
				break; // ���� ��
			}
		}
		for (int x = i; cur < x; x--)
		{	// �� �ڸ� �ڿ��ִ°� �� ��ĭ�� �δ�
			arr[x] = arr[x - 1];
		}
		arr[cur] = tmp; // �غ� ����
	}

	// ���
	for (int a = 0; a < n; a++)
		cout << arr[a] << endl;

	system("pause");
}