#include <iostream>
#include <vector>

using namespace std;

int max_count = 0;

void dfs(vector<vector<char>>& _board, vector<vector<bool>>& _isVisit, vector<bool>& _isHaveAlpabet, pair<int,int> _start_index, int _depth)
{
	if (_board.empty())
	{
		return;
	}

	max_count = max(max_count, _depth);

	int r_size = _board.size();
	int c_size = _board[0].size();

	int r = _start_index.first;
	int c = _start_index.second;


	int y[4] = { -1, 1, 0, 0 };
	int x[4] = { 0, 0, -1, 1 };

	for (int i = 0; i < 4; i++)
	{
		if (r + y[i] >= 1 && r + y[i] < r_size)
		{
			if (c + x[i] >= 1 && c + x[i] < c_size)
			{
				int next_visitAlpabet = _board[r + y[i]][c + x[i]];

				if (!_isVisit[r + y[i]][c + x[i]] && !_isHaveAlpabet[next_visitAlpabet - 'A'])
				{
					_isHaveAlpabet[next_visitAlpabet - 'A'] = true;
					_isVisit[r + y[i]][c + x[i]] = true;

					dfs(_board, _isVisit, _isHaveAlpabet, { r + y[i],c + x[i] }, _depth + 1);

					_isHaveAlpabet[next_visitAlpabet - 'A'] = false;
					_isVisit[r + y[i]][c + x[i]] = false;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int R, C;
	cin >> R >> C;

	vector<vector<char>> board(R + 1, vector<char>(C + 1, '0'));
	vector<vector<bool>> isVisit(R + 1, vector<bool>(C + 1,false));
	vector<bool> isHaveAlpabet(26, false);

	for (int r = 1; r <= R; r++)
	{
		for (int c = 1; c <= C; c++)
		{
			cin >> board[r][c];
		}
	}

	isHaveAlpabet[board[1][1] - 'A'] = true;
	isVisit[1][1] = true;

	dfs(board, isVisit, isHaveAlpabet, {1,1}, 1);

	cout << max_count;

	return 0;
}