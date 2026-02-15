#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& _graph, vector<vector<int>>& _possible_num, vector<vector<bool>>& _isVisit, pair<int,int> _wantPoint, pair<int,int> _startPoint)
{
	int x_size = _graph[0].size();
	int y_size = _graph.size();

	int start_x = _startPoint.second;
	int start_y = _startPoint.first;

	int possible_num = 0;

	//왼, 아, 오
	int x[4] = { -1, 0, 1, 0 };
	int y[4] = { 0, 1, 0, -1 };

	for (int i = 0; i < 4; i++)
	{
		//범위 안에 들어오고
		if (start_x + x[i] >= 0 && start_x + x[i] < x_size)
		{
			if (start_y + y[i] >= 0 && start_y + y[i] < y_size)
			{
				if (_graph[start_y][start_x] > _graph[start_y + y[i]][start_x + x[i]])
				{
					if (!_isVisit[start_y + y[i]][start_x + x[i]]) // 방문한 적이 없다면
					{
						_isVisit[start_y + y[i]][start_x + x[i]] = true; // 방문처리
						possible_num += dfs(_graph, _possible_num, _isVisit, _wantPoint, { start_y + y[i], start_x + x[i] });
					}
					else // 방문을 했엇다면
					{
						possible_num += _possible_num[start_y + y[i]][start_x + x[i]];
					}
				}
			}
		}
	}

	if (_startPoint == _wantPoint)
	{
		_possible_num[start_y][start_x] = 1;
		return 1;
	}

	_possible_num[start_y][start_x] = possible_num;
	return possible_num;
}

int main()
{
	int M, N;
	cin >> M >> N;

	vector<vector<int>> graph(M, vector<int>(N));
	vector<vector<int>> possible_num(M, vector<int>(N, 0)); // 이동 가능 횟수
	vector<vector<bool>> isVisit(M, vector<bool>(N, false));

	for (int m = 0; m < M; m++)
	{
		for (int n = 0; n < N; n++)
		{
			cin >> graph[m][n];
		}
	}

	dfs(graph, possible_num, isVisit, { M - 1,N - 1 }, { 0,0 });
	cout << possible_num[0][0];

	return 0;
}