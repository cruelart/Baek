#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>>& _graph, vector<int>& _isVisitNum, vector<bool>& _isVisit, int start_index)
{
	int count = 1; // 방문순서

	stack<int> dfs_stack;
	dfs_stack.push(start_index); // 처음 시작 인덱스 푸쉬

	while (!dfs_stack.empty()) // 스택이 빌 때까지 계속 반복
	{
		int present_index = dfs_stack.top();
		dfs_stack.pop();

		if (!_isVisit[present_index]) // 해당 인덱스가 방문된 적이 없다면
		{
			_isVisit[present_index] = true;

			for (int i = 0; i < _graph[present_index].size(); i++)
			{
				if (!_isVisit[_graph[present_index][i]])
				{
					dfs_stack.push(_graph[present_index][i]);
				}
			}

			_isVisitNum[present_index] = count++;

		}

		else
		{
			continue;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, R; // 정점의 수, 간선의 수, 시작정점
	cin >> N >> M >> R;

	vector<vector<int>> graph(N+1); // 인접리스트 N+1개 미리생성(인덱스0은 안쓸예정이므로)
	vector<int> isVisitNum(N+1, 0); // 방문순서배열
	vector<bool> isVisit(N+1, false); // 방문확인배열

	//그래프 채우기
	for (int i = 0; i < M; i++)
	{
		int start_index, end_index;
		cin >> start_index >> end_index;

		graph[start_index].push_back(end_index);
		graph[end_index].push_back(start_index);
	}

	//내림차순으로 정리 -> DFS 스택에서 오름차순으로 집어넣기위함
	for (int i = 1; i < N + 1; i++)
	{
		sort(graph[i].begin(), graph[i].end(), greater<int>());
	}

	//깊이 우선 탐색 시작
	DFS(graph, isVisitNum, isVisit, R);

	for (int i = 1; i < isVisitNum.size(); i++)
	{
		cout << isVisitNum[i] << '\n';
	}

	return 0;

}