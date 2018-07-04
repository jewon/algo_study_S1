/*
*	정답: 2018. 7. 4
*/

#include<iostream>
#include<map>
using namespace std;

// 박스 타입
typedef struct box
{
	int box_l;
	int box_w;
	int box_h;

	int box_min;	// 셋 중 최소변길이

	box(int l, int w, int h)
	{
		box_l = l;
		box_w = w;
		box_h = h;

		// 최소변길이 계산
		box_min = box_l;
		if (box_w < box_min)
			box_min = box_w;
		if (box_h < box_min)
			box_min = box_h;
	}
};

// b에 들어가는 최소 큐브 갯수를 리턴해주는 재귀함수
int recur(box b, map<int, int> & cubes, map<int, int>::reverse_iterator rit);

int main()
{
	// 입력
	int l, w, h;
	cin >> l >> w >> h;
	box mainbox(l, w, h);

	int n_cubes;
	cin >> n_cubes;

	int cube_i, cube_n;
	map<int, int> cubes; // 큐브i - 큐브 갯수 pair로 map에 저장
	for (int i = 0; i < n_cubes; i++)
	{
		cin >> cube_i >> cube_n;
		cubes.insert(pair<int, int>(cube_i, cube_n));
	}

	// 리버스 이터레이터 사용해 큰 큐브부터 탐색하도록
	map<int, int>::reverse_iterator rit = cubes.rbegin();
	cout << recur(mainbox, cubes, rit);

	system("pause");
	return 0;
}

// 리턴: 사용한 큐브 갯수, -1이면 못채우는 경우
int recur(box b, map<int, int> & cubes, map<int, int>::reverse_iterator rit)
{
	// base case
	if (b.box_min == 0) // 이미 다 채워진 박스 들어오면 0 리턴
		return 0;

	// common case
	// 큰 큐브부터 채우기 시도 (한 변 길이기 2^i이므로 무조건 큰거채우는게 이득)
	// 만약 큰 큐브부터 넣다가 채울수 없는 경우는 다른 방법으로도 채울 수 없음
	int t = 0;
	int cube_i = 0; // 큐브 i
	int cube_l = 0; // 큐브 한 변 길이

	// 들어가는 가장 큰 큐브 찾기 (reverse_iter 사용)
	for (; rit != cubes.rend(); rit++)
	{
		cube_i = rit->first;
		cube_l = 1;
		for (int i = 0; i < cube_i; i++)
			cube_l *= 2;
		if (cube_l > b.box_min || rit->second == 0) // 박스 최소변길이보다 큐브가 더 크면 못넣는다
			continue;
		else
			break;
	}
	if (rit == cubes.rend()) // 가장 작은 큐브마저 못 넣으면 못 채운다
		return -1;

	// 한 변에 들어가는 큐브의 갯수
	int n_cube_l = b.box_l / cube_l;
	int n_cube_w = b.box_w / cube_l;
	int n_cube_h = b.box_h / cube_l;

	// 이미 가진 큐브보다 들어갈수 있는 큐브 갯수가 많으면 한 변에 하나씩 줄여서 최대로 넣기
	while ((long)n_cube_l * (long)n_cube_w * (long)n_cube_h > (long)rit->second) // 큐브가 들어갈 수 있는 갯수는 int 넘어갈 수 있다
	{
		if (n_cube_l > 1)
			n_cube_l--;

		else if (n_cube_w > 1)
			n_cube_w--;

		else if (n_cube_h > 1)
			n_cube_h--;
		else
			return -1;
	}

	// 이번에 들어가는 큐브 총 갯수
	int result = n_cube_l * n_cube_w * n_cube_h;
	rit->second -= result;

	// 큐브 채우고 남은 부분을 세 개의 새로운 박스로 쪼개어 큐브수 반환받아 더함
	t = recur(box(b.box_l, b.box_w, b.box_h - cube_l * n_cube_h), cubes, rit);
	if (t < 0)
		return -1;
	else
		result += t;

	t = recur(box(b.box_l - cube_l * n_cube_l, b.box_w, cube_l * n_cube_h), cubes, rit);
	if (t < 0)
		return -1;
	else
		result += t;

	t = recur(box(cube_l * n_cube_l, b.box_w - cube_l * n_cube_w, cube_l * n_cube_h), cubes, rit);
	if (t < 0)
		return -1;
	else
		result += t;

	return result;
}