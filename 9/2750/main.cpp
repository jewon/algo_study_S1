#include<iostream>
using namespace std;

int main()
{
	int n; // 총 받는 숫자 갯수
	int i; // 지금 받는 게 몇 번쨰?
	cin >> n;
	int tmp; // 받은 수 임시 저장
	int cur; // 들어가야 할 곳

	int * arr = new int[n + 1]; // 숫자 정렬할 배열
	for (i = 0; i < n; i++)
	{
		cur = i; // 루프가 끝까지 돌면 마지막이 니자리임
		cin >> tmp; // 숫자 하나 받고
		for (int j = 0; j < i; j++)
		{	// 숫자가 들어가야 할 위치를 정해보자
			if (tmp < arr[j])
			{  // 받은 수가 더 크면
				cur = j;  // 그자리가 니자리다
				break; // 루프 끝
			}
		}
		for (int x = i; cur < x; x--)
		{	// 들어갈 자리 뒤에있는거 다 한칸씩 민다
			arr[x] = arr[x - 1];
		}
		arr[cur] = tmp; // 준비끝 들어가쇼
	}

	// 출력
	for (int a = 0; a < n; a++)
		cout << arr[a] << endl;

	system("pause");
}