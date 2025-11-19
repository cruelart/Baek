#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; // 정점의 개수
	cin >> N;

	vector<vector<int>> dp_table(N + 1, vector<int>(N + 1)); // 0번째 반복했을 때의 테이블
	int INF = 10000;

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> dp_table[y][x];
			if (dp_table[y][x] == 0)
			{
				dp_table[y][x] = 10000;
			}
		}
	}
	
	for (int i = 1; i <= N; i++) // 모든 정점을 돌 것
	{
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				dp_table[y][x] = min(dp_table[y][x], dp_table[y][i] + dp_table[i][x]); // 굳이 거쳐지나가지 않아도 되는 경우 판단해야되므로 min 삽입
			}
		}
	}

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			if (dp_table[y][x] != 10000)
			{
				cout << '1' << ' ';
			}
			else
			{
				cout << '0' << ' ';
			}
		}

		cout << '\n';
	}

	return 0;
}