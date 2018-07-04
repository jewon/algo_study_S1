/*
*	Á¤´ä: 2017. 7. 4
*/
#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int> & arr, int left, int right);
bool iptime(vector<int> & houses, int rest_iptime, int set_interval);

int main()
{
	int n;
	int c;
	vector<int> houses;

	cin >> n >> c;

	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		houses.push_back(t); 
	}

	quickSort(houses, 0, houses.size() - 1);
	int itv = (houses[houses.size() - 1] - houses[0]);
	int min = 0;
	int max = itv + 1;

	while (min + 1 < max)
	{
		itv = (min + max) / 2;
		if (iptime(houses, c - 1, itv))
			min = itv;
		else
			max = itv;	
	}

	cout << min;
	return 0;
}

bool iptime(vector<int> & houses, int rest_iptime, int set_interval)
{
	int interval = 0;
	for (int house_index = 1; house_index < houses.size() && rest_iptime > 0; house_index++)
	{
		interval += houses[house_index] - houses[house_index - 1];
		if (interval >= set_interval)
		{
			rest_iptime--;
			interval = 0;
		}

		if (houses.size() - house_index - 1 < rest_iptime)
			return false;
	}
	return true;
}

void quickSort(vector<int> & arr, int left, int right) 
{
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];
	int temp;
	do
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
		quickSort(arr, left, j);

	if (i < right)
		quickSort(arr, i, right);
}