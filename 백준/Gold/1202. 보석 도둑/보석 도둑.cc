#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int N, K; // 보석 갯수, 가방 갯수
	cin >> N >> K;

	vector<pair<int, int>> jewel;

	for (int n = 0; n < N; n++)
	{
		int jewel_weight, jewel_price;
		cin >> jewel_weight >> jewel_price;

		jewel.push_back({ jewel_weight, jewel_price });
	}

	sort(jewel.begin(), jewel.end(), 
		[](const pair<int,int>& a, const pair<int,int>& b)
		{
			if (a.first < b.first) // 무게는 가벼운순서
			{
				return true;
			}

			if (a.first == b.first) // 가격은 비싼순서대로
			{
				return a.second > b.second;
			}
			return false;
		});

	vector<int> back; // 가벼운 순서대로

	for (int k = 0; k < K; k++)
	{
		int back_weight;
		cin >> back_weight;

		back.push_back(back_weight);
	}

	sort(back.begin(), back.end());
	
	long long result = 0;

	priority_queue<int, vector<int>> jewel_price;
	int jewel_index = 0;

	for (int k = 0; k < K; k++)
	{
		while (jewel_index < N)
		{
			//해당 가방에 넣을 수 있는 보석 비싼순서대로 넣기
			if (back[k] >= jewel[jewel_index].first)
			{
				jewel_price.push(jewel[jewel_index].second);
				jewel_index++;
				continue;
			}
			break;
			//해당 가방에 들어갈 수 있는 모든 보석을 담았으니

		}

		if (!jewel_price.empty())
		{
			result += jewel_price.top();
			jewel_price.pop();
		}
	}

	cout << result;

	return 0;
}