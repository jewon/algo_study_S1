/*
*	1743�� ���� : 6. 22
*	���� ���� : ����Լ��� ���ʵ� ������ �� (���ϸ� J�� ����� ��� ���ʺκ��� �ٸ� �κ����� �ν���)
*/

#include<iostream>
#include<vector>
using namespace std;

int recur(int sx, int sy, vector<vector<int>> & road);

int main()
{
	// ���� �ʱ�ȭ �� �Է�
	int m, n, k;
	cin >> n >> m >> k;

	if (k == 0)
	{
		cout << 0;
		return 0;
	}

	vector<vector<int>> road;
	vector<int> tr;
	for (int j = 0; j < m + 2; j++)
		tr.push_back(0);
	for (int i = 0; i < n + 2; i++)
		road.push_back(tr);

	int x, y;
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		road[x][y] = 1;
	}

	//vector<vector<int>> trash;
	//vector<int> tt;
	//tt.resize(2);
	//for (int i = 0; i < k; i++)
	//{
	//	cin >> tt[0] >> tt[1];
	//	trash.push_back(tt);
	//}

	int max_size = 0;
	int size = 0;

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < m + 1; j++)
			if ((size = recur(j, i, road)) > max_size)
 				max_size = size;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			cout << road[i][j];
		}
		cout << endl;
	}


	cout << max_size;
	system("pause");
	return 0;
}

int recur(int sx, int sy, vector<vector<int>> & road)
{
	if (road[sy][sx] == -1)
		return 0;
	else if (road[sy][sx] == 0)
		return 0;
	else
	{
		road[sy][sx] = -1;
		return 1 + recur(sx + 1, sy, road) + recur(sx, sy + 1, road) + recur(sx - 1, sy, road) + recur(sx, sy - 1);
	}
}