#include<stdio.h>
using namespace std;

# define size 50

int main()
{
	int n = 0; // �Է¹޴� �ټ�
	int cur = 0; // n�� �ݺ��� ����
	int open = 0; // ���� ��ȣ ���� ����: �� ���� 0�ƴϸ� NO
	bool ICanMakeIt = true; // Yes / No
	char * temp = new char [size + 1]; // �Է¹��� ��ȣ ���ڿ�
	for (int i = 0; i < size + 1; i++) // �ʱ�ȭ
		temp[i] = NULL;

	scanf("%d", &n);
	// �� �� �ִ°��� �˻�
	for (; cur < n; cur++)
	{
		ICanMakeIt = true;
		open = 0;
		scanf("%50s", temp);
		for(int i = 0; (temp[i] != NULL) && ICanMakeIt; i++)
		{
			if (temp[i] == '(')
				open++;
			else
				open--;
			if (open < 0)
				ICanMakeIt = false;
		}
		if (open != 0)
			ICanMakeIt = false;
		if (ICanMakeIt)
			printf("%s\n", "YES");
		else
			printf("%s\n", "NO");
	}

	delete[] temp;
	return 0;

}
