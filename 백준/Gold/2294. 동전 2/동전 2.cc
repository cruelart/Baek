

/*
* 문제
n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.

입력
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.

출력
첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.

예제 입력 1 
3 15
1
5
12

예제 출력 1 
3
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> coin(n);
	vector<int> dp_table(k + 1,10001); // dp_table[k] -> k의 무게를 만드는데 최소 동전 갯수

	for (int index = 0; index < n; index++)
	{
		cin >> coin[index]; // 코인의 종류 입력
		if (coin[index] <= k)
		{
			dp_table[coin[index]] = 1; // 해당 무게를 만들기 위해선 단 1개의 코인만 필요하므로
		}
	}
	sort(coin.begin(), coin.end());

	for (auto p : coin)
	{
		for (int w = p; w <= k; w++)
		{
			if (dp_table[w - p] != 10001)
			{
				dp_table[w] = min(dp_table[w], dp_table[w - p] + 1);
			}
		}
	}
	if (dp_table[k] != 10001)
	{
		cout << dp_table[k];
		return 0;
	}
	cout << -1;

	return 0;
}