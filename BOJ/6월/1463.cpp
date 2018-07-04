//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int target;
//	cin >> target;
//
//	int temp = target;
//	int order_6 = 0;
//	while (1)
//	{
//		temp /= 6;
//		if (temp == 0)
//			break;
//		order_6++;
//	}
//
//	vector<vector<int>> LUT (order_6, vector<int>(order_6, 0));
//	temp = 1;
//	int temp2 = 1;
//	for (int i = 0; i <= order_6; i++)
//	{
//		for (int j = 0; j <= order_6; j++)
//		{
//			LUT[i][j] = temp * temp2;
//			temp2 *= 3;
//		}
//		temp *= 2;
//	}
//
//	int root = order_6 * 2 + 2;
//	for (int i = 0; i <= order_6; i++)
//	{
//		if (LUT[order_6][i] < target && (order_6 + i + target - LUT[order_6][i]) < root)
//			root = order_6 + i + target - LUT[order_6][i];
//	}
//
//	for (int i = 0; i <= order_6; i++)
//	{
//		if (LUT[i][order_6] < target && (order_6 + i + target - LUT[i][order_6]) < root)
//			root = order_6 + i + target - LUT[order_6][i];
//	}
//
//	cout << root;
//	system("pause");
//}

#include<iostream>
#include<vector>
using namespace std;
/*
*	정답 : 2018. 05. 27 / 32ms
*	틀린요인 : 1을 중간에 2번까지 뺼 수 있다, 1이 입력되면 0이 출력되야한다
*/

#define MAX_INT 2147483647

int recur(int target, int sub_check)
{
	if (target == 1)
		return 0;

	int root_temp;
	int root = MAX_INT - 1;

	if (target % 3 == 0)
		root = recur(target / 3, 0);
	if (target % 2 == 0)
	{
		root_temp = recur(target / 2, 0);
		if (root_temp < root)
			root = root_temp;
	}

	if (sub_check < 2)
	{
		root_temp = recur(target - 1, sub_check + 1);
		if (root_temp < root)
			root = root_temp;
	}

	return root + 1;
}

int main()
{
	int target;
	cin >> target;

	int root;
	root = recur(target, 0);


	cout << root;
	system("pause");
}