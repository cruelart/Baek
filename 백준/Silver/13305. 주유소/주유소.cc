#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	if (N < 1)
	{
		return 0;
	}

	vector<int> dist(N - 1); // K번 도시에서 k+1번쨰 도시로 가는 거리
	vector<int> cost(N);

	for (int n = 0; n < dist.size(); n++)
	{
		cin >> dist[n];
	}

	for (int n = 0; n < cost.size(); n++)
	{
		cin >> cost[n];
	}

	int total_cost = cost[0] * dist[0];
	int present_cost = cost[0];
	//sort(cost.begin(), cost.end() - 1);
	//int min_cost = *min_element(cost.begin(), cost.end() - 1);

	for (int n = 1; n < dist.size(); n++)
	{
		if (present_cost > cost[n])
		{
			present_cost = cost[n];
		}
		
		total_cost += present_cost * dist[n];
	}
	cout << total_cost;

	return 0;
}