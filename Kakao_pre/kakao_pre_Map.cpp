/*
*	���� 20180526 : 27.04ms
*	Ʋ�ȴ� ���� : (1) 1��, 1��¥�� ����� ���ߴ�. (2) int overflow�� ��� ���ߴ�.
*/


#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map);

int main()
{
	int m = 3;
	int n = 4;

	/*
	���� n, ���� m
	*/

	vector<vector<int>> city_map(m, vector<int>(n, 0));

	city_map = { { 0, 0, 0, 0 }, { 0, 2, 2, 0 }, { 0, 0, 0, 0 } };

	int result = solution(m, n, city_map);
	cout << result << endl;

	system("pause");
	return 0;
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;

	/*
	routesH : ���� n, ���� m + 1
	routesV : ���� n + 1, ���� n
	*/

	//vector<vector<int>> routesH;
	//vector<int> tempH;
	//for (int i = 0; i < n; i++)
	//	tempH.push_back(0);
	//for (int j = 0; j < m; j++)
	//	routesH.push_back(tempH);

	//vector<vector<int>> routesV;
	//vector<int> tempV;
	//for (int i = 0; i < n; i++)
	//	tempV.push_back(0);
	//for (int j = 0; j < m; j++)
	//	routesH.push_back(tempV);

	if (m == 1 && n == 1)
		return 1;

	vector<vector<int>> routesH(m, vector<int>(n, 0));
	vector<vector<int>> routesV(m, vector<int>(n, 0));

	// ù��
	for (int i = 0; i < n; i++)
	{
		if (city_map[0][i] != 1)
			routesH[0][i] = 1;
		else
			break;
	}

	if (m == 1) // ���η� �� �� ¥����
		return routesH[0][n - 1];

	// ù��
	for (int j = 0; j < m; j++)
	{
		if (city_map[j][0] != 1)
			routesV[j][0] = 1;
		else
			break;
	}

	if (n == 1) // ���η� �� �� ¥����
		return routesV[m - 1][0];

	for (int i = 1; i < m; i++ )
		for (int j = 1; j < n; j++)
		{
		
			if (city_map[i][j] == 1) // �ڱⰡ ���� ���� �����̸�
			{
				routesV[i][j] = 0;
				routesH[i][j] = 0;
				continue;
			}

			// �������� ���� ���
			if (city_map[i][j - 1] == 2)
				routesH[i][j] = routesH[i][j - 1];
			else
				routesH[i][j] = (routesV[i][j - 1] + routesH[i][j - 1]) % MOD;

			// ������ ���� ���
			if (city_map[i - 1][j] == 2)
				routesV[i][j] = routesV[i - 1][j];
			else
				routesV[i][j] = (routesH[i - 1][j] + routesV[i - 1][j]) % MOD;
		}

	answer = (routesH[m - 1][n - 1] + routesV[m - 1][n - 1]) % MOD;

	return answer;
}