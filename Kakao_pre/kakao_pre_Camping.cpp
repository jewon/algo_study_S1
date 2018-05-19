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

���⸦ �켱 x�� �������� �����صξ� ���������� ������ �� �ϰ����ִ� ������...
x���� ������ �����Ƿ�, �� ���Ⱑ ����� ��Ʈ ���� ���̿� �ٸ� ���Ⱑ �ֳ� �˻��� ��
�� ���� ���� �ε����� �ִ� ��� ������� y���� �˻��ϸ� �ȴ�.
�Ǵ� �� nC2���� �̹Ƿ� ���⿡�� �ȵǴ� �͸� ������.

*/

int solution(int n, vector<vector<int>> data) {
	int answer = n * (n - 1) / 2; // �� ���� ���� ���� : nC2
	int badCombi = 0;

	// ���� �����͸� x�� �������� ������(����)
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

	// ��� ���յ��� �˻��غ���
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n && i != n; j++)
		{
			if (data[i][0] == data[j][0]) // ���� x���ΰ�� (���η� ����)
				badCombi++;

			else if (data[i][1] == data[j][1]) // ���� y���� ��� (���η� ����)
				badCombi++;

			else
			{
				if (data[i][1] > data[j][1]) // ���� ��, ������ �Ʒ��� ���� �ڴ� ���
				{
					for (int x = i + 1; x < j; x++)
						if (data[x][0] != data[i][0] && data[x][0] != data[j][0] && // i, j����� ���� ���μ����� �ƴϰ�
							data[x][1] > data[j][1] && data[x][1] < data[i][1]) // ���Ʒ��� i, j ���� ���̿� ������
						{
							badCombi++;
							break;
						}
				}

				else // ���� �Ʒ�, ������ ���� ���� �ڴ� ���
				{
					for (int x = i + 1; x < j; x++)
						if (data[x][0] != data[i][0] && data[x][0] != data[j][0] && // i, j����� ���� ���μ����� �ƴϰ�
							data[x][1] > data[i][1] && data[x][1] < data[j][1])	// ���Ʒ��� i, j ���� ���̿� ������
						{
							badCombi++;
							break;
						}
				}
			}
		}
	}

	answer -= badCombi; // �߸��� ������ �� ���� ������ ����
	return answer;
}