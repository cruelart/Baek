#include <iostream>
#include <vector>

using namespace std;

int count_num = 0;

void outQueenAfterFillMap(vector<vector<int>>& _chess_map, pair<int, int> _queenPos)
{
	int size = _chess_map.size();
	int r = _queenPos.first;
	int c = _queenPos.second;

	int compare_size_c = max(size - 1 - c, c); // 비교 횟수
	int compare_size_r = max(size - 1 - r, r); // 비교 횟수

	int compare_size = max(compare_size_c, compare_size_r);

	_chess_map[r][c]--;

	for (int i = 1; i <= compare_size; i++)
	{
		if (c - i >= 0) // 왼쪽으로 채우기
		{
			if (r + i < size) // 위 대각성 채우기
			{
				_chess_map[r + i][c - i]--;
			}

			if (r - i >= 0)
			{
				_chess_map[r - i][c - i]--;
			}

			_chess_map[r][c - i]--;
		}

		if (c + i < size)
		{
			if (r + i < size)
			{
				_chess_map[r + i][c + i]--;
			}

			if (r - i >= 0)
			{
				_chess_map[r - i][c + i]--;
			}

			_chess_map[r][c + i]--;
		}

		if (r + i < size)
		{
			_chess_map[r + i][c]--;
		}

		if (r - i >= 0)
		{
			_chess_map[r - i][c]--;
		}
	}
}

void inQueenAfterFillMap(vector<vector<int>>& _chess_map, pair<int,int> _queenPos)
{
	int size = _chess_map.size();
	int r = _queenPos.first;
	int c = _queenPos.second;

	_chess_map[r][c]++; // 배치된 퀸 자리 채우기


	int compare_size_c = max(size - 1 - c, c); // 비교 횟수
	int compare_size_r = max(size - 1 - r, r); // 비교 횟수

	int compare_size = max(compare_size_c, compare_size_r);

	for (int i = 1; i <= compare_size; i++)
	{
		if (c - i >= 0) // 왼쪽으로 채우기
		{
			if (r + i < size) // 위 대각성 채우기
			{
				_chess_map[r + i][c - i]++;
			}
			
			if (r - i >= 0)
			{
				_chess_map[r - i][c - i]++;
			}

			//왼쪽 직선으로 다 채우기
			_chess_map[r][c - i]++;
		}

		if (c + i < size)
		{
			//오른쪽 아래 대각선 채우기
			if (r + i < size)
			{
				_chess_map[r + i][c + i]++;
			}

			//오른쪽 위 대각선 채우기
			if (r - i >= 0)
			{
				_chess_map[r - i][c + i]++;
			}

			//오른쪽 직선 채우기
			_chess_map[r][c + i]++;
		}

		//어래 직선 채우기
		if (r + i < size)
		{
			_chess_map[r + i][c]++;
		}

		//위 직선 채우기
		if (r - i >= 0)
		{
			_chess_map[r - i][c]++;
		}
	}
}

void dfs(vector<vector<int>>& _chess_map, int _row) // _row가 곧 depth 역할
{
	int map_size = _chess_map.size();

	// 목표한 행 끝까지 도달했다면 성공
	if (_row == map_size)
	{
		count_num++;
		return;
	}

	// 현재 행(_row)에서 어느 열(c)에 놓을지만 결정
	for (int c = 0; c < map_size; c++)
	{
		if (_chess_map[_row][c] == 0) // 현재 행의 c열이 안전한가?
		{
			inQueenAfterFillMap(_chess_map, { _row, c });
			dfs(_chess_map, _row + 1); // 다음 행으로 이동
			outQueenAfterFillMap(_chess_map, { _row, c });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>> chess_map(N, vector<int>(N, 0));

	dfs(chess_map, 0);

	cout << count_num;

	return 0;
}