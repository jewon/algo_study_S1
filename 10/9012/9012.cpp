#include<stdio.h>
using namespace std;

# define size 50

int main()
{
	int n = 0; // 입력받는 줄수
	int cur = 0; // n번 반복할 변수
	int open = 0; // 현재 괄호 열린 갯수: 다 돌고 0아니면 NO
	bool ICanMakeIt = true; // Yes / No
	char * temp = new char [size + 1]; // 입력받은 괄호 문자열
	for (int i = 0; i < size + 1; i++) // 초기화
		temp[i] = NULL;

	scanf("%d", &n);
	// 할 수 있는건지 검사
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
