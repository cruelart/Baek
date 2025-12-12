#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

double cal_dist(pair<int, int> _dot1, pair<int, int> _dot2)
{
	double pow_dist = (_dot1.first - _dot2.first) * (_dot1.first - _dot2.first) + (_dot1.second - _dot2.second) * (_dot1.second - _dot2.second);
	return sqrt(pow_dist);
}

pair<int, int> vec(pair<int,int> _dot1, pair<int,int> _dot2)
{
	return { _dot1.first - _dot2.first , _dot1.second - _dot2.second };
}

bool is_collinear(const pair<long long, long long>& A,
	const pair<long long, long long>& B,
	const pair<long long, long long>& C)
{
	// cross = (B-A) x (C-A)
	long long x1 = B.first - A.first;
	long long y1 = B.second - A.second;
	long long x2 = C.first - A.first;
	long long y2 = C.second - A.second;

	long long cross = x1 * y2 - y1 * x2;
	return cross == 0;
}

int main()
{
	pair<int, int> a;
	pair<int, int> b;
	pair<int, int> c;

	cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;

	//예외처리
	if (is_collinear(a, b, c))
	{
		cout << -1;
		return 0;
	}

	double ab_dist = cal_dist(a, b);
	double bc_dist = cal_dist(b,c);
	double ca_dist = cal_dist(c,a);

	vector<double> dist = { ab_dist,bc_dist,ca_dist };

	double min_dist = *min_element(dist.begin(), dist.end());
	double max_dist = *max_element(dist.begin(), dist.end());

	double result_minDist = 0;
	double result_maxDist = 0;
	for (auto p : dist)
	{
		result_maxDist += p;
		result_minDist += p;
	}

	result_maxDist -= min_dist;
	result_minDist -= max_dist;

	cout.precision(10);
	cout << 2 * (result_maxDist - result_minDist);

	return 0;
}