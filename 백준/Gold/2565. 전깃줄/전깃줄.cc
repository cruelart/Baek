#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
	int num; // 전깃줄의 개수
	cin >> num;

	unordered_map<int, int> map;
	vector<int> save_A;

	for (int n = 0; n < num; n++)
	{
		int A, B;
		cin >> A >> B;

		map[A] = B;
		save_A.push_back(A);
	}

	sort(save_A.begin(), save_A.end()); // A기준 오름차순 정렬해주고

	vector<int> save_B;

	for (int i = 0; i < save_A.size(); i++)
	{
		save_B.push_back(map[save_A[i]]);
	}

	//LIS 가장 긴 부분수열 찾으면 끝

	vector<int> dp_table(save_B.size(), 1);

	for (int i = 1; i < save_B.size(); i++) // 끝
	{
		for (int j = 0; j < i; j++) // 시작부분
		{
			if (save_B[i] > save_B[j])
			{
				dp_table[i] = max(dp_table[i], dp_table[j] + 1);
			}
		}
	}

	cout << num - *max_element(dp_table.begin(), dp_table.end());
	//cout << num - dp_table[save_B.size() - 1];

	return 0;
}

// 16 17 10 31 40 25 13 12 1