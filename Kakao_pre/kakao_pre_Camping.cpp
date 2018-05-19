#include<iostream>
#include<vector>
using namespace std;

int solution(int, vector<vector<int>>);

int main()
{
	int n = 4;
	vector<vector<int>> data;

	for (int i = 0; i < n; i++)
	{
		vector<int> element;
		element.resize(2);
		data.push_back(element);
	}

	data = { {0, 0},{1, 1},{0, 2},{2, 0} };
	int answer = solution(n, data);

	cout << answer;
	system("pause");
}

/*

쐐기를 우선 x축 기준으로 소팅해두어 순차적으로 접근할 때 일관성있는 순서로...
x축은 정리되 있으므로, 두 쐐기가 만드는 텐트 범위 사이에 다른 쐐기가 있나 검사할 때
두 쐐기 사이 인덱스에 있는 모든 쐐기들을 y값만 검사하면 된다.
되는 건 nC2가지 이므로 여기에서 안되는 것만 빼보자.

*/

int solution(int n, vector<vector<int>> data) {
	int answer = n * (n - 1) / 2; // 총 조합 가능 갯수 : nC2
	int badCombi = 0;

	// 벡터 데이터를 x축 기준으로 소팅함(버블)
	vector<int> temp;
	temp.resize(2);
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (data[j - 1][0] > data[j][0])
			{
				temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
		}
	}

	// 모든 조합들을 검사해보자
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n && i != n; j++)
		{
			if (data[i][0] == data[j][0]) // 같은 x값인경우 (세로로 일자)
				badCombi++;

			else if (data[i][1] == data[j][1]) // 같은 y값인 경우 (가로로 일자)
				badCombi++;

			else
			{
				if (data[i][1] > data[j][1]) // 왼쪽 위, 오른쪽 아래에 쐐기 박는 경우
				{
					for (int x = i + 1; x < j; x++)
						if (data[x][0] != data[i][0] && data[x][0] != data[j][0] && // i, j쐐기와 같은 세로선상이 아니고
							data[x][1] > data[j][1] && data[x][1] < data[i][1]) // 위아래로 i, j 쐐기 사이에 있으면
						{
							badCombi++;
							break;
						}
				}

				else // 왼쪽 아래, 오른쪽 위에 쐐기 박는 경우
				{
					for (int x = i + 1; x < j; x++)
						if (data[x][0] != data[i][0] && data[x][0] != data[j][0] && // i, j쐐기와 같은 세로선상이 아니고
							data[x][1] > data[i][1] && data[x][1] < data[j][1])	// 위아래로 i, j 쐐기 사이에 있으면
						{
							badCombi++;
							break;
						}
				}
			}
		}
	}

	answer -= badCombi; // 잘못된 조합을 총 조합 수에서 빼자
	return answer;
}