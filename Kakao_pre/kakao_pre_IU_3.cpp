#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int recur2(int & sub, int beforemove, int maxmove, int cur, int starnum, int moveplus, vector<int> & LUT_MAX)
{
	if (cur > sub) // �̹� ���簪�� �� ũ�� �۷��Ծ���
		return 0;

	if (cur + LUT_MAX[starnum] < sub) // !!!!!�̹� ���� �� �������� ��� ���� �� �ִ�� �Űܵ� ���ڶ�� �۷��Ծ���
		return 0;

	// ���� �����ؼ� ���
	if (starnum == 0)
	{ 
		if (sub >= cur + beforemove * 2 && sub <= cur + maxmove * 2) // ������ ���� �����϶����� 2�� �����ϹǷ�
			return 1;
		else
			return 0;
	}

	// ���
	int result = 0;

	cur += moveplus * beforemove;
	for (int i = beforemove; i <= maxmove; i++)
	{
		result += recur2(sub, i, maxmove + 2, cur, starnum - 1, moveplus / 3, LUT_MAX);
		cur += moveplus;
	}
	
	return result;
}
//
//int recur(int n, vector<int> & LUT, vector<int> now, int order, int star_num, int cur, int min_move_star)
//{
//	
//
//	int result = 0;
//	int max_move = 2 * (order - 1 - star_num);
//	int min_move;
//	if (star_num == order - 1)
//		min_move = 0;
//	else
//		min_move = now[star_num + 1];
//
//	if (star_num == 0) // ����
//	{
//		if (cur + min_move * 2 <= n && n <= cur + max_move * 2)
//			return 1;
//		else
//			return 0;
//	}
//
//	now[star_num] = min_move;
//	cur += min_move * LUT[star_num];
//	for (int i = min_move; i <= max_move; i++)
//	{
//		if (cur > n) // �̹� n���� Ŀ������ �ƿ�
//			break;
//		else
//			result += recur(n, LUT, now, order, star_num - 1, cur, min_move_star);
//		cur += LUT[star_num];
//		now[star_num]++;
//	}
//
//	return result;
//}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n) {
	int answer = 0;

	int order = 0; // ����
	int temp = n; // �ӽ÷� �� ����
	
	// log3�� ����
	while (1)
	{
		temp /= 3;
		if (temp == 0)
			break;
		order++;
	}

	// �ּڰ� ���ϱ�
	int min = 1;
	for (int i = 0; i < order; i++)
		min *= 3;
	min += order * 2;

	// �ִ밪 ���ϱ�
	int max = 1;
	for (int i = 0; i < order; i++)
	{
		max *= 3;
		max += 2;
	}

	// �ּڰ����� �� ���ϱ�
	int sub = n - min;

	// �ִ�, �ּ� ���� ���̸� �Ұ���
	if (n < min || (max > 0 && n > max))
		return 0;

	// �ִ�, �ּҿ� ������ ����� �Ѱ���
	if (n == min || n == max)
		return 1;

	// ���̰� Ȧ���� �Ұ���
	if (sub % 2 == 1)
		return 0;

	// ����� ������ �ϱ� ���� LUT�����(i��° ���� ������ �� �������� ��)
	vector<int> LUT(order, 0);
	for (int i = 0; i < order; i++)
		LUT[i] = pow(3, i) * 2;

	// ����� �� ���ϰ� �ϱ� ���� ���� LUT�� �������� ���ϱ�
	// ���� ���� ��ĭ �����̸� ���� ���� ��ĭ �������� �ϱ� ������
	// �ʱ� ���¿��� �ѵ�ĭ ������ �� ����� ���ϱ� ���� ����(i��° ���� �����϶��� �ּڰ�)
	vector<int> LUT_ACC = LUT;
	for (int i = 1; i < order; i++)
		LUT_ACC[i] += LUT_ACC[i - 1];

	// i��° ���� �����̴� ���� �̹� ���
	int max_move_star_num = order - 1;
	for (int i = 0; i < order - 1; i++)
	{
		if (LUT_ACC[i] > sub)
		{
			max_move_star_num = i - 1;
			break;
		}
	}

	// i��°������ ���� �� �� �ڷ� �Ű������� �������� �� ���̺�
	vector<int> LUT_MAX = LUT;
	LUT_MAX[0] *= 2 * (order - 1);
	for (int i = 1; i < order; i++)
	{
		LUT_MAX[i] *= 2 * (order - 1 - i);
		LUT_MAX[i] += LUT_MAX[i - 1];
	}

	// �ּ��� i��° ���� �������� ��
	int min_move_star_num = 0;
	for (int i = 0; i < order; i++) // ��ĭ�� �غ��� �ɷ�����
	{
		if (LUT_MAX[i] > sub)
		{
			min_move_star_num = i; // i��° ���� �������� ������ ���� ���� ��Ȳ��
			break;
		}
	}

	//// �������� �ٿ����� ���� ���� ���Ͽ� log3�� ���غ�
	//temp = sub;
	//int sub_order = 0;
	//while (1)
	//{
	//	temp /= 3;
	//	if (temp == 0)
	//		break;
	//	sub_order++;
	//}

	//// ���� ������ ������ �� ������ ������ 
	//// �ִ��� ������ ���� ���� ���������� n�� ����� ���� ����
	//temp = min;
	//int star_num = 0; // �ڽź��� �����ʿ� �ִ� ���� ��
	//int star_move_plus = 2; // ���� ��ĭ �� �� ���� �����ϴ� ��
	//int star_max_move = 2 * (order - 1); // ���� �ִ� ������ �� �ִ� Ƚ��
	//while (temp < max)	// ���� ���ʷ� �ڷ� ����
	//{
	//	temp += star_move_plus * star_max_move;
	//	if (temp > n)
	//		break;
	//	else
	//	{
	//		star_num++; // ���� ����
	//		star_move_plus *= 3; // ���� ���� ������ �� �����ϴ� �� * 3�辿 ���� Ŀ����
	//		star_max_move -= 2; // �ִ� ������ �� �ִ� Ƚ���� ������ ���� 2ȸ ����
	//	}
	//}
	//
	//// ���� ���� : ������ ������ �ڷ� ������ ���� �� �� �شܿ� ���� �ִ� ����, temp�� n���� ū ù ����
	vector<int>now(order, 0);
	//int cur = min;

	//for (int i = 1; i < 2 * (order - 1 - min_move_star_num); i++)
	//{
	//	now[min_move_star_num] = i;
	//	cur += LUT[min_move_star_num];

	//	answer += recur(n, LUT, now, order, min_move_star_num - 1, cur);
	//}

	//answer = recur(sub, LUT, now, order, max_move_star_num, 0, min_move_star_num);
	answer = recur2(sub, 0, 2 * (order - 1 - max_move_star_num), 0, max_move_star_num, LUT[max_move_star_num], LUT_MAX);
	return answer;
}


int main()
{
	int n = 2147483647;
	cout << solution(n);

	system("pause");
}