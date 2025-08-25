#include <iostream>
#include <stack> // dfs사용
#include <queue> // bfs사용
#include <algorithm> //사실 이건 굳이 필요하지 않다 -> 조건이 주어지지 않았어 but i will use 오름차순
#include <vector>

#define USEDFS
//#define USEBFS;

using namespace std;

int DFS(vector<vector<int>>& _graph, vector<bool>& _isVisit, int _start_index)
{
	int count = 0; // 총 바이러스에 걸린 컴퓨터 갯수
	stack<int> dfs_stack;
	dfs_stack.push(_start_index);

	while (!dfs_stack.empty())
	{
		int present_index = dfs_stack.top(); // 현재 진행중인 값을 가져옴
		dfs_stack.pop();
		if (!_isVisit[present_index])
		{
			_isVisit[present_index] = true; // 해당 정점을 방문했다
			count++;
		}

		for (int i = 0; i < _graph[present_index].size(); i++)
		{
			if (!_isVisit[_graph[present_index][i]]) // 방문하지않은 정점일 경우에만
			{
				dfs_stack.push(_graph[present_index][i]);
			}
		}
	}

	return count;
}

int main()
{
	int cpt_num; // 컴퓨터의 수
	int rope_num; // 연결된 컴퓨터의 수(간선)
	int start_num = 1; // 시작 컴퓨터번호

	cin >> cpt_num;
	cin >> rope_num;

	vector<vector<int>> graph(cpt_num + 1); // why? 0번째 인덱스는 안쓸거기때문에 1개 추가해줌 -> 기독성위해
	vector<bool> isVisit(cpt_num + 1 , false); // 이미 감연된 컴퓨터인지 따지는 배열

	//그래프 작성
	for (int i = 0; i < rope_num; i++)
	{
		int start_index, end_index;
		cin >> start_index >> end_index;

		graph[start_index].push_back(end_index);
		graph[end_index].push_back(start_index);
	}

	for (int i = 1; i < cpt_num + 1; i++)
	{
#ifdef USEDFS
		sort(graph[i].begin(), graph[i].end()); // 오름차순
#endif

#ifdef USEBFS
		sort(graph[i].begin(), graph[i].end(), greater<int>());
#endif
	}

	cout << DFS(graph, isVisit, start_num) - 1;

	return 0;
}