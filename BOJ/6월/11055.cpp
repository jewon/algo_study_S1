#include<iostream>
#include<vector>
using namespace std;

#define MAX_INT 2147483647

int main()
{
	int n;
	cin >> n;

	vector<int> numbers;
	numbers.resize(n);
	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	vector<int> acc;
	acc.resize(n);

	acc[0] = numbers[0];
	for (int i = 1; i < n; i++)
	{
		int max = -1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (numbers[j] < numbers[i] && acc[j] > max)
				max = acc[j];
		}
		if (max != -1)
			acc[i] = max + numbers[i];
		else
			acc[i] = numbers[i];
	}

	int max_acc = 0;
	for (int i = 0; i < n; i++)
		if (acc[i] > max_acc)
			max_acc = acc[i];

	cout << max_acc;
	system("pause");
	return 0;

}