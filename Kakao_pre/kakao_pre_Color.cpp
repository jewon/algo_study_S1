/*
*	채점완료 (20180519
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> solution(int, int, vector<vector<int>>);
void color(int, int, int&, vector<vector<int>>&);

int main()
{
	int m = 6;
	int n = 4;
	vector<vector<int>> picture;

	for (int i = 0; i < m; i++)
	{
		vector<int> element;
		element.resize(n);
		picture.push_back(element);
	}

	picture = { {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} };
	vector<int> answer = solution(m, n, picture);

	cout << answer[0] << endl;
	cout << answer[1] << endl;
	system("pause");
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	int mx_s = 0;
	int colors = 0;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (picture[i][j] < 1)
				continue;
			else
			{
				colors++;
				int temp_c = picture[i][j];
				int temp_s = 0;
				color(i, j, temp_s, picture);
				if (temp_s > mx_s)
					mx_s = temp_s;
			}
		}

	vector<int> answer(2);
	answer[0] = colors;
	answer[1] = mx_s;

	return answer;
}

void color(int m, int n, int& s, vector<vector<int>>& picture) // 컬러 사이즈 반환
{
	s++;
	int c = picture[m][n];
	picture[m][n] = -1; // 현재 위치의 컬러를 따로 저장하고 -1 집어넣음
	if (n + 1 < picture[m].size() &&  c == picture[m][n + 1]) //오른쪽
		color(m, n + 1, s, picture);
	if (m + 1 < picture.size() && c == picture[m + 1][n]) //아래쪽
		color(m + 1, n, s, picture);
	if (n > 0 && c == picture[m][n - 1]) //왼쪽
		color(m, n - 1, s, picture);
	if (m > 0 && c == picture[m - 1][n]) //위쪽
		color(m - 1, n, s, picture);
}
