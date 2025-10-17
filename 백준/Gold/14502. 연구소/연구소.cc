#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dfs(vector<vector<pair<int, bool>>> _arr, vector<pair<int, int>> _virus_location)
{
	stack<pair<int, int>> dfs_stack; // x, y 인덱스 삽입
	for (int i = 0; i < _virus_location.size(); i++)
	{
		dfs_stack.push(_virus_location[i]);
	}

	int count = 0;

	while (!dfs_stack.empty())
	{
		pair<int, int> present_index = dfs_stack.top();
		dfs_stack.pop();

		int x = present_index.first;
		int y = present_index.second;

		if (_arr[x][y].second) // 이미 방문했던 적이 있다면
		{
			continue; // 넘어간다
		}

		_arr[x][y].second = true;

		 // 상좌우하 순으로 할건데 dfs 스택이므로 거꾸로
		
		if (_arr[x][y + 1].first == 0)
		{
			_arr[x][y + 1].first = 2;
			dfs_stack.push({ x, y + 1 });
		}

		if (_arr[x + 1][y].first == 0)
		{
			_arr[x + 1][y].first = 2;
			dfs_stack.push({ x + 1, y });
		}

		if (_arr[x - 1][y].first == 0)
		{
			_arr[x - 1][y].first = 2;
			dfs_stack.push({ x - 1, y });
		}

		if (_arr[x][y - 1].first == 0)
		{
			_arr[x][y - 1].first = 2;
			dfs_stack.push({ x, y - 1 });
		}
		
	}



	for (int i = 1; i < _arr[0].size(); i++)
	{
		for (int j = 1; j < _arr.size(); j++)
		{
			if (_arr[j][i].first == 0)
			{
				count++;
			}
		}
	}

	return count;
}

int main()
{
	int M, N; // x, y
	cin >> N >> M;

	vector<vector<pair<int,bool>>> arr(M + 2, vector<pair<int, bool>>(N + 2, {1,false})); // -> )바이러스위치, 검사확인 자료형)

	vector<pair<int, int>> virus_location; // 바이러스 위치 저장

	int max = 0;

	for (int n = 1; n < N + 1; n++)
	{
		for (int m = 1; m < M + 1; m++)
		{
			cin >> arr[m][n].first;
			if (arr[m][n].first == 2)
			{
				virus_location.push_back({ m,n });
			}
		}
	}


	// 1차원 배열로 변환
	for (int i = 0; i < (M + 1) * (N + 1); i++)
	{
		int x1 = i % (M + 1);
		int y1 = i / (M + 1);

		if (arr[x1][y1].first == 0)
		{
			arr[x1][y1].first = 1;
		}
		else
		{
			continue;
		}

		for (int j = i + 1; j < (M + 1) * (N + 1); j++)
		{
			int x2 = j % (M + 1);
			int y2 = j / (M + 1);

			if (arr[x2][y2].first == 0)
			{
				arr[x2][y2].first = 1;
			}
			else
			{
				continue;
			}

			for (int k = j + 1; k < (M + 1) * (N + 1); k++)
			{
				int x3 = k % (M + 1);
				int y3 = k / (M + 1);

				if (arr[x3][y3].first == 0)
				{
					arr[x3][y3].first = 1;

					int count = dfs(arr, virus_location);

					if (max < count)
					{
						max = count;
					}

					arr[x3][y3].first = 0;
				}
				else
				{
					continue;
				}
			}
			arr[x2][y2].first = 0;
		}
		arr[x1][y1].first = 0;
	}


	cout << max;


	return 0;
}