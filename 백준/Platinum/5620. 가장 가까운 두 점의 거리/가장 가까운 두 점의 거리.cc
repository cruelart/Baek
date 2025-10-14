#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getLength(pair<int,int> first, pair<int,int> second) // 두 점사이의 거리 (제곱근 제외)
{
	return pow(first.first - second.first, 2) + pow(first.second - second.second, 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end()); // x기준으로 정렬

	int pivotDistance = getLength(arr[0], arr[1]); // 기준 거리

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (pow(arr[j].first - arr[i].first, 2) > pivotDistance) // 만약 기준 거리보다 x좌표의 거리가 더 멀다면
			{
				break; // 생략
			}
			if (getLength(arr[j], arr[i]) < pivotDistance) // 기준 거리보다 거리가 더 작으면 교체
			{
				pivotDistance = getLength(arr[j], arr[i]);
			}
		}
	}

	cout << pivotDistance;

	return 0;
}