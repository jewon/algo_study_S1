#include<iostream>
#include<vector>
using namespace std;

int recur(vector<int> & arr, int life, int cur, int & target, int b_index)
{
	int result = 0;

	if (life == 1)
	{
		for (int i = b_index + 1; i < arr.size(); i++)
		{
			int a = cur + arr[i];
			if (a == target)
				result++;
		}
		return result;
	}

	for (int i = b_index + 1; i < arr.size(); i++)
		result = recur(arr, life - 1, cur + arr[i], target, i);

	return result;
}

int main()
{
	int N, S;
	cin >> N >> S;

	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int answer = 0;
	for (int i = 1; i <= N; i++)
		answer += recur(arr, i, 0, S, -1);
	cout << arr.size();

	cout << answer;
	system("pause");
}