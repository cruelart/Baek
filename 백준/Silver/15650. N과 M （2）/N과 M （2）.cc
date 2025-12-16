#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<bool>& _isVisit, vector<int>& _save_num, int _N, int _M, int _depth, int _n)
{
	if (_depth == _M)
	{
		for (int i = 0; i < _save_num.size(); i++)
		{
			cout << _save_num[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int n = _n+1; n <= _N; n++)
	{
		_save_num[_depth] = n;

		dfs(_isVisit, _save_num, _N, _M, _depth + 1, n);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<bool> isVisit(N + 1, false);
	vector<int> save_num(M);

	dfs(isVisit, save_num, N, M, 0, 0);

	return 0;
}