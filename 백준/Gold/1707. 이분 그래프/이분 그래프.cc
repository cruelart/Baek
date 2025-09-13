#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool BFS(vector<vector<int>>& _graph, vector<bool>& _isUnion1, vector<bool>& _isUnion2, int _start_index)
{
	queue<int> bfs_queue;
	bfs_queue.push(_start_index);
	int count = _start_index;

	while(!bfs_queue.empty())
	{
		int present_index = bfs_queue.front();
		bfs_queue.pop();

		_isUnion2[present_index] = true; // 일단 유니온 2에 넣음

		//집합에 넣는 과정
		for (int i = 0; i < _graph[present_index].size(); i++)
		{
			if (!_isUnion1[_graph[present_index][i]] && !_isUnion2[_graph[present_index][i]])
			{
				bfs_queue.push(_graph[present_index][i]);
			}
			if (_isUnion2[_graph[present_index][i]]) // 유니온2에 자식이 들어가 있다면 인접하므로 false전환하고 1로 옮김
			{
				_isUnion2[present_index] = false;
				_isUnion1[present_index] = true;
			}
		}

		if (!_isUnion2[present_index]) // 유니온 1에도 자식이 있는지 확인
		{
			for (int i = 0; i < _graph[present_index].size(); i++)
			{
				if (_isUnion1[_graph[present_index][i]]) // 옮긴 유니온 1에도 자식이 들어가있다면
				{
					_isUnion1[present_index] = false;
					return false;
				}

			}
		}

		if (bfs_queue.empty())
		{
			for (int g = count; g < _graph.size(); g++)
			{
				if (!_isUnion1[g] && !_isUnion2[g]) // 방문한적이 없는 정점이 있다면
				{
					bfs_queue.push(g);
					count = g;
					break;
				}
			}
		}
		
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int K; // 테스트 횟수
	cin >> K;

	vector<bool> result;
	//K번 반복
	for (int k = 0; k < K; k++)
	{
		int V, E; // 정점의 갯수, 간선의 갯수
		cin >> V >> E;

		vector<bool> isUnion1(V + 1, false); // 1번 집합(한개만 연결돼있다면)
		vector<bool> isUnion2(V + 1, false); // 2번 집합(두개이상 연결돼있다면)

		vector<vector<int>> graph(V + 1); // 그래프

		int start_num = 1; // 시작 정점

		for (int e = 0; e < E; e++)
		{
			int start, end;
			cin >> start >> end;

			graph[start].push_back(end);
			graph[end].push_back(start);
		}

		if (BFS(graph, isUnion1, isUnion2, start_num))
		{
			result.push_back(true);
		}
		else
		{
			result.push_back(false);
		}
	}

	for (int r = 0; r < result.size(); r++)
	{
		if (result[r])
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}


	return 0;
}