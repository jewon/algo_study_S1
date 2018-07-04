/*
*	���� : 2018. 07. 02
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	// �Է�
	int n, l;
	cin >> n >> l;
	vector<int> water_points;
	vector<int> water_point_interval;
	water_points.resize(n, 0);
	water_point_interval.resize(n - 1, 0);

	for (int i = 0; i < n; i++)
		cin >> water_points[i];

	// ���� (bubble)
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (water_points[j] > water_points[j + 1])
			{
				int t = water_points[j + 1];
				water_points[j + 1] = water_points[j];
				water_points[j] = t;
			}

	// ���� ���� �ֱ�
	for (int i = 0; i < n - 1; i++)
		water_point_interval[i] = water_points[i + 1] - water_points[i];

	// ���� �о�� ������ ���̱�
	int acc = 0;
	int tapes = 1;
	for (int i = 0; i < n - 1; i++)
	{
		acc += water_point_interval[i];
		if (acc > l - 1) // ���� �������� Ŀ�� ���ϴ� ����
		{
			tapes++;
			acc = 0;
		}
	}

	// ��� �� ����
	cout << tapes;
	system("pause");
	return 0;
}