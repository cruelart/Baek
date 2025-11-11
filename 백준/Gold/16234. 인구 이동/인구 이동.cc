#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& _country_personNum, vector<vector<bool>>& _isVisit_country, pair<int,int> start_index, int _L, int _R)
{
	queue<pair<int,int>> bfs_queue; // y x 순서대로
	int N = _country_personNum.size();
	_isVisit_country[start_index.first][start_index.second] = true;
	vector < pair<int, int>> save_country;
	int total_saveCountry_num = 0; // 저장된 총 인구수

	bfs_queue.push({ start_index.first,start_index.second });

	while (!bfs_queue.empty())
	{
		pair<int,int> present_index = bfs_queue.front(); 
		save_country.push_back({ present_index.first, present_index.second });
		total_saveCountry_num += _country_personNum[present_index.first][present_index.second]; // 현재 나라 인구수를 더함

		bfs_queue.pop();

		int x[4] = { -1,1,0,0 };
		int y[4] = { 0,0,-1,1 };

		for (int i = 0; i < 4; i++)
		{
			int present_personNum = _country_personNum[present_index.first][present_index.second]; // 현재 나라의 인구수

			int next_index_x = present_index.second + x[i];
			int next_index_y = present_index.first + y[i];

			if (_country_personNum[next_index_y][next_index_x] != -1) // 임시로 늘려놓은 공간이 아니면서
			{
				if (!_isVisit_country[next_index_y][next_index_x]) // 해당 나라를 아직 방문하지 않은 상태이고
				{
					if (abs(present_personNum - _country_personNum[next_index_y][next_index_x]) >= _L 
						&& abs(present_personNum - _country_personNum[next_index_y][next_index_x]) <= _R) // 문제에서 주어진 조건이 맞다면
					{
						bfs_queue.push({ next_index_y , next_index_x });
						_isVisit_country[next_index_y][next_index_x] = true;
					}
				}
			}
		}
	}

	int average_num = total_saveCountry_num / save_country.size();

	for (int index = 0; index < save_country.size(); index++)
	{
		_country_personNum[save_country[index].first][save_country[index].second] = average_num;
	}

	return save_country.size();
}

int main()
{
	int N;
	cin >> N; // 땅의 크기 결정

	vector<vector<int>> country_personNum(N + 2, vector<int>(N + 2, -1)); // N x N 크기 인데 좌우로 하나씩 늘려줌
	vector<vector<bool>> isVisit_country(N + 2, vector<bool>(N + 2, false)); // N x N 크기 인데 좌우로 하나씩 늘려줌

	int L, R;
	cin >> L >> R; // L명 이상 , R명 이하 차이나는지 확인

	//나라별 인구수 채우기
	for (int y = 1; y < N+1; y++)
	{
		for (int x = 1; x < N + 1; x++)
		{
			cin >> country_personNum[y][x];
		}
	}

	int count = 0;
	//BFS돌리기
	bool isBfsRun = false; // 실제로 BFS가 한번이상 작동했는지 판단
	while (true)
	{
		for (int y = 1; y < N + 1; y++)
		{
			for (int x = 1; x < N + 1; x++)
			{
				if (!isVisit_country[y][x])
				{
					if (bfs(country_personNum, isVisit_country, { y,x }, L, R) != 1) // 한번이라도 bfs가 정상작동했다면
					{
						isBfsRun = true;
					}
				}
			}

		}
		if (!isBfsRun) // 하지만 끝날때까지 정상작동하지 않았다면 
		{
			break; // 반복문 종료
		}

		for (int y = 1; y < N + 1; y++)
		{
			fill(isVisit_country[y].begin(), isVisit_country[y].end(), false); // 다시 초기화
		}
		isBfsRun = false;
		count++;
	}
	
	cout << count;

	return 0;
}