/*
*	���� 2018. 6. 30
*/

#include<iostream>
#include<map>
using namespace std;

int main()
{
	// �Է�
	int	n_trees, h_required;
	cin >> n_trees >> h_required;

	// ���� �Է¹��� �� �󵵺����� ���� ������
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

	// map ����ȸ�ϸ鼭 �߸� ���� ����ϱ�
	map<int, int>::reverse_iterator rit = trees_map.rbegin();
	if (h_required == 0) // 0���� �ڸ��� ����ó��
	{
		cout << 0;
		return 0;
	}
	int n_cut_trees = 0; // �߸��� ������ ����
	int h_cut_break = 0; // ���� ���� ����
	int cutted = 0; // �߸� ������ ���� ��
	int h_cut = rit->first - 1; // ���� ���� ����(����: �ִ볪������ - 1)
	for (rit = trees_map.rbegin(); rit != trees_map.rend(); rit++) // ���� ���� ��������� �Ųٷ�(���ͷ����ʹ� ���� ������ �̹� ������)
	{
		map<int, int>::reverse_iterator rit_next = rit;
		rit_next++;
		n_cut_trees += rit->second; // �߸��� ������ ����
		if (rit_next == trees_map.rend())
			h_cut_break = 0;
		else
			h_cut_break = rit_next->first;
		for (; h_cut >= h_cut_break; h_cut--) // 1m�� ������ �߶���
		{
			cutted += n_cut_trees; // 1m�� �߶� �ڸ� ���̿� �߰���
			// cout << "set : " << h_cut << " >> " << cutted << " / " << h_required << endl;
			if (cutted >= h_required) // ����� �߶�����
				break; // ��
		}
		if (cutted >= h_required) // ����� �߶�����
			break; // ��
	} // �� �߶� ���ڶ� ���� �����ϸ� h_cut = 0��

	cout << h_cut;
	system("pause");
	return 0;
}