/*
*	����: 2018. 7. 4
*/

#include<iostream>
#include<map>
using namespace std;

// �ڽ� Ÿ��
typedef struct box
{
	int box_l;
	int box_w;
	int box_h;

	int box_min;	// �� �� �ּҺ�����

	box(int l, int w, int h)
	{
		box_l = l;
		box_w = w;
		box_h = h;

		// �ּҺ����� ���
		box_min = box_l;
		if (box_w < box_min)
			box_min = box_w;
		if (box_h < box_min)
			box_min = box_h;
	}
};

// b�� ���� �ּ� ť�� ������ �������ִ� ����Լ�
int recur(box b, map<int, int> & cubes, map<int, int>::reverse_iterator rit);

int main()
{
	// �Է�
	int l, w, h;
	cin >> l >> w >> h;
	box mainbox(l, w, h);

	int n_cubes;
	cin >> n_cubes;

	int cube_i, cube_n;
	map<int, int> cubes; // ť��i - ť�� ���� pair�� map�� ����
	for (int i = 0; i < n_cubes; i++)
	{
		cin >> cube_i >> cube_n;
		cubes.insert(pair<int, int>(cube_i, cube_n));
	}

	// ������ ���ͷ����� ����� ū ť����� Ž���ϵ���
	map<int, int>::reverse_iterator rit = cubes.rbegin();
	cout << recur(mainbox, cubes, rit);

	system("pause");
	return 0;
}

// ����: ����� ť�� ����, -1�̸� ��ä��� ���
int recur(box b, map<int, int> & cubes, map<int, int>::reverse_iterator rit)
{
	// base case
	if (b.box_min == 0) // �̹� �� ä���� �ڽ� ������ 0 ����
		return 0;

	// common case
	// ū ť����� ä��� �õ� (�� �� ���̱� 2^i�̹Ƿ� ������ ū��ä��°� �̵�)
	// ���� ū ť����� �ִٰ� ä��� ���� ���� �ٸ� ������ε� ä�� �� ����
	int t = 0;
	int cube_i = 0; // ť�� i
	int cube_l = 0; // ť�� �� �� ����

	// ���� ���� ū ť�� ã�� (reverse_iter ���)
	for (; rit != cubes.rend(); rit++)
	{
		cube_i = rit->first;
		cube_l = 1;
		for (int i = 0; i < cube_i; i++)
			cube_l *= 2;
		if (cube_l > b.box_min || rit->second == 0) // �ڽ� �ּҺ����̺��� ť�갡 �� ũ�� ���ִ´�
			continue;
		else
			break;
	}
	if (rit == cubes.rend()) // ���� ���� ť�긶�� �� ������ �� ä���
		return -1;

	// �� ���� ���� ť���� ����
	int n_cube_l = b.box_l / cube_l;
	int n_cube_w = b.box_w / cube_l;
	int n_cube_h = b.box_h / cube_l;

	// �̹� ���� ť�꺸�� ���� �ִ� ť�� ������ ������ �� ���� �ϳ��� �ٿ��� �ִ�� �ֱ�
	while ((long)n_cube_l * (long)n_cube_w * (long)n_cube_h > (long)rit->second) // ť�갡 �� �� �ִ� ������ int �Ѿ �� �ִ�
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

	// �̹��� ���� ť�� �� ����
	int result = n_cube_l * n_cube_w * n_cube_h;
	rit->second -= result;

	// ť�� ä��� ���� �κ��� �� ���� ���ο� �ڽ��� �ɰ��� ť��� ��ȯ�޾� ����
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