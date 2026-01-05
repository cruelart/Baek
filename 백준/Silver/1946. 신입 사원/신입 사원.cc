#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void select_employee()
{
	int N;
	cin >> N;
	vector<pair<int, int>> apply_person(N); // 서류 순위, 면접 순위

	for (int n = 0; n < N; n++)
	{
		cin >> apply_person[n].first >> apply_person[n].second;
	}

	int count_num = 1; // 1등은 그냥 포함

	sort(apply_person.begin(), apply_person.end());

	int pass_Test2Rank = apply_person[0].second; // 서류 1등의 면접 순위

	for (int n = 1; n < N; n++)
	{
		int test2Rank = apply_person[n].second;

		if (pass_Test2Rank > test2Rank)
		{
			pass_Test2Rank = test2Rank;
			count_num++;
		}
	}

	cout << count_num << '\n';
	

}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		select_employee();
	}

	return 0;
}