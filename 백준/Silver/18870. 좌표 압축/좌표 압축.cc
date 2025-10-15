#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<tuple<long long, int, int>> arr(N);
	vector<long long> result(N);

	//풀이방법
	// -> pair를 사용함 ex pair<int,int> 써서 (2,0,0) (4.1, 0) (-10,2 ,0).... -> (-10,2,0) (2,0,1) (4,1,2)
	
	for (int n = 0; n < N; n++)
	{
		long long num;
		cin >> num;

		arr[n] = { num, n, 0 };
	}

	sort(arr.begin(), arr.end());

	int k = 0;
	for(int i = 0; i < N; i++)
	{ 
		if (i == 0)
		{
			get<2>(arr[i]) = k++;
		}
		else
		{
			if (get<0>(arr[i]) == get<0>(arr[i - 1])) // 값이 중복이라면
			{
				get<2>(arr[i]) = k - 1; // 더하기를 해주지않음
			}
			else
			{
				get<2>(arr[i]) = k++;
			}
		}
	}

	for (int j = 0; j < N; j++)
	{
		result[get<1>(arr[j])] = get<2>(arr[j]);
	}

	for (int k = 0; k < N; k++)
	{
		cout << result[k] << ' ';
	}

	return 0;
}