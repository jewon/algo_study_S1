/*
*	정답: 2018. 07. 03
*/

#include<iostream>
#include<set>
using namespace std;

int main()
{
	int n; ///< 회의 수
	cin >> n;

	multiset<pair<int, int>> conf; ///< 회의시작시간(key) - 끝시간(value)
	int start = 0;
	int end = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		conf.insert(make_pair(start, end));
	} // 회의 시작시간 기준으로 정렬됨

	int time = 0;
	int holded_conf = 0;
	multiset<pair<int, int>>::iterator iter; ///< 이터레이터
	for (iter = conf.begin(); iter != conf.end(); iter++)
	{
		if (iter->first < time)
			continue; // 이미 지난 회의면 다음 회의로

		// 회의 선택
		int fastest_end_time = iter->second;
		multiset<pair<int, int>>::iterator seletor;
		multiset<pair<int, int>>::iterator seleted_conf = iter;
		for (seletor = iter; seletor != conf.end(); seletor++)
		{
			// 회의 시작시간이 지금까지 회의 중 가장 빠른 끝시간보다 작을 떄만 찾기
			if (seletor->first > fastest_end_time)
				break;
			// cout << seletor->first << "---" << seletor->second << endl;
			if (seletor->second < fastest_end_time)
			{
				fastest_end_time = seletor->second;
				seleted_conf = seletor;
			}
		}

		// 회의 선택이 완료된 후 동작
		// cout << seleted_conf->first << "---" << seleted_conf->second << endl;
		holded_conf++;
		time = fastest_end_time; // 현재 시간을 회의 종료 시간으로함
		iter = seleted_conf; // 시작하자마자 끝나는 회의가 계속 선택되는 것 방지
	}

	cout << holded_conf;

	system("pause");
	return 0;
}