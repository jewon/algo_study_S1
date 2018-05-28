#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	//int zeros = 1;
	//int ones = 1;
	//for (int i = 1; i < N - 2; i++)
	//{
	//	int temp = ones;
	//	ones = zeros;
	//	zeros = zeros + temp;
	//}

	//int result = zeros + ones;

	//if (N == 1)
	//	result = 1;
	//else if (N == 2)
	//	result = 1;

	//cout << result;
	//system("pause");

	long a = 1;
	long b = 1;

	for (int i = 3; i <= N; i++)
	{
		long temp = b;
		b += a;
		a = temp;
	}

	cout << b;
	system("pause");
}