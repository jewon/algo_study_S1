#include<iostream>
#include<cmath>
using namespace std;

const int MAX_N = 8001; // 숫자의 가짓수(-4000~4000)

// 전체적으로 카운팅 소팅 알고리즘 중간에 몇 개의 반복, 조건문을 끼워 넣은 형태

int main()
{
	int size;

	scanf("%d", &size); // 크기 입력
	int arr[MAX_N + 1]; // 받는 수의 범위 + 1개 할당
	int temp; // 버퍼
	int sum = 0; // 총합

	for (int i = 0; i < MAX_N + 1; i++)
		arr[i] = 0; // 초기화

	// arr에 히스토그램 만들기
	for (int i = 0; i < size; i++)
	{ // 버퍼에 숫자 하나 받음
		
		scanf("%d", &temp);
		arr[temp + 4000]++; // 받은 숫자 해당하는 인덱스에++
		sum += temp; // 총합
	}

	int median = 8001; // 중위수
	int max = 8001; // 최대값
	int min = 8001; // 최솟값

	int max_count_index1 = 8001; // 첫 번째로 빈도수 높은 인덱스
	int max_count_index2 = 8001; // 두 번째로 빈도수 높은 인덱스
	
	// 최대, 최소, 최빈값 구하기
	for (int i = MAX_N - 1; i > -1; i--)
	{ // 8000번지부터 하나씩 내려옴
		
		if (max > 8000 && arr[i] > 0)
			max = i; // 가장 처음 숫자가 나타나는 인덱스가 최대값임
		
		if (arr[i] > 0)
			min = i; // 빈도가 1이상인 인덱스를 계속 저장해서 마지막에 남는 게 최솟값임
		
		if (arr[i] >= arr[max_count_index1])
		{ // 현재 빈도수가 이전에 저장된 최대빈도수보다 높거나 같으면
			max_count_index2 = max_count_index1; // 이전의 인덱스를 2번 인덱스로
			max_count_index1 = i; // 현재의 것을 1번 인덱스로
		}
	}// 최대빈도가 두개 이상의 인덱스에서 나타나면 가장 작은것이 1번, 두 번째 것이 2번에 저장된다


	// 최대빈도 중복 검사
	if (arr[max_count_index1] != arr[max_count_index2]) // 예비저장소와 현재저장소의 빈도수가 다름: 최빈값이 유일하다
		max_count_index2 = max_count_index1; // 2번 인덱스 값은 필요없고, 2번에 덮어씌움

	// else 빈도수가 같을 경우 그냥 2번 인덱스 선택하면 됨

	// 중위수 찾기
	for (int i = 1; i < MAX_N; i++)
	{ // 누적분포를 그려 보자
		arr[i] += arr[i - 1]; // 누적분포를 그려보자
		if (arr[i] > size / 2) // 누적빈도가 절반 넘어가면 (size가 항상 홀수)
		{
			median = i; // 그 순간의 인덱스가 중위수가 된다
			break; // 끝
		}
	}

	printf("%.0f\n", floor((sum*1.0) / (size*1.0) + 0.5)); // 유의 강제형변환 한다고 해도 출력 타입이나 대입연산자 등에 따라 연산 후에는 풀리기도 한다...
	/*
	테스트 :
	cout << (float)3 / (float)2 + 0.5 ; 하면 2가 출력된다. 왜지???
	*/
	printf("%d\n", median - 4000); // 중위수
	printf("%d\n", max_count_index2 - 4000); // 최빈값
	printf("%d\n", max - min); // 범위

	return 0;
}