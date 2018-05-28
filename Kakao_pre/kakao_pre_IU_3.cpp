#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int recur2(int & sub, int beforemove, int maxmove, int cur, int starnum, int moveplus, vector<int> & LUT_MAX)
{
	if (cur > sub) // 이미 현재값이 더 크면 글러먹었다
		return 0;

	if (cur + LUT_MAX[starnum] < sub) // !!!!!이번 별과 그 오른쪽의 모든 별을 다 최대로 옮겨도 모자라면 글러먹었다
		return 0;

	// 끝에 도달해서 계산
	if (starnum == 0)
	{ 
		if (sub >= cur + beforemove * 2 && sub <= cur + maxmove * 2) // 마지막 별은 움직일때마다 2씩 증가하므로
			return 1;
		else
			return 0;
	}

	// 재귀
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
//	if (star_num == 0) // 계산부
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
//		if (cur > n) // 이미 n보다 커버리면 아웃
//			break;
//		else
//			result += recur(n, LUT, now, order, star_num - 1, cur, min_move_star);
//		cur += LUT[star_num];
//		now[star_num]++;
//	}
//
//	return result;
//}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n) {
	int answer = 0;

	int order = 0; // 차수
	int temp = n; // 임시로 몫 저장
	
	// log3값 구함
	while (1)
	{
		temp /= 3;
		if (temp == 0)
			break;
		order++;
	}

	// 최솟값 구하기
	int min = 1;
	for (int i = 0; i < order; i++)
		min *= 3;
	min += order * 2;

	// 최대값 구하기
	int max = 1;
	for (int i = 0; i < order; i++)
	{
		max *= 3;
		max += 2;
	}

	// 최솟값과의 차 구하기
	int sub = n - min;

	// 최대, 최소 범위 밖이면 불가능
	if (n < min || (max > 0 && n > max))
		return 0;

	// 최대, 최소와 같으면 방법은 한가지
	if (n == min || n == max)
		return 1;

	// 차이가 홀수면 불가능
	if (sub % 2 == 1)
		return 0;

	// 계산을 빠르게 하기 위한 LUT만들기(i번째 별이 움직일 때 더해지는 수)
	vector<int> LUT(order, 0);
	for (int i = 0; i < order; i++)
		LUT[i] = pow(3, i) * 2;

	// 계산을 더 편하계 하기 위해 만든 LUT의 누적도수 구하기
	// 앞의 별을 한칸 움직이면 뒤의 별도 한칸 움직여야 하기 때문에
	// 초기 상태에서 한두칸 움직일 때 계산결과 구하기 쉽게 해줌(i번째 별이 움직일때의 최솟값)
	vector<int> LUT_ACC = LUT;
	for (int i = 1; i < order; i++)
		LUT_ACC[i] += LUT_ACC[i - 1];

	// i번째 별이 움직이는 순간 이미 노답
	int max_move_star_num = order - 1;
	for (int i = 0; i < order - 1; i++)
	{
		if (LUT_ACC[i] > sub)
		{
			max_move_star_num = i - 1;
			break;
		}
	}

	// i번째까지의 별을 다 맨 뒤로 옮겼을때의 더해지는 값 테이블
	vector<int> LUT_MAX = LUT;
	LUT_MAX[0] *= 2 * (order - 1);
	for (int i = 1; i < order; i++)
	{
		LUT_MAX[i] *= 2 * (order - 1 - i);
		LUT_MAX[i] += LUT_MAX[i - 1];
	}

	// 최소한 i번째 별이 움직여야 함
	int min_move_star_num = 0;
	for (int i = 0; i < order; i++) // 한칸씩 해보고 걸러보자
	{
		if (LUT_MAX[i] > sub)
		{
			min_move_star_num = i; // i번째 별이 움직이지 않으면 답이 없는 상황임
			break;
		}
	}

	//// 가짓수를 줄여보기 위해 차에 대하여 log3값 구해봄
	//temp = sub;
	//int sub_order = 0;
	//while (1)
	//{
	//	temp /= 3;
	//	if (temp == 0)
	//		break;
	//	sub_order++;
	//}

	//// 가장 뒤쪽의 별부터 맨 끝까지 보내서 
	//// 최대한 비중이 작은 별의 움직임으로 n과 비슷한 수를 만들어봄
	//temp = min;
	//int star_num = 0; // 자신보다 오른쪽에 있는 별의 수
	//int star_move_plus = 2; // 별이 한칸 갈 때 마다 증가하는 수
	//int star_max_move = 2 * (order - 1); // 별이 최대 움직일 수 있는 횟수
	//while (temp < max)	// 별을 차례로 뒤로 보냄
	//{
	//	temp += star_move_plus * star_max_move;
	//	if (temp > n)
	//		break;
	//	else
	//	{
	//		star_num++; // 다음 별은
	//		star_move_plus *= 3; // 전의 별이 움직일 때 증가하는 수 * 3배씩 수가 커지고
	//		star_max_move -= 2; // 최대 움직일 수 있는 횟수는 이전에 비해 2회 적다
	//	}
	//}
	//
	//// 현재 상태 : 오른쪽 별부터 뒤로 보내서 별이 양 쪽 극단에 몰려 있는 상태, temp가 n보다 큰 첫 순간
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