/*
*	정답 2018. 7. 5
*/
#include<iostream>
#include<map>
using namespace std;

long get_k(long in, long n);

int main()
{
	long n;
	long k;
	cin >> n >> k;

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

/*
	map<int, int> numbers;
	int acc = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (numbers.find(i * j) == numbers.end())
				numbers[i * j] = 1;
			else
				numbers[i * j]++;

		if (get_k(i * n, n) < k)
		{
			numbers.clear();
			numbers[i * n] = n;
		}
	}

	int kkk = 0;
	map<int, int>::iterator it = numbers.begin();
	for (it = numbers.begin(); it != numbers.end(); it++)
	{
		kkk += it->second;
		if (kkk > k)
			break;
	}

	cout << it->first;*/

	long cl = n / 2;
	long min_cl = 1;
	long max_cl = n;

	// 가온데 대각선 기준으로 우선 한 번 탐색
	while (min_cl < max_cl)
	{
		cl = (min_cl + max_cl + 1) / 2;
		if (get_k(cl * cl - 1, n) + 1 > k)
			max_cl = cl - 1;
		else
			min_cl = cl;
	}

	long min_col = min_cl;
	long max_col = ((min_cl + 1) * (min_cl + 1) / min_cl) + 1; 
	/* arc근방에 걸쳐져 있는 수들은 고려되지 않을 수 있으므로 arc밖의 첫 수까지 고려하기로 한다 */
	if (max_col > n)
		max_col = n;
	long col = (min_col + max_col + 1) / 2;
	while (min_col < max_col)
	{
		col = (min_col + max_col + 1) / 2;
		if (get_k(min_cl * col - 1, n) + 1 > k)
			max_col = col - 1;
		else
			min_col = col;
	} // 컬럼 단위 이진탐색

	long min_v = min_cl * min_col;
	long max_v = min_cl * min_col + min_cl - 1;
	long v = (min_v + max_v + 1) / 2;
	while (min_v < max_v)
	{
		v = (min_v + max_v + 1) / 2;
		if (get_k(v - 1, n) + 1 > k)
			max_v = v - 1;
		else
			min_v = v;
	} // 두 위치 사이의 수 이진탐색

	cout << (long)min_v;
	system("pause");
	return 0;
}

long get_k(long in, long n)
{
	long result = 0;
	long t;
	for (long i = 1; i <= n; i++)
	{
		t = in / i;
		if (i > in)
			break;
		if (t > n)
			result += n;
		else
			result += t;
	}

	return result;
}