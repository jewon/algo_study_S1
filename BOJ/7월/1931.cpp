/*
*	����: 2018. 07. 03
*/

#include<iostream>
#include<set>
using namespace std;

int main()
{
	int n; ///< ȸ�� ��
	cin >> n;

	multiset<pair<int, int>> conf; ///< ȸ�ǽ��۽ð�(key) - ���ð�(value)
	int start = 0;
	int end = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		conf.insert(make_pair(start, end));
	} // ȸ�� ���۽ð� �������� ���ĵ�

	int time = 0;
	int holded_conf = 0;
	multiset<pair<int, int>>::iterator iter; ///< ���ͷ�����
	for (iter = conf.begin(); iter != conf.end(); iter++)
	{
		if (iter->first < time)
			continue; // �̹� ���� ȸ�Ǹ� ���� ȸ�Ƿ�

		// ȸ�� ����
		int fastest_end_time = iter->second;
		multiset<pair<int, int>>::iterator seletor;
		multiset<pair<int, int>>::iterator seleted_conf = iter;
		for (seletor = iter; seletor != conf.end(); seletor++)
		{
			// ȸ�� ���۽ð��� ���ݱ��� ȸ�� �� ���� ���� ���ð����� ���� ���� ã��
			if (seletor->first > fastest_end_time)
				break;
			// cout << seletor->first << "---" << seletor->second << endl;
			if (seletor->second < fastest_end_time)
			{
				fastest_end_time = seletor->second;
				seleted_conf = seletor;
			}
		}

		// ȸ�� ������ �Ϸ�� �� ����
		// cout << seleted_conf->first << "---" << seleted_conf->second << endl;
		holded_conf++;
		time = fastest_end_time; // ���� �ð��� ȸ�� ���� �ð�������
		iter = seleted_conf; // �������ڸ��� ������ ȸ�ǰ� ��� ���õǴ� �� ����
	}

	cout << holded_conf;

	system("pause");
	return 0;
}