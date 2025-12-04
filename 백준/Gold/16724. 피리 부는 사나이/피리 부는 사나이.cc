#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<char>>& _graph, vector<vector<pair<bool, int>>>& _checkVisit, pair<int,int> _start_index, int& _count, int& _cycle_num)
{
	stack<pair<int,int>> dfs_stack;
	dfs_stack.push(_start_index);
	_checkVisit[_start_index.first][_start_index.second].first = true; // 시작점임을 알리고
	_checkVisit[_start_index.first][_start_index.second].second = _cycle_num; // 시작점임을 알리고

	while (!dfs_stack.empty())
	{
		pair<int,int> present_index = dfs_stack.top();
		int y = present_index.first;
		int x = present_index.second;
		dfs_stack.pop();

		if (_graph[y][x] == 'D')
		{
			if (y + 1 < _graph.size())
			{
				if (!_checkVisit[y + 1][x].first) // 한번도 방문한 적이 없는 정점이라면
				{
					dfs_stack.push({ y + 1,x });
					_checkVisit[y + 1][x].first = true;
					_checkVisit[y + 1][x].second = _cycle_num;
				}
				else if(_checkVisit[y + 1][x].first && _checkVisit[y + 1][x].second == _cycle_num)
				{
					_count++;
					_cycle_num++;
					return;
				}
				else if(_checkVisit[y + 1][x].first && _checkVisit[y + 1][x].second != _cycle_num)// 사이클이 존재하는 정점에 진입했으므로 건너뛰면 됨
				{
					_cycle_num++;
					return; // 이미 계산을 마쳤음
				}
				else
				{ }
			}
		}
		else if (_graph[y][x] == 'U')
		{
			if (y - 1 >= 0)
			{
				if (!_checkVisit[y - 1][x].first)
				{
					dfs_stack.push({ y - 1,x });
					_checkVisit[y - 1][x].first = true;
					_checkVisit[y - 1][x].second = _cycle_num;
				}
				else if (_checkVisit[y - 1][x].first && _checkVisit[y - 1][x].second == _cycle_num)
				{
					_count++;
					_cycle_num++;
					return;
				}
				else if (_checkVisit[y - 1][x].first && _checkVisit[y - 1][x].second != _cycle_num)// 사이클이 존재하는 정점에 진입했으므로 건너뛰면 됨
				{
					_cycle_num++;
					return; // 이미 계산을 마쳤음
				}
				else
				{
				}
			}
		}
		else if (_graph[y][x] == 'R')
		{
			if (x + 1 < _graph[y].size())
			{
				if (!_checkVisit[y][x + 1].first)
				{
					dfs_stack.push({ y,x + 1 });
					_checkVisit[y][x + 1].first = true;
					_checkVisit[y][x + 1].second = _cycle_num;
				}
				else if (_checkVisit[y][x + 1].first && _checkVisit[y][x + 1].second == _cycle_num)
				{
					_count++;
					_cycle_num++;
					return;
				}
				else if (_checkVisit[y][x + 1].first && _checkVisit[y][x + 1].second != _cycle_num)// 사이클이 존재하는 정점에 진입했으므로 건너뛰면 됨
				{
					_cycle_num++;
					return; // 이미 계산을 마쳤음
				}
				else
				{
				}
			}
		}
		else if (_graph[y][x] == 'L')
		{
			if (x - 1 >= 0)
			{
				if (!_checkVisit[y][x - 1].first)
				{
					dfs_stack.push({ y,x - 1 });
					_checkVisit[y][x - 1].first = true;
					_checkVisit[y][x - 1].second = _cycle_num;
				}
				else if (_checkVisit[y][x - 1].first && _checkVisit[y][x - 1].second == _cycle_num)
				{
					_count++;
					_cycle_num++;
					return;
				}
				else if (_checkVisit[y][x - 1].first && _checkVisit[y][x - 1].second != _cycle_num)// 사이클이 존재하는 정점에 진입했으므로 건너뛰면 됨
				{
					_cycle_num++;
					return; // 이미 계산을 마쳤음
				}
				else
				{
				}
			}
		}
		else
		{

		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<char>> graph(N, vector<char>(M));
	vector<vector<pair<bool,int>>> isVisit(N, vector<pair<bool, int>>(M, {false,0}));

	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			cin >> graph[n][m];
		}
	}

	int count = 0;
	int cycle_num = 1;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (!isVisit[y][x].first)
			{
				dfs(graph, isVisit, { y,x } , count, cycle_num);
			}
		}
	}

	cout << count;

}