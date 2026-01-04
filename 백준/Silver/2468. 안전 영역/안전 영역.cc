#include <iostream>
#include <vector>

using namespace std;

void vectorClear(vector<vector<bool>>& _isVisit)
{
	int size = _isVisit.size();

	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			_isVisit[r][c] = false;
		}
	}
}

void dfs(vector<vector<int>>& _graph, vector<vector<bool>>& _isVisit, pair<int,int> _start_index, int _height)
{
	if (_graph.empty())
	{
		return;
	}

	int r = _start_index.first;
	int c = _start_index.second;
	int graph_size = _graph.size();

	int y[4] = { -1, 1 ,0, 0 };
	int x[4] = { 0, 0 ,-1, 1 };

	for (int i = 0; i < 4; i++) // 간선의 수만큼 반복
	{
		if (r + y[i] >= 0 && r + y[i] < graph_size)
		{
			if (c + x[i] >= 0 && c + x[i] < graph_size)
			{
				if (!_isVisit[r + y[i]][c + x[i]] && _graph[r + y[i]][c + x[i]] > _height)
				{
					_isVisit[r + y[i]][c + x[i]] = true;
					dfs(_graph, _isVisit, {r + y[i], c + x[i]}, _height);
				}
			}
		}
	}

}

int main()
{
	int N;
	cin >> N;

	int max_count = 0;

	vector<vector<int>> graph(N, vector<int>(N));
	vector<vector<bool>> isVisit(N, vector<bool>(N, false));

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> graph[r][c];
		}
	}

	for (int h = 0; h <= 100; h++)
	{
		int count_num = 0;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				if (!isVisit[r][c] && graph[r][c] > h)
				{
					isVisit[r][c] = true;
					count_num++;
					dfs(graph, isVisit, {r,c}, h);
				}
			}
		}
		vectorClear(isVisit);
		max_count = max(max_count, count_num);
	}
	
	cout << max_count;

	return 0;
}