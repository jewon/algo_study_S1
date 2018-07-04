/*
*	정답 2018. 6. 30
*/

#include<iostream>
#include<map>
using namespace std;

int main()
{
	// 입력
	int	n_trees, h_required;
	cin >> n_trees >> h_required;

	// 나무 입력받을 때 빈도분포만 세서 저장함
	map<int, int> trees_map;
	int h;
	for (int i = 0; i < n_trees; i++)
	{
		cin >> h;
		if (trees_map.find(h) == trees_map.end())
			trees_map[h] = 1;
		else
			trees_map[h]++;
	}

	// map 역순회하면서 잘린 길이 계산하기
	map<int, int>::reverse_iterator rit = trees_map.rbegin();
	if (h_required == 0) // 0미터 자를때 예외처리
	{
		cout << 0;
		return 0;
	}
	int n_cut_trees = 0; // 잘리는 나무의 갯수
	int h_cut_break = 0; // 다음 나무 높이
	int cutted = 0; // 잘린 나무들 높이 합
	int h_cut = rit->first - 1; // 현재 세팅 높이(최초: 최대나무높이 - 1)
	for (rit = trees_map.rbegin(); rit != trees_map.rend(); rit++) // 제일 높은 나무들부터 거꾸로(이터레이터는 다음 나무에 이미 가있음)
	{
		map<int, int>::reverse_iterator rit_next = rit;
		rit_next++;
		n_cut_trees += rit->second; // 잘리는 나무의 갯수
		if (rit_next == trees_map.rend())
			h_cut_break = 0;
		else
			h_cut_break = rit_next->first;
		for (; h_cut >= h_cut_break; h_cut--) // 1m씩 위에서 잘라보자
		{
			cutted += n_cut_trees; // 1m씩 잘라서 자른 높이에 추가함
			// cout << "set : " << h_cut << " >> " << cutted << " / " << h_required << endl;
			if (cutted >= h_required) // 충분히 잘랐으면
				break; // 끝
		}
		if (cutted >= h_required) // 충분히 잘랐으면
			break; // 끝
	} // 다 잘라도 모자라 끝에 도달하면 h_cut = 0임

	cout << h_cut;
	system("pause");
	return 0;
}