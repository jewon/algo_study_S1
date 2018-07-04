/*
*	정답 : 2018. 07. 02
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	// 입력
	int n, l;
	cin >> n >> l;
	vector<int> water_points;
	vector<int> water_point_interval;
	water_points.resize(n, 0);
	water_point_interval.resize(n - 1, 0);

	for (int i = 0; i < n; i++)
		cin >> water_points[i];

	// 소팅 (bubble)
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (water_points[j] > water_points[j + 1])
			{
				int t = water_points[j + 1];
				water_points[j + 1] = water_points[j];
				water_points[j] = t;
			}

	// 간격 구해 넣기
	for (int i = 0; i < n - 1; i++)
		water_point_interval[i] = water_points[i + 1] - water_points[i];

	// 간격 읽어가며 테이프 붙이기
	int acc = 0;
	int tapes = 1;
	for (int i = 0; i < n - 1; i++)
	{
		acc += water_point_interval[i];
		if (acc > l - 1) // 기존 테이프로 커버 못하는 점임
		{
			tapes++;
			acc = 0;
		}
	}

	// 출력 및 종료
	cout << tapes;
	system("pause");
	return 0;
}