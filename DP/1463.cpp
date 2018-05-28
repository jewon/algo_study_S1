#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int target;
	cin >> target;

	int temp = target;
	int order_6 = 0;
	while (1)
	{
		temp /= 6;
		if (temp == 0)
			break;
		order_6++;
	}

	vector<vector<int>> LUT (order_6, vector<int>(order_6, 0));
	temp = 1;
	int temp2 = 1;
	for (int i = 0; i <= order_6; i++)
	{
		for (int j = 0; j <= order_6; j++)
		{
			LUT[i][j] = temp * temp2;
			temp2 *= 3;
		}
		temp *= 2;
	}

	int root = order_6 * 2 + 2;
	for (int i = 0; i <= order_6; i++)
	{
		if (LUT[order_6][i] < target && (order_6 + i + target - LUT[order_6][i]) < root)
			root = order_6 + i + target - LUT[order_6][i];
	}

	for (int i = 0; i <= order_6; i++)
	{
		if (LUT[i][order_6] < target && (order_6 + i + target - LUT[i][order_6]) < root)
			root = order_6 + i + target - LUT[order_6][i];
	}

	cout << root;
	system("pause");
}